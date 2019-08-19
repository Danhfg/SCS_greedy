#include <random>
#include <iostream>

int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist50(1,50); // distribution in range [1, 6]
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0,3);
    std::vector<std::string> alphab = {"A","C","T","G"};
    int i = 0;
    auto rand_number( dist50(rng));
    std::vector<std::string> reads;
    while (i < 100){
        std::string aux = "";
        for (auto j(0u);j < rand_number; ++j){
            aux += alphab[dist4(rng)];
        }
        reads.push_back(aux);
        ++i;
        rand_number = dist50(rng);
    }

    for (auto const& i: reads) {
		std::cout << i << "\n";
	}
    
}