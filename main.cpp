#include <iostream>
#include <random>
#include <ctime>
#include <string>

std::random_device rd;
std::mt19937_64 engine(rd());

int main(int argc, char *argv[])
{

    const int PASS_SIZE = 42;

    std::string char_set = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    std::uniform_int_distribution<int> t_rand(0, char_set.size()-1);

    std::string password;

    for (int i = 0; i < PASS_SIZE; i++) {
        password += char_set[t_rand(engine)];
    }

    std::cout << password << "\n";

    return 0;
}
