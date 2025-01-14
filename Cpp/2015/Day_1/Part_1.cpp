#include <iostream>
#include <fstream>

const std::string filePath = "ExerciseInput.txt";

int main()
{
    short int currentFloor{0};    
    std::string text;
    std::ifstream fileReader (filePath);

    while (getline(fileReader, text))
    {
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == '(')
            currentFloor++;
            else if(text[i] == ')')
            currentFloor--;
        }
    }
    std::cout << "Santa ends up on floor: " << currentFloor << std::endl;
    fileReader.close();
    return 0;
}