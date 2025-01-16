#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string filePath {"ExerciseInput.txt"};
std::vector <int> Seperator(std::string plainText, char delimiter);

int main()
{
    std::ifstream fileReader (filePath);
    std::string plainText;
    int sum {0};
    int smallestSide {0};
    int lw, wh, hl;
    while(std::getline(fileReader, plainText))
    {
        std::vector <int> sides;
        sides = Seperator(plainText, 'x');
        lw = smallestSide = sides.at(0) * sides.at(1);
        wh = sides.at(1) * sides.at(2);
        hl = sides.at(0) * sides.at(2);

        

        if(wh < smallestSide && wh < hl)
            smallestSide = wh;
        else if(hl < smallestSide)
            smallestSide = hl;
            
        sum += (2 * lw) + (2 * wh) + (2 * hl) + smallestSide;
    }
    std::cout << "The elves should order " << sum << " square feet of wrapping paper";
    std::cout << std::endl;
    return 0;
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