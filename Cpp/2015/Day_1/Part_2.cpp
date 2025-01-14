#include <iostream>
#include <fstream>
#include <string>

const std::string filePath = "ExerciseInput.txt";

int main()
{
    short int currentFloor {0};
    short int currentPosition {1};  
    std::string text;
    std::ifstream fileReader (filePath);

    while (std::getline(fileReader, text))
    {
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == '(')
            currentFloor++;
            else if(text[i] == ')')
            {
                currentFloor--;
                if(currentFloor == -1)
                {
                    std::cout << "Santa first enters the basement on character #" << currentPosition << std::endl;
                    return 0;
                }
            }
            else
            {
                continue;
            }
            currentPosition++;
        }
    }
    fileReader.close();
    return 0;
}