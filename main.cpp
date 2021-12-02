#include <iostream>
#include <fstream>
#include <vector>

struct Pair {
    int first = 0;
    int second = 0;
    int aim = 0;
};

int main() {
    std::ifstream in_file;
    in_file.open("../input.txt");

    if(!in_file)
    {
        std::cerr << "File didn't open correctly!" << std::endl;
        return 1;
    }

    Pair xya;
    std::string word;
    int num;

    while(!in_file.eof())
    {
        in_file >> word >> num;
        if (word == "up")
            xya.aim -= num;
        else if (word == "down")
            xya.aim += num;
        else if (word == "forward")
        {
            xya.first += num;
            xya.second += xya.aim * num;
        }
    }

    std::cout << xya.first * xya.second << std::endl;

    return 0;
}
