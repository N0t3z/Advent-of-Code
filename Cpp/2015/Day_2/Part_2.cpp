#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string filePath {"ExerciseInput.txt"};

std::vector <int> Seperator(std::string plainText, char delimiter);
std::vector<int> Sort(std::vector <int> input );

int main()
{
    std::ifstream fileReader (filePath);
    std::string plainText;
    int sum {0};
    while(std::getline(fileReader, plainText))
    {
        std::vector <int> sides;
        sides = Seperator(plainText, 'x');
        sides = Sort(sides);   
        sum += (2 * sides.at(0) + 2 * sides.at(1)) + (sides.at(0) * sides.at(1) * sides.at(2));
    }
    std::cout << "The elves should order " << sum << " square feet of wrapping paper";
    std::cout << std::endl;
    return 0;
}



std::vector<int> Sort(std::vector <int> input )
{
    for(int i = 0; i < input.size()-1; i++)
    {
        for(int j = i+1; j < input.size(); j++)
        {
            if(input.at(i) > input.at(j))
            {
                int temp {input.at(i)};
                input.at(i) = input.at(j);
                input.at(j) = temp;
            }
        }
    }
    return input;
}


std::vector <int> Seperator(std::string plainText, char delimiter)
{
    std::vector <int> buffer;
    std::string temp;
    for(int i = 0; i < plainText.size(); i++)
    {
        if(tolower(plainText[i]) == tolower(delimiter))
        {
            buffer.push_back(std::stoi(temp));
            temp.clear();
            continue;
        }
        else if( i == plainText.size()-1)
        {
            temp += plainText[i];
            buffer.push_back(std::stoi(temp));
        }
        else
        {
          temp += plainText[i];
        }
    }
    return buffer; 
}