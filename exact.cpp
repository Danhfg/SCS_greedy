#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

//https://stackoverflow.com/questions/1878001/how-do-i-check-if-a-c-stdstring-starts-with-a-certain-string-and-convert-a
static bool starts_with(const std::string str, const std::string prefix)
{
    return ((prefix.size() <= str.size()) && std::equal(prefix.begin(), prefix.end(), str.begin()));
}

int overlap(std::string a, std::string b, int min_length=5)
{
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

std::vector<std::vector<std::string>> permutations(std::vector<std::string> reads) 
{ 
    sort(reads.begin(), reads.end()); 
    std::vector<std::vector<std::string>> all_perm;
  
    do { 
        all_perm.push_back(reads);
    } while (next_permutation(reads.begin(), reads.end()));
    return all_perm;
} 

std::string scs(std::vector<std::string> reads){
    auto all_perm (permutations(reads));

    std::string shortest = "";

    for (auto const& line: all_perm) {
        std::string shortest_actual = line[0];
        for (auto i (0u); i < reads.size()-1; ++i)
        {
            int over = overlap(line[i], line[i+1], 1);
            shortest_actual += line[i+1].substr(over);
        }
        if (shortest == "" || shortest_actual.size() < shortest.size())
        {
            shortest = shortest_actual;
        }

    }
    return shortest;
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
            std::cerr << "To run: ./exe_exact <file>" << std::endl;
        }
        else{
            //std::vector<std::string> vet = {"ABCD", "CDBC", "BCDA"};
            auto scs_final (scs(vet));

            std::cout << "The shortest common superstring is: " << scs_final << std::endl;
            std::cout << "The size of the shortest common superstring is: " << scs_final.size() << std::endl;
        }
    }
    else{
        std::cerr << "To run: ./exe_exact <file>" << std::endl;
    }
}
