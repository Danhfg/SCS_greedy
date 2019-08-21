#include <random>
#include <iostream>

int main(int argc, char *argv[])
{
    int k = 50;
    if (argc > 1)
        k = std::stoi(argv[1]);
    std::vector<std::string> alphab = {"AB","BA","C"};
    
    std::vector<std::string> reads;

    std::string aux = "C";
    for (auto j(0);j < k; ++j){
        aux += alphab[0];
    }
    reads.push_back(aux);
    aux = "";
    for (auto j(0);j < k; ++j){
        aux += alphab[1];
    }
    reads.push_back(aux);
    aux = "";
    for (auto j(0);j < k; ++j){
        aux += alphab[0];
    }
    aux += "C";
    reads.push_back(aux);

    for (auto const& i: reads) {
        std::cout << i << "\n";
    }
    
}