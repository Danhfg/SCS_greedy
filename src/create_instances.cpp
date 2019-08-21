/**
 * @file	create_instances.cpp
 * @brief	Contem o programa que cria as instancias para caso de uso
 */

#include <random>
#include <iostream>
#include <string>
#include <string> 

int main(int argc, char *argv[])
{
    int len = 50;
    int block = 100;

	/// Verificacao de argumentos
	if (argc > 1)
        len = std::stoi(argv[1]);
    
	if (argc > 2)
        block = std::stoi(argv[2]);
    
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist50(4,len); 
    std::uniform_int_distribution<std::mt19937::result_type> dist502(4,len*len); 
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0,3);
    std::uniform_int_distribution<std::mt19937::result_type> dist3(0,2);
    
	/// Vetor que contem o alfabeto
	std::vector<std::string> alphab = {"A","C","T","G"};

    std::string str = "";
    int j = 1;
    while (j < len*len){
        str += alphab[dist4(rng)];
        ++j;
    }

    auto rand_number( dist502(rng));
    //int i = 0;
    std::vector<std::string> reads;
    while (int(reads.size()) < block){
        if (int(rand_number) > len*len - len)
            len -= 50;
        std::string aux = str.substr(rand_number,len);
        if (int(rand_number)+50 > len*len - len)
            rand_number -= dist4(rng);
        else
            rand_number += dist4(rng);


        if (!reads.empty())
        {
            auto find (false);
            for (auto const& read: reads) {
                auto pos (read.find(aux));
                if (pos != std::string::npos)
                    find = true;
                pos = aux.find(read);
                if (pos != std::string::npos)
                    find = true;
            }
            if (!find)
            {
                reads.push_back(aux);
            }
        }
        else
            reads.push_back(aux);


    }
    /*
    while (int(reads.size()) < block){
        rand_number = len;
        std::string aux = "";
        for (auto j(0u);j < rand_number; ++j){
            aux += alphab[dist4(rng)];
        }
        //std::cout << aux << std::endl;
        if (!reads.empty())
        {
            auto find (false);
            for (auto const& read: reads) {
                auto pos (read.find(aux));
                if (pos != std::string::npos)
                    find = true;
                pos = aux.find(read);
                if (pos != std::string::npos)
                    find = true;
            }
            if (!find)
            {
                    reads.push_back(aux);
            }
        }
        else
            reads.push_back(aux);
        i++;
        rand_number = dist50(rng);
    }*/

    for (auto const& i: reads) {
        std::cout << i << "\n";
    }
    
}
