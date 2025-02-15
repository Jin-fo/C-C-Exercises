#include "My_Array.h"
#include <random>

int main() {
    My_Array array;
    //[v]gpt provided code to perform test-case
    std::random_device rand;
    std::mt19937 gen(rand());

    std::uniform_real_distribution<float> dist(-100.0, 100.0);
    //[^]gpt provided code to perform test-case

    float value;

    std::cout << "\n[o]Array of Random Values: ";
    for (int i = 0; i < 5; i++) {
        float random_gpt = dist(gen);
        array.add_value(random_gpt);
        std::cout << "\n\t" << random_gpt;
    }
    std::cout << "\n[o]Lowest to Highest: ";
    std::cout <<    "\n\t^||Lowest values: " << array.get_low();
    array.show_low_high();
    
    std::cout << "\n[o]Highest to Lowest: ";
    std::cout <<    "\n\t^||Highest values: " << array.get_high();
    array.show_high_low();
    
    std::cout << "\n[o]Sum of values: " << array.get_sum();
    std::cout << "\n[o]Postive count: " << array.count_pos();

    std::cout << "\n[>]check for value: ";
    std::cin >> value;
    std::cout <<    "\t^||True(1)/False(0): " << array.check_exist(value);
}