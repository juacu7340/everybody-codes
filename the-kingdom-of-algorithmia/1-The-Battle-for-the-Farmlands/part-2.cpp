#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <algorithm>

const std::string file = "input-2.txt";

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
    bool has_x = false;

    for (int i = 0; i < enemies.length(); i += 1) {
        const char & enemy = enemies[i];
        bool is_odd = (i % 2 == 1);

        if (has_x == false) {
            has_x = (enemy == 'x');
        }

        potions += required_potions(enemy);

        if (is_odd == true) {
            if (has_x == true) {
                has_x = false;
            } else {
                potions += 2;
            }
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
