#include <random>
#include <iostream>

int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist50(1,50);
    std::vector<std::string> alphab = {"AB","BA","C"};
    
    auto k( dist50(rng));
    std::vector<std::string> reads;

    std::string aux = "C";
    for (auto j(0u);j < k; ++j){
        aux += alphab[0];
    }
    reads.push_back(aux);
    aux = "";
    for (auto j(0u);j < k; ++j){
        aux += alphab[1];
    }
    reads.push_back(aux);
    aux = "";
    for (auto j(0u);j < k; ++j){
        aux += alphab[0];
    }
    aux += "C";
    reads.push_back(aux);

    for (auto const& i: reads) {
        std::cout << i << "\n";
    }
    
}