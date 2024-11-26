#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <algorithm>

const std::string file = "input-3.txt";

std::string get_input() {
    std::ifstream input_stream(file);

    std::string input;
    std::getline(input_stream, input);

    return input;
}

int required_potions(char enemy) {
    switch (enemy) {
        case 'D' : return 5;
        case 'C' : return 3;
        case 'B' : return 1;
        default  : return 0;
    }
}

int count_potions(const std::string& enemies) {
    int potions = 0;
    int x_counter = 0;

    for (int i = 0; i < enemies.length(); i += 1) {
        const char & enemy = enemies[i];

        bool is_x = (enemy == 'x');

        if (is_x == true) {
            x_counter++;
        }

        bool is_group = (i % 3 == 2);

        potions += required_potions(enemy);

        if (is_group == true) {
            // 3 -> 0
            // 2 -> 0
            // 1 -> 2
            // 0 -> 6

            if (x_counter < 2) {
                potions += 6 - (x_counter * 4);
            }

            x_counter = 0;
        }
    }

    return potions;
}

int main() {
    const std::string input = get_input();

    int potions = count_potions(input);

    std::cout << "Potions: " << potions << '\n';

    return 0;
}
