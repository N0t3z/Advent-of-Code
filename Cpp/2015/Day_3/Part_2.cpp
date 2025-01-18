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
    Location RoboSantaLocation;
    Santalocation.x = RoboSantaLocation.x = 0;
    Santalocation.y = RoboSantaLocation.y = 0;
    char currentTurn {'0'};
    std::vector <Location> recordedLocation;
    recordedLocation.push_back(Santalocation);
    while(std::getline(fileReader, plainText))
    {
        for(int i = 0; i < plainText.size(); i++)
        {
            bool ShouldAdd = true;
            if(currentTurn == '0')
            {
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
                currentTurn = '1';
            }
            else if (currentTurn == '1')
            {
                switch(plainText[i])
                {
                    case '^': RoboSantaLocation.y++; break;
                    case 'v': RoboSantaLocation.y--;  break;
                    case '>': RoboSantaLocation.x++; break;
                    case '<': RoboSantaLocation.x--;  break;
                    default: continue;
                }
                for(int j = 0; j < recordedLocation.size(); j++)
                {
                    if(recordedLocation[j].x == RoboSantaLocation.x && recordedLocation[j].y == RoboSantaLocation.y)
                    {
                        ShouldAdd = false;
                        break;
                    }
                }
                if(ShouldAdd == true)
                {
                    recordedLocation.push_back(RoboSantaLocation);
                }
                currentTurn = '0';
            }
        }
    }
    fileReader.close();
    std::cout << "Santa and Robo-Santa have delivered presents to " << recordedLocation.size() << " houses" << std::endl;
    return 0;
}

