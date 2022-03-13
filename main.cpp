#include <iostream>
#include <random>
#include <chrono>

int main() {
    auto current_time = std::chrono::steady_clock::now().time_since_epoch().count() / static_cast<unsigned long long>(1e9);
    std::cout << "Current time is " << current_time << std::endl;
    auto generator = std::mt19937_64(current_time);
    auto distribution = std::uniform_int_distribution(0, 10);
    for (auto i = 0; i < 20; i++) {
        std::cout << distribution(generator) << ' ';
    }
    std::cout << std::endl;
    std::vector<int> numbers;
    std::generate_n(std::back_inserter(numbers), 10,
                    [&distribution, &generator](){
        return distribution(generator);
    });
    for(auto item: numbers) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
    return 0;
}
