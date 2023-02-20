#include <iostream>
#include <random>
#include <ctime>
#include <string>

std::random_device rd;
std::mt19937_64 engine(rd());

int main(int argc, char *argv[])
{

    int PASS_SIZE = 42;
    bool ADD_CHARS = true;

    // Input Validation Block PASS_SIZE
    std::string input;
    bool valid_input = false;
    do {
        std::cout << "Enter size(default " << PASS_SIZE << "): ";
        std::getline(std::cin, input);

        if (input.empty()) { // user didn't enter anything
            valid_input = true;
        } else {
            try {
                PASS_SIZE = std::stoi(input);
                valid_input = true;
            } catch (std::invalid_argument&) {
                std::cerr << "Invalid input, please enter an integer." << "\n";
            } catch (std::out_of_range&) {
                std::cerr << "Input out of range, please enter a smaller integer." << "\n";
            }
        }
    } while (!valid_input);

    valid_input = false;
    input = "";

    // Input Validation Block ADD_CHARS
    do {
        std::cout << "Use extra chars (Y/N, default Y): ";
        std::getline(std::cin, input);

        if (input.empty()) { // user didn't enter anything
            valid_input = true;
        } else {
            std::transform(input.begin(), input.end(), input.begin(), ::tolower);

            if (input == "y" || input == "yes") {
                ADD_CHARS = true;
            } else if (input == "n" || input == "no" || input == "not") {
                ADD_CHARS = false;
            } else {
                std::cerr << "Invalid input, please enter Y/N or yes/no." << "\n";
            }

            valid_input = true;
        }
    } while (!valid_input);

    std::string char_set = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"; // 62(Length)
    std::string additional_char_set = "!@#$%&"; // 6(Length)

    std::uniform_int_distribution<int> t_rand(0, char_set.size()-1);

    std::string password;

    // Password Generation
    for (int i = 0; i < PASS_SIZE; i++) {
        password += char_set[t_rand(engine)];
    }

    // Additional Symbols
    if (ADD_CHARS) {
        std::uniform_int_distribution<int> add_chars(0, additional_char_set.size()-1);
        std::uniform_int_distribution<int> new_rand(0, password.size()-1);

        // Always Add Chars
        std::uniform_int_distribution<int> t2_rand(1, password.size()-2);
        password[t2_rand(engine)] = additional_char_set[add_chars(engine)];

        for (int i = 1; i < PASS_SIZE-1; i++) {
            if (i == new_rand(engine)) {
                password[i] = additional_char_set[add_chars(engine)];
            }
        }

    }

    std::cout << "\n" << password << "\n\n";

    return 0;
}
