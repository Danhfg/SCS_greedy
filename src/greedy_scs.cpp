/**
 * @file	greedy_scs.cpp
 * @brief	Contem o a implementacao do algoritmo guloso GREEDY
 */

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <sstream>
#include <fstream>
#include <string>

//https://stackoverflow.com/questions/1878001/how-do-i-check-if-a-c-stdstring-starts-with-a-certain-string-and-convert-a
/**
 * @brief	Checa se uma string comeca com certa string e em seguida converta a substring em um numero
 */
static bool starts_with(const std::string str, const std::string prefix){
    return ((prefix.size() <= str.size()) && std::equal(prefix.begin(), prefix.end(), str.begin()));
}

int overlap(std::string a, std::string b, int min_length=5){
    /* Retorna o tamanho do maior sufixo ou prefixo que contenha pelo menos min_length.
        Se não existir sobreposição, returna 0. */
    int start = 0; 
    while (1){
        start = a.find(b.substr(0,min_length), start);
        if (start == -1)
            return 0;
        if (starts_with(b,a.substr(start,a.size()-1) ) )
            return (a.size())-start;
        start += 1;
    }
}

std::vector<std::pair<int,int>> arrangement(std::vector<std::string> reads){
    std::vector<std::pair<int,int>> arrang;
    for (auto i (0u); i < reads.size(); ++i){
        for (auto j (0u); j < reads.size(); ++j){
            if(i!=j){
                arrang.push_back( std::make_pair(i,j) );
            }
        }
    }
    return arrang;
}

std::tuple <int,int,int> pick_maximal_overlap(std::vector<std::string> reads, int k){
    /* Retorna uma tupla a posição dos pares da lista que contém suffix/prefix maximal
        com sobreposição >= k, além da sobreposição*/
    int read_a = 0;
    int read_b = 0;
    int best_over = 0;
    auto arrang (arrangement(reads));
    for (auto & r: arrang ){
        std::string a = reads[r.first];
        std::string b = reads[r.second];
        int over = overlap(a, b, k);
        if (over > best_over){
            read_a = r.first;
            read_b = r.second;
            best_over = over;
            }
        }
    return std::make_tuple (read_a, read_b, best_over);
}

std::string greedy_scs(std::vector<std::string>reads, int k){
    auto maximal (pick_maximal_overlap(reads,k));
    int read_a = std::get<0>(maximal);
    int read_b = std::get<1>(maximal);
    int over = std::get<2>(maximal);
    while (over > 0){
        std::string aux = reads[read_a]+reads[read_b].substr(over);
        reads[read_b] = aux;
        reads.erase(reads.begin()+read_a);

        auto maximal (pick_maximal_overlap(reads,k));
        read_a = std::get<0>(maximal);
        read_b = std::get<1>(maximal);
        over = std::get<2>(maximal);
    }
    std::string scs = "";
    for (auto const& i: reads) {
		scs += i;
	}
    return scs;
}

int main(int argc, char *argv[]){
    
	std::fstream f(argv[1]);
    std::string line;    
    std::vector<std::string> vet;
    
	if (f.is_open())
    {
        while (!f.eof() )
        {
            getline (f,line);
            vet.push_back(line);
        }
        f.close();
        if (vet.empty())
        {
            std::cerr << "To run: ./exe_greedy <file>" << std::endl;
        }
        else{
            auto scs (greedy_scs(vet, 1));
            std::cout << "The shortest common superstring is: " << scs << std::endl;
            std::cout << "The size of the shortest common superstring is: " << scs.size() << std::endl;

            auto max(0u);
            for (auto const& i: vet) {
                if (max < i.size())
                    max = i.size();
            }
            std::cout << "The length of the longest string found in the file is: " << max << std::endl;
        }
    }
    else
    {
        std::cerr << "To run: ./exe_greedy <file>" << std::endl;
    }
}
