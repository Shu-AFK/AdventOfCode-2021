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

    std::vector<int> measurements;
    int temp;
    while(!in_file.eof())
    {
        in_file >> temp;
        measurements.push_back(temp);
    }

    int count = 0;
    for (int i = 1; i < measurements.size(); i++)
    {
        if (measurements.at(i) > measurements.at(i - 1))
            count++;
    }

    std::cout << count << std::endl;
    in_file.close();

    return 0;
}
