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
    std::vector<int> windows;
    for(std::size_t i = 2; i < measurements.size(); i++)
    {
        windows.push_back(measurements.at(i) + measurements.at(i-1) + measurements.at(i-2));
    }
    for(std::size_t i = 1; i < windows.size(); i++)
    {
        if(windows.at(i) > windows.at(i-1))
            count++;
    }

    std::cout << count << std::endl;
    in_file.close();

    return 0;
}
