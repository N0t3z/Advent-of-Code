#include <iostream>
#include <fstream>
#include <vector>

const std::string filePath {"ExerciseInput.txt"};
struct Location
{
    int x;
    int y;
};

int main()
{
    std::ifstream fileReader(filePath);
    std::string plainText;
    Location Santalocation;
    Santalocation.x = 0;
    Santalocation.y = 0;
    std::vector <Location> recordedLocation;
    recordedLocation.push_back(Santalocation);
    while(std::getline(fileReader, plainText))
    {
        for(int i = 0; i < plainText.size(); i++)
        {
            bool ShouldAdd = true;
            switch(plainText[i])
            {
                case '^': Santalocation.y++; break;
                case 'v': Santalocation.y--;  break;
                case '>': Santalocation.x++; break;
                case '<': Santalocation.x--;  break;
                default: continue;
            }
            for(int j = 0; j < recordedLocation.size(); j++)
            {
                if(recordedLocation[j].x == Santalocation.x && recordedLocation[j].y == Santalocation.y)
                {
                    ShouldAdd = false;
                    break;
                }
            }
            if(ShouldAdd == true)
            {
                recordedLocation.push_back(Santalocation);
            }
        }
    }
    fileReader.close();
    std::cout << "Santa has delivered presents to " << recordedLocation.size() << " houses" << std::endl;
    return 0;
}