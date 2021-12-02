#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream in_file;
    in_file.open("../input.txt");

    if(!in_file)
    {
        std::cerr << "File didn't open correctly!" << std::endl;
        return 1;
    }

    std::pair<int, int> xy {0, 0};
    std::string word;
    int num;
    while(!in_file.eof())
    {
        in_file >> word >> num;
        if(word == "forward")
            xy.first += num;
        else if(word == "up")
            xy.second -= num;
        else if(word == "down")
            xy.second += num;
    }

    std::cout << xy.first * xy.second << std::endl;

    return 0;
}
