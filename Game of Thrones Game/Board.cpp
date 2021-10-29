#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "Board.h"
using namespace std;

//Insert all extra special functions that I find out i need to make
//either for specific calculations, split, or things like that
void splitMap(string input, char delimiter, char Map[25][16], int numRows) // split function that makes the map
{
   
    if (input.length() == 0) // if the given input string is empty
    {
        return;
    }
    
    int numCols = 0; // piece counter
    input = input + delimiter;
    for (int i = 0; i < input.length(); i++) // for loop running to the length of the string
    {
        if (numCols == 16) // failsafe if j reaches length
        {
            return;
        }
        
        if (input[i] != delimiter) // if the string position equals the delimiter
        {
        	if(input[i] == 'p')
        	{
        	    Map[numRows][numCols] = '*';
        	    numCols++;
        	}
        	
        	else if(input[i] == 'w')
        	{
        	    Map[numRows][numCols] = '~';
        	    numCols++;
        	}
        	
        	else if(input[i] != 'p' || input[i] != 'w')
        	{
        	    char capital = input[i];
        	    Map[numRows][numCols] = capital;
        	    numCols++;
        	    
        	}
           
        } 
        
    }
    return;

}

void splitCity(string input, char delimiter, string cityRay[5]) // split function that fills the city aray
{
    
    if (input.length() == 0) // if the given input string is empty
    {
        return;
    }
    
    int length = input.length();
    
    int spot1 = 0;
    int spot2 = 0;
    int spot3 = 0;
    int spot4 = 0;
    
    input = input + delimiter;
    for (int i = 0; i < input.length(); i++) // for loop running to the length of the string
    {
        if (input[i] == delimiter && spot1 == 0) // if the string position equals the delimiter
        {
        	spot1 = i;
        	cityRay[0] = input.substr(0,1);
        	continue;
        }
        
        //cout << input.substr(spot1 + 1,i - spot1);
        else if(input[i] == delimiter && spot2 == 0)
        {
            spot2 = i;
            cityRay[1] = input.substr(2,i - 2);
            continue;
        }
        
        else if(input[i] == delimiter && spot3 == 0)
        {
            spot3 = i;
            cityRay[2] = input.substr(spot2 + 1,(i - spot2) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot4 == 0)
        {
            spot4 = i;
            cityRay[3] = input.substr(spot3 + 1,(spot4 - spot3) - 1);
            cityRay[4] = input.substr(spot4 + 1,(length - spot4) - 1);
            return;
        }
        
    }

}

void splitHero(string input, char delimiter, string heroRay[11]) // split function that fills the hero array
{
    
    if (input.length() == 0) // if the given input string is empty
    {
        return;
    }
    
    int length = input.length();
    
    int spot1 = 0;
    int spot2 = 0;
    int spot3 = 0;
    int spot4 = 0;
    int spot5 = 0;
    int spot6 = 0;
    int spot7 = 0;
    int spot8 = 0;
    int spot9 = 0;
    int spot10 = 0;
    
    input = input + delimiter;
    for (int i = 0; i < input.length(); i++) // for loop running to the length of the string
    {
        if (input[i] == delimiter && spot1 == 0) // if the string position equals the delimiter
        {
        	spot1 = i;
        	heroRay[0] = input.substr(0,i);
        	continue;
        }
        
        //cout << input.substr(spot1 + 1,i - spot1);
        else if(input[i] == delimiter && spot2 == 0)
        {
            spot2 = i;
            heroRay[1] = input.substr(spot1 + 1,(spot2 - spot1) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot3 == 0)
        {
            spot3 = i;
            heroRay[2] = input.substr(spot2 + 1,(spot3 - spot2) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot4 == 0)
        {
            spot4 = i;
            heroRay[3] = input.substr(spot3 + 1,(spot4 - spot3) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot5 == 0)
        {
            spot5 = i;
            heroRay[4] = input.substr(spot4 + 1,(spot5 - spot4) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot6 == 0)
        {
            spot6 = i;
            heroRay[5] = input.substr(spot5 + 1,(spot6 - spot5) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot7 == 0)
        {
            spot7 = i;
            heroRay[6] = input.substr(spot6 + 1,(spot7 - spot6) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot8 == 0)
        {
            spot8 = i;
            heroRay[7] = input.substr(spot7 + 1,(spot8 - spot7) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot9 == 0)
        {
            spot9 = i;
            heroRay[8] = input.substr(spot8 + 1,(spot9 - spot8) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot10 == 0)
        {
            spot10 = i;
            heroRay[9] = input.substr(spot9 + 1,(spot10 - spot9) - 1);
            heroRay[10] = input.substr(i + 1,(length - i) - 1);
            return;
        }
        
    }

}


void splitWar(string input, char delimiter, string warRay[7]) // split function that fills the hero array
{
    
    if (input.length() == 0) // if the given input string is empty
    {
        return;
    }
    
    int length = input.length();
    
    int spot1 = 0;
    int spot2 = 0;
    int spot3 = 0;
    int spot4 = 0;
    int spot5 = 0;
    int spot6 = 0;
    int spot7 = 0;
    
    input = input + delimiter;
    for (int i = 0; i < input.length(); i++) // for loop running to the length of the string
    {
        if (input[i] == delimiter && spot1 == 0) // if the string position equals the delimiter
        {
        	spot1 = i;
        	warRay[0] = input.substr(0,i);
        	continue;
        }
        
        //cout << input.substr(spot1 + 1,i - spot1);
        else if(input[i] == delimiter && spot2 == 0)
        {
            spot2 = i;
            warRay[1] = input.substr(spot1 + 1,(spot2 - spot1) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot3 == 0)
        {
            spot3 = i;
            warRay[2] = input.substr(spot2 + 1,(spot3 - spot2) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot4 == 0)
        {
            spot4 = i;
            warRay[3] = input.substr(spot3 + 1,(spot4 - spot3) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot5 == 0)
        {
            spot5 = i;
            warRay[4] = input.substr(spot4 + 1,(spot5 - spot4) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot6 == 0)
        {
            spot6 = i;
            warRay[5] = input.substr(spot5 + 1,(spot6 - spot5) - 1);
            continue;
        }
        
        else if(input[i] == delimiter && spot7 == 0)
        {
            spot7 = i;
            warRay[6] = input.substr(spot6 + 1,(spot7 - spot6) - 1);
            continue;
        }
        
        
    }

}


int Board::matcher(string warName)
{
    int RoCounter = 0;
    while(RoCounter < numHeroes)
    {
        string Name1 = Heroes[RoCounter].getWar1();
        if(Name1 == warName)
        {
            return RoCounter;
        }
        
        string Name2 = Heroes[RoCounter].getWar2();
        if(Name2 == warName)
        {
            return RoCounter;
        }
        
        string Name3 = Heroes[RoCounter].getWar3();
        if(Name3 == warName)
        {
            return RoCounter;
        }
        
        string Name4 = Heroes[RoCounter].getWar4();
        if(Name4 == warName)
        {
            return RoCounter;
        }
        
        RoCounter++;
    }
}


//Member Functions

Board::Board() // default (more variables to come probably)
{
    turns = 0;
    numCities = 0;
    numHeroes = 0;
    numWarriors = 0;
    
}


void Board::intBoard(string mapFile, string cityFile) 
// initializes map array
// this takes in the map file  and city file and establishes every land tile individually as an object with private values 
// it also reads a city file and creates city objects for each line 
// this also randomly places the dragonglass
{
    cout << "Initiating Tiles..." << endl;
    cout << endl;
    
    ifstream fileMap;
    fileMap.open(mapFile);
    if (fileMap.fail()) {return;} // open the fil and make sure it isn't empty. If it is, return -1
    
    string line;
    int numRows = 0;
    while (getline(fileMap, line)) // while loop that checks each line
    {
        
        if (line.empty() == false) // as long as the line isn't empty
        {
            splitMap(line,',',Map,numRows); // run split on it
            
            numRows ++;
            if (numRows == 25) // once numbooks is full, break
            {
                break;
            }
        }
    }    
    
    //CREATE LAND OBJECT
    int landRows;        
    for(int landCol = 0; landCol < 17; landCol++)
    {
        if(landRows == 25)
        {
            break;
        }
        
        if(landCol == 16)
        {
            landRows++;
            landCol = -1;
            continue;
        }
       
        //cout << Map[landRows][landCol] << endl;
        if(Map[landRows][landCol] > 64 && Map[landRows][landCol] < 91 && landCol < 16)
        {
            Tiles[landRows][landCol] = Land(landRows,landCol,0,0,0);
            continue;
        }
        else if(Map[landRows][landCol] == '*' && landCol < 16)
        {
            Tiles[landRows][landCol] = Land(landRows,landCol,2,20,10);
            //cout << "(" << Tiles[landRows][landCol].getRow() << "," << Tiles[landRows][landCol].getCol() << ") is Land" << endl;
            continue;
        }
        else if(Map[landRows][landCol] == '~' && landCol < 16)
        {
            Tiles[landRows][landCol] = Land(landRows,landCol,1,10,0);
            //cout << "(" << Tiles[landRows][landCol].getRow() << "," << Tiles[landRows][landCol].getCol() << ") is Water" << endl;
            continue;
        }
            
        else if(landCol < 16)
        {
            //cout << "(" << landRows << "," << landCol << ") is a city" << endl;
            continue;
        }
                
    }

            
        
    
    //map print
    cout << "This is the map" << endl;
    cout << endl;
    int c = 0;
    for(int r = 0; r < 17; r++)
    {
        if(c == 25)
        {
            break;
        }
        
        if(r == 16)
        {
            cout << endl;
            c++;
            r = -1;
            continue;
        }
        cout << Map[c][r] << " ";
        
    }
    cout << endl;
    
    //looking for and setting cities
    cout << "Initializing Cities..." << endl;
    cout << endl;
    //cout << "These are the cities and their locations" << endl;
    cout << endl;
    
    int citiesRow = 0;
    for(int citiesCol = 0; citiesCol < 160; citiesCol++)
    {
        if(citiesRow == 25)
        {
            break;
        }
        
        char spot = Map[citiesRow][citiesCol];
        
        if(spot > 64 && spot < 91)
        {
            string cityRay[5];
            ifstream fileCity;
            fileCity.open(cityFile);
            if(fileCity.fail()) {return;}
    
            string cityLine;
    
            while (getline(fileCity,cityLine)) // while loop that checks each line
            {
        
                if (cityLine.empty() == false) // as long as the line isn't empty
                {
                    string spotString(1, spot);
                    string citySpot = cityLine.substr(0,1);
                    
                    if(citySpot == spotString)
                    {
                        splitCity(cityLine,',',cityRay);
                        
                        string Let = cityRay[0];
                        int Mon = stoi(cityRay[2]);
                        int Arm = stoi(cityRay[3]);
                        int Poi = stoi(cityRay[4]);
                        
                        Cities[numCities] = City(citiesRow,citiesCol,Let,cityRay[1],Mon,Arm,Poi,"none");
                        
            
                        break;
                    }
                }
        
            }
            //cout << numCities << endl;
            //cout << Cities[numCities].getLetter() << "  " << Cities[numCities].getName() << "  " << cityRay[2] << "  " << cityRay[3] << "  " << cityRay[4] << endl;
            //cout << "Coordinates (" << Cities[numCities].getRow() + 1 << "," << Cities[numCities].getCol() + 1 << ")" << endl;
            //cout << endl;
            numCities++;
            if(citiesCol == 15)
            {
                citiesRow++;
                citiesCol = -1;
            }
            continue;
        }
        else if(citiesCol == 15)
        {
            citiesRow++;
            citiesCol = -1;
        }
    }
    //cout << endl;
    
}

void Board::readHeros(string heroFile) 
//this function takes in the hero file, creates a hero object for each line 
//initializes their private variables 
{
    string heroRay[11];
    bool ship;
    cout << "Initiating Heroes..." << endl;
    cout << endl;
    //cout << "These are the Heroes you can choose from" << endl;
    cout << endl;
    
    ifstream fileHero;
    fileHero.open(heroFile);
    if (fileHero.fail()) {return;} // open the fil and make sure it isn't empty. If it is, return -1
    
    string line;
    while (getline(fileHero, line)) // while loop that checks each line
    {
        
        if (line.empty() == false) // as long as the line isn't empty
        {
            splitHero(line,',',heroRay); // run split on it
            
            int Money = stoi(heroRay[1]);
            int Influ = stoi(heroRay[2]);
            int Armsize = stoi(heroRay[3]);
            int row = stoi(heroRay[8]);
            int col = stoi(heroRay[9]);
            
            if(heroRay[10] == "no")
            {
                ship = false;
            }
            else if(heroRay[10] == "yes")
            {
                ship = true;
            }
            
            Heroes[numHeroes] = Hero(heroRay[0],Money,Influ,Armsize,heroRay[4],heroRay[5],heroRay[6],heroRay[7],row,col,ship,0,false);
            

            //cout << "Name: " << Heroes[numHeroes].getName() << endl;
            //cout << "Money: " << Heroes[numHeroes].getMoney() << "  Influence: " << Heroes[numHeroes].getInfluence() << "  Army Size: " << Heroes[numHeroes].getArmSize() << endl;
            if(heroRay[4] != "" || heroRay[5] != "" || heroRay[6] != "" || heroRay[7] != "" )
            {
                //cout << "Warriors: " << Heroes[numHeroes].getWar1() << ", " << Heroes[numHeroes].getWar2() << ", " << Heroes[numHeroes].getWar3() << ", " << Heroes[numHeroes].getWar4() << endl;
        
            }
            else
            {
                //cout << "This Hero starts with no warriors" << endl;
            }
    
            //cout << endl;
            //out << "They start at (" << Heroes[numHeroes].getRow() << "," << Heroes[numHeroes].getCol() << ")" << endl;
    
            if(ship == true)
            {
                //cout << "They also have a ship! You can move on water!" << endl;
            }
            else
            {
                //cout << "They are shipless" << endl;
            }
            //cout << endl;
            //cout << endl;
            numHeroes++;
            
        }
    }
    
    
}

void Board::readWarriors(string warriorFile)
//this function takes in the warrior file and establishes each line as a warrior object
//initializes warrior private variables
{
    string warRay[7];
    bool ship;
    bool freebee;
    bool DG;
    int cord1;
    int switcher;
    int cord2;
    
    cout << "Initiating Warriors..." << endl;
    cout << endl;
    //cout << "These are the Warriors roaming the map, some already have a hero!" << endl;
    cout << endl;
    
    ifstream fileWar;
    fileWar.open(warriorFile);
    if (fileWar.fail()) {return;} // open the fil and make sure it isn't empty. If it is, return -1
    
    string line;
    while (getline(fileWar, line)) // while loop that checks each line
    {
        
        if (line.empty() == false) // as long as the line isn't empty
        {
            splitWar(line,',',warRay); // run split on it
            
            int Strength = stoi(warRay[1]);
            int Loyalty = stoi(warRay[2]);
            int Morale = stoi(warRay[3]);
            
            if(warRay[4] == "no")
            {
                freebee = false;
            }
            else if(warRay[4] == "yes")
            {
                freebee = true;
            }
            
            if(warRay[5] == "no")
            {
                ship = false;
            }
            else if(warRay[5] == "yes")
            {
                ship = true;
            }
            
            if(warRay[6] == "no")
            {
                DG = false;
            }
            else if(warRay[6] == "yes")
            {
                DG = true;
            }
            
            Warriors[numWarriors] = Warrior(0,0,warRay[0],Strength,Loyalty,Morale,freebee,ship,DG);

            cout << "Name: " << Warriors[numWarriors].getName() << endl;
            cout << "Strength: " << Warriors[numWarriors].getStrength() << "  Loyalty: " << Warriors[numWarriors].getLoyalty() << "  Morale: " << Warriors[numWarriors].getMorale() << endl;
            
            if(DG == true)
            {
                
                int Ro = matcher(warRay[0]);
                string RoName = Heroes[Ro].getName();
                Warriors[numWarriors].setMaster(RoName);
                
                
                cout << "They work for John Snow, have no ship, and will start with him at (" << Heroes[Ro].getRow() << "," << Heroes[Ro].getCol() << ")" << endl;
                cout << "But..... they have Dragonglass! WOW!" << endl;
                Warriors[numWarriors].setRow(Heroes[Ro].getRow());
                Warriors[numWarriors].setCol(Heroes[Ro].getCol());
                cout << endl;
                
                numWarriors++;
                continue;
            }
            
            if(freebee == true && ship == false)
            {
                //random cords have to be land
                
                switcher = 0;
            
                while(switcher == 0)
                {
                    cord1 = rand() % 16;
                    cord2 = rand() % 25;
                    
                    if(Map[cord2][cord1] != '~')
                    {
                        switcher = 1;
                    }
                }
                
                Warriors[numWarriors].setRow(cord2);
                Warriors[numWarriors].setCol(cord1);
                
                cout << "They are a free warrior with no ship, and will start at (" << Warriors[numWarriors].getRow() << "," << Warriors[numWarriors].getCol() << ")" << endl;
                numWarriors++;
            }
            else if(freebee == true && ship == true)
            {
                
                cord1 = rand() % 16;
                cord2 = rand() % 25;
                Warriors[numWarriors].setRow(cord2);
                Warriors[numWarriors].setCol(cord1);
                
                cout << "They are a free warrior with a ship, and start at (" << Warriors[numWarriors].getRow() << "," << Warriors[numWarriors].getCol() << ")" << endl;
                cout << "If you can catch them, you can travel on water!" << endl;
                numWarriors++;
            }
            else if(freebee == false)
            {
                //find hero they are attached to as well as their coords
                if(ship == true)
                {
                    int Ro = matcher(warRay[0]);
                    string RoName = Heroes[Ro].getName();
                    Warriors[numWarriors].setMaster(RoName);
                    
                    cout << "They are not a free warrior, and start with " << RoName << "." << endl;
                    cout << "They start together at (" << Heroes[Ro].getRow() << "," << Heroes[Ro].getCol() << ")" << endl;
                    Warriors[numWarriors].setRow(Heroes[Ro].getRow());
                    Warriors[numWarriors].setCol(Heroes[Ro].getCol());
                    Heroes[Ro].setBoat("yes");
                    numWarriors++;
                }
                
                else
                {
                    int Ro = matcher(warRay[0]);
                    string RoName = Heroes[Ro].getName();
                    Warriors[numWarriors].setMaster(RoName);
                    
                    cout << "They are not a free warrior, and start with " << RoName << "." << endl;
                    cout << "They start together at (" << Heroes[Ro].getRow() << "," << Heroes[Ro].getCol() << ")" << endl;
                    Warriors[numWarriors].setRow(Heroes[Ro].getRow());
                    Warriors[numWarriors].setCol(Heroes[Ro].getCol());
                    numWarriors++;
                }
            }    
            cout << endl;
            
        }
    }
    
     
}

void Board::peopleToMap()
// this function matches the starting coordinates of each hero and warrior with a tile on the map, 
// it also updates their values based on their starting tile
{
    cout << endl;
    int heroCount;
    for(heroCount = numHeroes - 1; heroCount > -1; heroCount--)
    {
        string naMe = Heroes[heroCount].getName();
        int points = Heroes[heroCount].getPoints();
        int roRow = Heroes[heroCount].getRow() - 1;
        int roCol = Heroes[heroCount].getCol() - 1;
        
        int adder = Tiles[roRow][roCol].getPoints();
        
        if(adder == 1 || adder == 2)
        {
            Heroes[heroCount].setPoints(adder);
            //cout << naMe << " gains " << adder << " points from their starting tile" << endl;
            //cout << endl;
            continue;
        }
        
        //check to see if its a city
        
        int cityCount;
        for(cityCount = numCities - 1; cityCount > -1; cityCount--)
        {
            int citRow = Cities[cityCount].getRow();
            int citCol = Cities[cityCount].getCol();
            if(citRow == roRow && citCol == roCol)
            {
                //cout << naMe << " starts in the city " << Cities[cityCount].getName() << endl;
                //cout << "They start with " << Cities[cityCount].getPoints() << " points!" << endl;
                Heroes[heroCount].setPoints(Cities[cityCount].getPoints());
                
                //setting owner
                string owner = Heroes[heroCount].getName();
                Cities[cityCount].setOwner(owner);
                
                //cout << endl;
            }
        }
        
    }

}

void Board::startUp()
{
    
    cout << "Welcome to the G A M E of T H R O N E S!" << endl;
    cout << endl;
    cout << endl;
    
    cout << "State your name, Your Grace:" << endl;
    string name;
    cin >> name;  //user gives name
    cout << endl;
    
    cout << "Would you like to choose a hero " << name << ", Your Grace?(Y/N):" << endl;
    string YorN;
    cin >> YorN; //user chooses yes or no
    
    //makes sure input is valid
    if(YorN == "Y" || YorN == "y") //valid input
    {
        cout << endl;
        cout << "Please choose from the following heroes:" << endl;
        cout << "1. Cersei Lannister" << endl;
        cout << "2. Stannis Baratheon" << endl;
        cout << "3. Jon Snow" << endl;
        cout << "4. Sansa Stark" << endl;
        cout << "5. Euron Greyjoy" << endl;
        cout << "6. Daenerys Targaryen" << endl;
        cout << endl;
        int choice;
        cin >> choice;
        
        string roName;
        switch(choice) //switch for hero assignment
        {
            case 1: roName = "Cersei Lannister"; break;
            case 2: roName = "Stannis Baratheon"; break;
            case 3: roName = "Jon Snow"; break;
            case 4: roName = "Sansa Stark"; break;
            case 5: roName = "Euron Greyjoy"; break;
            case 6: roName = "Daenerys Targaryen"; break;
            default: roName = ""; break;
        }
        
        PlayerRo = choice - 1;
        cout << "You have chosen " << roName << "!" << endl;
        cout << "Here are their stats:" << endl;
        cout << "Money: " << Heroes[PlayerRo].getMoney() << " Influence: " << Heroes[PlayerRo].getInfluence() << " Army Size: " << Heroes[PlayerRo].getArmSize() << endl;
        
        string warr = Heroes[PlayerRo].getWar1();
        if(warr != "NULL")
        {
            cout << "Your warriors are: " << Heroes[PlayerRo].getWar1() << ", " << Heroes[PlayerRo].getWar2() << ", " << Heroes[PlayerRo].getWar3() << ", " << Heroes[PlayerRo].getWar4() << endl;
            cout << "You start at: (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
        }
        
        else
        {
            cout << "You have no warriors.." << endl;
        }
        
    }
    else
    {
        PlayerRo = 6;
        
        cout << endl;
        cout << "Your Grace " << name << ", you have chosen to go on this journey alone." << endl;
        cout << "Please provide starting values for your adventure." << endl;
        cout << endl;
        //user creates a custom hero object
        cout << "Money?" << endl;
        int money;
        cin >> money;
        cout << endl;
        
        cout << "Influence?" << endl;
        int influ;
        cin >> influ;
        cout << endl;
        
        cout << "Army Size?" << endl;
        int AS;
        cin >> AS;
        cout << endl;
        
        cout << "Starting Row?" << endl;
        int row;
        cin >> row;
        cout << endl;
        
        cout << "Starting Column?" << endl;
        int col;
        cin >> col;
        cout << endl;
        
        bool boat;
        if(Map[row][col] == '*')
        {
            boat = false;
        }
        else if(Map[row][col] == '~')
        {
            boat = true;
        }
        
        Heroes[numHeroes] = Hero(name,money,influ,AS,"","","","",row,col,boat,0,false);
        
        cout << "You are " << name << endl;
        cout << "Your stats are: " << "Money: " << Heroes[numHeroes].getMoney() << "   Influence: " << Heroes[numHeroes].getInfluence() << "   Army Size: " << Heroes[numHeroes].getArmSize() << endl;
        cout << "You have no warriors" << endl;
        cout << "You start at (" << row << "," << col << ")" << endl;
        if(boat == true)
        {
            cout << "You start on water with a boat!" << endl;
            cout << endl;
        }
    
    }
    cout << endl;
    cout << "LET'S BEGIN!" << endl;
    cout << endl;
}

void Board::userDeath()
// this function kills the game if the user hero dies
// prints to screen the top five players
{
    cout << endl;
    cout << "R. I. P." << endl;
    exit (EXIT_FAILURE);
}

Hero Board::soloDeath(Hero badguy)
{
    int one;
    for(one = 0; one < numHeroes; one++)
    {
        if(Heroes[one].getName() == badguy.getName())
        {
            break;
        }
    }
    cout << badguy.getName() << " has been defeated" << endl;
    cout << endl;
    Heroes[one].setDead("yes");
    
    string war1 = Heroes[one].getWar1();
    string war2 = Heroes[one].getWar2();
    string war3 = Heroes[one].getWar3();
    string war4 = Heroes[one].getWar4();
    
    if(war1 !=  "NULL")
    {
        for(int y = 0; y < numWarriors; y++)
        {
            if(Warriors[y].getName() == war1)
            {
                Warriors[y].setFree("yes");
            }
        }
    }
    
    if(war2 !=  "NULL")
    {
        for(int y = 0; y < numWarriors; y++)
        {
            if(Warriors[y].getName() == war2)
            {
                Warriors[y].setFree("yes");
            }
        }
    }
    
    if(war3 !=  "NULL")
    {
        for(int y = 0; y < numWarriors; y++)
        {
            if(Warriors[y].getName() == war3)
            {
                Warriors[y].setFree("yes");
            }
        }
    }
    
    if(war4 !=  "NULL")
    {
        for(int y = 0; y < numWarriors; y++)
        {
            if(Warriors[y].getName() == war4)
            {
                Warriors[y].setFree("yes");
            }
        }
    }
    
    return Heroes[one];
}

Hero Board::otherHeroDeath(Hero winner, Hero loser)
{
    int one;
    for(one = 0; one < numHeroes; one++)
    {
        if(Heroes[one].getName() == winner.getName())
        {
            break;
        }
    }
    
    int two;
    for(two = 0; two < numHeroes; two++)
    {
        if(Heroes[two].getName() == loser.getName())
        {
            break;
        }
    }
    
    cout << endl;
    //cout << changers[1].getName() << " has been defeated" << endl;
    Board::soloDeath(Heroes[two]);
    cout << endl;
    cout << "Their warriors are " << winner.getName() << "'s" << endl;
    cout << endl;
    
    //warrior chooser
    
    cout << "Their money, influence, and army are " << winner.getName() << "'s" << endl;
    cout << endl;
    
    //gives stats
    
    cout << winner.getName() << " takes control of their cities" << endl;
    cout << endl;
    
    // city switcher
    
    return Heroes[one];
    
}

void Board::userWins()
//this function is called if the usr defeats the white walkers, hooray!
{
    cout << "You are the winner!" << endl;
    exit (EXIT_FAILURE);
    
}

void Board::printMap()
//this function prints the map around the user
{
    int printRow = Heroes[PlayerRo].getRow();
    int printCol = Heroes[PlayerRo].getCol();
    int startRow = printRow - 3;
    int startCol;
    int checker = 1;
    for(startCol = printCol - 3; startCol < printCol + 5; startCol++)
    {
        int roCheck = 0;
        for(int v = 0; v < numHeroes; v++)
        {
            
            if(v == PlayerRo)
            {
                continue;
            }
            
            if(startCol == Heroes[v].getCol() && startRow == Heroes[v].getRow())
            {
                if(Heroes[v].getDead() == false)
                {
                    cout << "h" << " ";
                    roCheck = 1;
                    break;
                }
            
            }
        }
        if(roCheck == 1)
        {
            continue;
        }
        
        int warCheck = 0;
        for(int w = 0; w < numWarriors; w++)
        {
            
            if(startCol == Warriors[w].getCol() && startRow == Warriors[w].getRow() && Warriors[w].getFree() == true)
            {
                cout << "w" << " ";
                warCheck = 1;
                break;
            }
        }
        if(warCheck == 1)
        {
            continue;
        }
        
        if(startCol == printCol && startRow == printRow)
        {
            cout << "@" << " ";
            continue;
        }
        if(startRow == printRow + 4)
        {
            return;
        }
        
        if(startCol == printCol + 4)
        {
            cout << endl;
            startRow++;
            startCol = printCol - 4;
            continue;
        }
        if(startRow <= 25 && startCol <= 16 && startRow >= 0 && startCol >= 0)
        {
            cout << Map[startRow - 1][startCol - 1] << " ";
            continue;
        }
        else
        {
            cout << "  " << endl;
        }
        
    }
    
}

Hero Board::heroHitsCity(Hero hitter)
//this function is triggred when a hero lands on a city
//various prompts and possible actions take place here
{
    string realName = hitter.getName(); // which hero
    int o;
    for(o = 0; o < numHeroes; o++)
    {
        if(Heroes[o].getName() == hitter.getName())
        {
            break;
        }
    }
    
    int roRow = Heroes[o].getRow();
    int roCol = Heroes[o].getCol();
    
    int city;
    for(city = 0; city < numCities; city++) // which city
    {
        if(Cities[city].getRow() + 1 == roRow && Cities[city].getCol() + 1 == roCol)
        {
            break;
        }
    }
    
    cout << Heroes[o].getName() << "has arrived in " << Cities[city].getName() << endl;
    cout << endl;
    
    string owner = Cities[city].getOwner();
    
    if(Heroes[o].getName() == Cities[city].getOwner())
    {
        return Heroes[o];
    }
    
    int mon = Cities[city].getMoney();
    int arm = Cities[city].getArmy();
    int points = Cities[city].getPoints();
    
    string whoisit = Cities[city].getOwner();
    int e;
    for(e = 0; e < numHeroes; e++)
    {
        if(Heroes[e].getName() == whoisit)
        {
            break;
        }
    }
    
    Heroes[e].setMoney(mon * -1);
    Heroes[e].setArmSize(arm * -1);
    Heroes[e].setPoints(points * -1);
    
    Heroes[o].setMoney(mon);
    Heroes[o].setArmSize(arm);
    Heroes[o].setPoints(points);
    
    if(o == PlayerRo)
    {
        //player arrives
        cout << "Do you want to listen to rumors?" << endl;
        cout << "(y) for yes or (n) for no" << endl;
        string answ;
        cin >> answ;
        
        
        if(answ == "y")
        {
            int smallDist = 10000;
            Hero closest;
            for(int u = 0; u < numHeroes; u++)
            {
                if(Heroes[u].getDead() == true)
                {
                    continue;
                }
                if(u == PlayerRo)
                {
                    continue;
                }
                int rowab = abs(Heroes[o].getRow() - Heroes[u].getRow());
                int rowcol = abs(Heroes[o].getCol() - Heroes[u].getCol());
                int distance = rowab + rowcol;
                if(distance < smallDist)
                {
                    smallDist = distance;
                    closest = Heroes[u];
                    cout << endl;
                    cout << closest.getName() << " is " << smallDist << " away from you!" << endl;
                }
                
                
            }
            
           
        }    
        
        else if(answ != "y" || answ != "n")
        {
            cout << "Try again" << endl;
            cout << "(y) for yes or (n) for no" << endl;
            cout << endl;
            
            cin >> answ;
        }
        
        
        cout << endl;
        cout << "Do you want to buy more knights?" << endl;
        cout << "(y) for yes or (n) for no" << endl;
        string answer;
        cin >> answer;
        
        
        if(answ == "y")
        {
            Heroes[o].setMoney(20);
            Heroes[o].setArmSize(1);
            
            cout << "You paid 20 dollars and increased your army size by 1!" << endl;
            cout << endl;
            return Heroes[PlayerRo];
        }
        
        else if(answer != "y" || answer != "n")
        {
            cout << "Try again" << endl;
            cout << "(y) for yes or (n) for no" << endl;
            cout << endl;
            
            cin >> answer;
        }
    }
    else
    {
        Cities[city].setOwner(Heroes[o].getName());
        return Heroes[o];
    }
    
    
}

void Board::heroHitsDG()
//triggred when the user hits dragonglass
//something cool I'll come up with...
{
    
}

Hero Board::speech(Hero hero1, Hero hero2)
//this is the speech action in the hero vs hero encounter, calculates the winner
//get influence of hero and morale of oppenents warrior to calculate probability
//updates changes(depending on if you win or lose)
{
    
    int k;
    for(k = 0; k < numHeroes; k++)
    {
        if(Heroes[k].getName() == hero2.getName())
        {
            break;
        }
    }
    int r;
    int Influ = Heroes[PlayerRo].getInfluence();
    double doubFlu = Influ * 1;
    string War = hero2.getWar1();
    for(r = 0; r < numWarriors; r++)
    {
        string check = Warriors[r].getName();
        if(check == War)
        {
            break;
        }
    }
    int WarMor = Warriors[r].getMorale();
    double doubWarMor = WarMor * 1;
    
    double prob1 = 1.0 - (doubWarMor/100);
    double prob2 = doubFlu/1000;
    double probFin = prob1 * prob2;
    cout << endl;
    cout << "You have a " << probFin * 100 << " percent chance of succeeding..." << endl;
    cout << endl;
    cout << "Here we go!" << endl;
    cout << endl;
    
    double outta100 = probFin * 100;
    int integer = (int)round(outta100);
    int lifeordeath = rand () % 100;
    if(lifeordeath <= integer)
    {
        
        Board::otherHeroDeath(Heroes[PlayerRo], Heroes[k]);
        return Heroes[PlayerRo];
    }
    else
    {
        
        cout << "You were not very persuasive...." << endl;
        cout << "Your influence is cut in half" << endl;
        cout << endl;
        int flu = Heroes[PlayerRo].getInfluence();
        int newFlu = flu / 2;
        Heroes[PlayerRo].setInfluence(newFlu);
        return Heroes[PlayerRo];
    }
}                        
                        
Hero Board::buyout(Hero hero1, Hero hero2)
// this is the buy outright action in the hero v hero encounter, calculayes winner
// get money of hero and loyalty of oppenents warrior to calculate probability
// updates game changes(depending on if you win or lose)
{
    
    int k;
    for(k = 0; k < numHeroes; k++)
    {
        if(Heroes[k].getName() == hero2.getName())
        {
            break;
        }
    }
    
    int r;
    int Mons= hero1.getMoney();
    double doubMon = Mons * 1;
    string War = hero2.getWar1();
    for(r = 0; r < numWarriors; r++)
    {
        string check = Warriors[r].getName();
        if(check == War)
        {
            break;
        }
    }
    int WarLoy = Warriors[r].getLoyalty();
    double doubWarLoy = WarLoy * 1;
    
    double prob1 = 1.0 - (doubWarLoy/100);
    double prob2 = doubMon/17800;
    double probFin = prob1 * prob2;
    cout << endl;
    cout << "You have a " << probFin * 100 << " percent chance of succeeding..." << endl;
    cout << endl;
    cout << "Here we go!" << endl;
    cout << endl;
    
    double outta100 = probFin * 100;
    int integer = (int)round(outta100);
    int lifeordeath = rand () % 100;
    if(lifeordeath <= integer)
    {
        Board::otherHeroDeath(Heroes[PlayerRo], Heroes[k]);
        return hero1;
    }
    else
    {
        
        cout << "The money wasn't enough..." << endl;
        cout << "Your money is cut in half" << endl;
        cout << endl;
        int flu = Heroes[PlayerRo].getMoney();
        int newMon = flu / 2;
        Heroes[PlayerRo].setInfluence(newMon);
        return Heroes[PlayerRo];
    }
}                    

Hero Board::battle(Hero hero1, Hero hero2)
// this is the battle action in the hero v hero encounter, calc winner
// get strength of hero and opponent as well as army size of both heros
//updates game changes(depending on if you win or lose)
{
    int k;
    for(k = 0; k < numHeroes; k++)
    {
        if(Heroes[k].getName() == hero2.getName())
        {
            break;
        }
    }
    
    int yourWars = 0;
    int opponentWars = 0;
    int yourStrength;
    int opponentStrength;
    
    if(hero1.getWar1() == "NULL" && hero1.getWar2() == "NULL" && hero1.getWar3() == "NULL" && hero1.getWar4() == "NULL")
    {
        cout << endl;
        cout << "You have no warriors and have backed yourself into a corner" << endl;
        Board::userDeath();
    }
    
    if(hero2.getWar1() == "NULL" && hero2.getWar2() == "NULL" && hero2.getWar3() == "NULL" && hero2.getWar4() == "NULL")
    {
        cout << endl;
        cout << "The other hero has no warriors!" << endl;
        cout << "You automatically win!" << endl;
        Board::otherHeroDeath(Heroes[PlayerRo], Heroes[k]);
    }
    
    if(hero1.getWar1() != "NULL")
    {
        yourWars++;
    }
    
    if(hero1.getWar2() != "NULL")
    {
        yourWars++;
    }
    
    if(hero1.getWar3() != "NULL")
    {
        yourWars++;
    }
    
    if(hero1.getWar4() != "NULL")
    {
        yourWars++;
    }
    
    cout << endl;
    cout << "You have " << yourWars << " warriors" << endl;
    cout << "Choose your favorite!" << endl;
    cout << endl;
    
    
    if(yourWars == 1)
    {
        cout << "Press 1 for " << hero1.getWar1() << endl;
        cout << endl;
    }
    
    if(yourWars == 2)
    {
        cout << "Press 1 for " << hero1.getWar1() << endl;
        cout << "Press 2 for " << hero1.getWar2() << endl;
        
        cout << endl;
    }
    
    if(yourWars == 3)
    {
        cout << "Press 1 for " << hero1.getWar1() << endl;
        cout << "Press 2 for " << hero1.getWar2() << endl;
        cout << "Press 3 for " << hero1.getWar3() << endl;
        
        cout << endl;
    }
    
    if(yourWars == 4)
    {
        cout << "Press 1 for " << hero1.getWar1() << endl;
        cout << "Press 2 for " << hero1.getWar2() << endl;
        cout << "Press 3 for " << hero1.getWar3() << endl;
        cout << "Press 4 for " << hero1.getWar4() << endl;
        
        cout << endl;
    }
    
    int warChoice;
    cin >> warChoice;
    
    if(warChoice > yourWars || warChoice < 0)
    {
        cout << endl;
        cout << "Invalid entry" << endl;
        cout << "Just enter the number" << endl;
        cin >> warChoice;
    }
    
    if(warChoice == 1)
    {
        string name = hero1.getWar1();
        cout << "You have chosen " << hero1.getWar1();
        cout << endl;
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        yourStrength = Warriors[u].getStrength();
    }
    
    if(warChoice == 2)
    {
        string name = hero1.getWar2();
        cout << "You have chosen " << hero1.getWar2();
        cout << endl;
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        yourStrength = Warriors[u].getStrength();
    }
    
    if(warChoice == 3)
    {
        string name = hero1.getWar3();
        cout << "You have chosen " << hero1.getWar3();
        cout << endl;
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        yourStrength = Warriors[u].getStrength();
    }
    
    if(warChoice == 4)
    {
        string name = hero1.getWar4();
        cout << "You have chosen " << hero1.getWar4();
        cout << endl;
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        yourStrength = Warriors[u].getStrength();
    }
    
    //how many warriors does oponent have?
    if(hero2.getWar1() != "NULL")
    {
        opponentWars++;
    }
    if(hero2.getWar2() != "NULL")
    {
        opponentWars++;
    }
    if(hero2.getWar3() != "NULL")
    {
        opponentWars++;
    }
    if(hero2.getWar4() != "NULL")
    {
        opponentWars++;
    }
    
    int oppChoice = rand() % opponentWars;
    if(oppChoice == 0)
    {
        oppChoice++;
    }
    
    if(oppChoice == 1)
    {
        string name = hero2.getWar1();
        cout << "Opponent chooses " << name << endl; 
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        opponentStrength = Warriors[u].getStrength();
    }
    if(oppChoice == 2)
    {
        string name = hero2.getWar2();
        cout << "Opponent chooses " << name << endl; 
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        opponentStrength = Warriors[u].getStrength();
    }
    if(oppChoice == 3)
    {
        string name = hero2.getWar3();
        cout << "Opponent chooses " << name << endl; 
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        opponentStrength = Warriors[u].getStrength();
    }
    if(oppChoice == 4)
    {
        string name = hero2.getWar4();
        cout << "Opponent chooses " << name << endl; 
        
        int u;
        for(u = 0; u < numWarriors; u++)
        {
            string compare = Warriors[u].getName();
            if(compare == name)
            {
                break;
            }
        }
        opponentStrength = Warriors[u].getStrength();
    }
    
    int yourArm = hero1.getArmSize();
    int oppArm = hero2.getArmSize();
    
    int yourCalc = yourArm * yourStrength;
    int oppCalc = oppArm * opponentStrength;
    
    if(yourCalc > oppCalc)
    {
        Board::otherHeroDeath(Heroes[PlayerRo], Heroes[k]);
        return hero1;
    }
    
    if(oppCalc > yourCalc)
    {
        Board::userDeath();
    }
    
    if(yourCalc == oppCalc)
    {
        //hmmmmm
    }
    
}                

void Board::encounter(Hero hero1, Hero Ro2)
//this function runs the hero vs hero encounter 
//ask hero what they want to do(speech, buy, battle) and call that function
//operates as the hub of main hero encounters
{
    int k;
    for(k = 0; k < numHeroes; k++)
    {
        if(Heroes[k].getName() == Ro2.getName())
        {
            break;
        }
    }
    cout << "You have encountered " << Ro2.getName() << endl;
    cout << "How should we handle this?" << endl;
    cout << endl;
    cout << "Do we talk our way out (speech), try to buy them outright (buy) or fight? (battle)" << endl;
    string answer;
    cin  >> answer;
    
    if(answer == "speech")
    {
        Board::speech(Heroes[PlayerRo],Heroes[k]);
    }
    if(answer == "buy")
    {
        Board::buyout(Heroes[PlayerRo],Heroes[k]);
    }
    if(answer == "battle")
    {
        Board::battle(Heroes[PlayerRo],Heroes[k]);
    }
}


void Board::travel()
//this function changes the coordinates of the hero and updates their values
{
    
    cout << endl;
    int currentRow = Heroes[PlayerRo].getRow();
    int currentCol = Heroes[PlayerRo].getCol();
    cout << "Where do you want to travel?" << endl;
    cout << "N for North, S for South, W for West, E for East" << endl;
    char direction;
    cin >> direction;
    
    if(direction == 'N')
    {   
        
        if(Heroes[PlayerRo].getRow() == 0)
        {
            cout << "Map edge" << endl;
            cout << endl;
            return;
        }
        
        int newRow = currentRow - 1;
        
        if(Map[newRow - 1][currentCol - 1] > 64 && Map[newRow - 1][currentCol - 1] < 91)
        {
            Heroes[PlayerRo].setRow(newRow);
            Board::heroHitsCity(Heroes[PlayerRo]);
            return;
        }
        
        if(Heroes[PlayerRo].getBoat() == true)
        {
            if(Map[newRow - 1][currentCol - 1] == '*')
            {
                Heroes[PlayerRo].setMoney(20);
                Heroes[PlayerRo].setArmSize(10);
                Heroes[PlayerRo].setPoints(2);
            }
            else if(Map[newRow - 1][currentCol - 1] == '~')
            {
                Heroes[PlayerRo].setMoney(10);
                Heroes[PlayerRo].setPoints(1);
            }
            Heroes[PlayerRo].setRow(newRow);
            cout << "You move one tile North" << endl;
            cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
            return;
        }
        else if(Map[newRow - 1][currentCol - 1] != '~')
        {
              Heroes[PlayerRo].setMoney(20);
              Heroes[PlayerRo].setArmSize(10);
              Heroes[PlayerRo].setPoints(2);
              
              Heroes[PlayerRo].setRow(newRow);
              cout << endl;
              cout << "You move one tile North" << endl;
              cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
              cout << endl;
              return;
        }
        cout << "There's water ahead, and you're boatless" << endl;
        
    }
    
    if(direction == 'S')
    {
        if(Heroes[PlayerRo].getRow() == 24)
        {
            cout << "Map edge" << endl;
            cout << endl;
            return;
        }
        
        int newRow = currentRow + 1;
        
      
        if(Map[newRow - 1][currentCol - 1] > 64 && Map[newRow - 1][currentCol - 1] < 91)
        {
            Heroes[PlayerRo].setRow(newRow);
            Board::heroHitsCity(Heroes[PlayerRo]);
            return;
        }
       
        if(Heroes[PlayerRo].getBoat() == true)
        {
            if(Map[newRow - 1][currentCol - 1] == '*')
            {
                Heroes[PlayerRo].setMoney(20);
                Heroes[PlayerRo].setArmSize(10);
                Heroes[PlayerRo].setPoints(2);
            }
            else if(Map[newRow - 1][currentCol - 1] == '~')
            {
                Heroes[PlayerRo].setMoney(10);
                Heroes[PlayerRo].setPoints(1);
            }
            Heroes[PlayerRo].setRow(newRow);
            cout << "You move one tile South" << endl;
            cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
            return;
        }
        else if(Map[newRow - 1][currentCol - 1] != '~')
        {
              Heroes[PlayerRo].setMoney(20);
              Heroes[PlayerRo].setArmSize(10);
              Heroes[PlayerRo].setPoints(2);
              
              Heroes[PlayerRo].setRow(newRow);
              cout << endl;
              cout << "You move one tile South" << endl;
              cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
              cout << endl;
              return;
        }
        cout << "There's water ahead, and you're boatless" << endl;
    }
    
    if(direction == 'E')
    {
        if(Heroes[PlayerRo].getCol() == 16)
        {
            cout << "Map edge" << endl;
            cout << endl;
            return;
        }
        
        int newCol = currentCol + 1;
        
        if(Map[currentRow - 1][newCol - 1] > 64 && Map[currentRow - 1][newCol - 1] < 91)
        {
            Heroes[PlayerRo].setCol(newCol);
            Board::heroHitsCity(Heroes[PlayerRo]);
            return;
        }
        
        if(Heroes[PlayerRo].getBoat() == true)
        {
            if(Map[currentRow - 1][newCol - 1] == '*')
            {
                Heroes[PlayerRo].setMoney(20);
                Heroes[PlayerRo].setArmSize(10);
                Heroes[PlayerRo].setPoints(2);
            }
            else if(Map[currentRow - 1][newCol - 1] == '~')
            {
                Heroes[PlayerRo].setMoney(10);
                Heroes[PlayerRo].setPoints(1);
            }
            Heroes[PlayerRo].setCol(newCol);
            cout << "You move one tile East" << endl;
            cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
            return;
        }
        else if(Map[currentRow - 1][newCol - 1] != '~')
        {
              Heroes[PlayerRo].setMoney(20);
              Heroes[PlayerRo].setArmSize(10);
              Heroes[PlayerRo].setPoints(2);
              
              Heroes[PlayerRo].setCol(newCol);
              cout << endl;
              cout << "You move one tile East" << endl;
              cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
              cout << endl;
              return;
        }
        cout << "There's water ahead, and you're boatless" << endl;
    }
    
    if(direction == 'W')
    {
        if(Heroes[PlayerRo].getCol() == 0)
        {
            cout << "Map edge" << endl;
            cout << endl;
            return;
        }
        
        int newCol = currentCol - 1;
        
        
        if(Map[currentRow - 1][newCol - 1] > 64 && Map[currentRow - 1][newCol - 1] < 91)
        {
            Heroes[PlayerRo].setCol(newCol);
            Board::heroHitsCity(Heroes[PlayerRo]);
            return;
        }
       
        if(Heroes[PlayerRo].getBoat() == true)
        {
            if(Map[currentRow - 1][newCol - 1] == '*')
            {
                Heroes[PlayerRo].setMoney(20);
                Heroes[PlayerRo].setArmSize(10);
                Heroes[PlayerRo].setPoints(2);
            }
            else if(Map[currentRow - 1][newCol - 1] == '~')
            {
                Heroes[PlayerRo].setMoney(10);
                Heroes[PlayerRo].setPoints(1);
            }
            Heroes[PlayerRo].setCol(newCol);
            cout << "You move one tile West" << endl;
            cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
            return;
        }
        else if(Map[currentRow - 1][newCol - 1] != '~')
        {
              Heroes[PlayerRo].setMoney(20);
              Heroes[PlayerRo].setArmSize(10);
              Heroes[PlayerRo].setPoints(2);
              
              Heroes[PlayerRo].setCol(newCol);
              cout << endl;
              cout << "You move one tile West" << endl;
              cout << "Your new coordinates are (" << Heroes[PlayerRo].getRow() << "," << Heroes[PlayerRo].getCol() << ")" << endl;
              cout << endl;
              return;
        }
        cout << "There's water ahead, and you're boatless" << endl;
    }
    
}

void Board::rest()
// this function updates the hero's warrior's stats by increasing strength by 1
{
    int count;
    string war1 = Heroes[PlayerRo].getWar1();
    string war2 = Heroes[PlayerRo].getWar2();
    string war3 = Heroes[PlayerRo].getWar3();
    string war4 = Heroes[PlayerRo].getWar4();
    
    for(count = 0; count < numWarriors; count++)
    {
        if(Warriors[count].getName() == war1 || Warriors[count].getName() == war2 || Warriors[count].getName() == war3 || Warriors[count].getName() == war4 )
        {
            Warriors[count].setStrength(1);
            cout << endl;
            cout << Warriors[count].getName() << " increased their strength by 1" << endl;
        }
    }
    cout << endl;
    
}

void Board::consult()
// this function adds 1 to the morale of every warrior the hero owns
{
    int count;
    string war1 = Heroes[PlayerRo].getWar1();
    string war2 = Heroes[PlayerRo].getWar2();
    string war3 = Heroes[PlayerRo].getWar3();
    string war4 = Heroes[PlayerRo].getWar4();
    
    for(count = 0; count < numWarriors; count++)
    {
        if(Warriors[count].getName() == war1 || Warriors[count].getName() == war2 || Warriors[count].getName() == war3 || Warriors[count].getName() == war4 )
        {
            Warriors[count].setMorale(1);
            cout << endl;
            cout << Warriors[count].getName() << " increased their morale by 1" << endl;
        }
    }
    cout << endl;
}

void Board::othersMove()
// this function randomly decides a direction to move every non-user hero and free warrior
// every dirction has a value 1-4, randomly generate a number and send them that way
// as long as they only go on water w/ a boat and dont go off the board
// update all of their stats
{
    cout << "Now everyone else will move" << endl;
    cout << endl;
    cout << "Heroes moving..." << endl;
    cout << endl;
    for(int i = 0; i < numHeroes; i++)
    {
        if(Heroes[i].getDead() == true)
        {
            continue;
        }
        
        if(i == PlayerRo)
        {
            continue;
        }
        
        int currentRow = Heroes[i].getRow();
        int currentCol = Heroes[i].getCol();
        
        int direction = rand() % 3;
        
        if(Heroes[i].getRow() <= 0 && direction == 0)
        {
            direction++;
        }
        
        if(Heroes[i].getRow() >= 24 && direction == 1)
        {
            direction++;
        }
        
        if(Heroes[i].getCol() >= 16 && direction == 2)
        {
            direction++;
        }
        
        if(Heroes[i].getCol() <= 0 && direction == 3)
        {
            direction = 0;
        }
       
        if(direction == 0) // north
        {
            int newRow = currentRow - 1;

            if(Map[newRow - 1][currentCol - 1] == '~' && Heroes[i].getBoat() == false)
            {
                direction++;
            }
            
            if(Heroes[i].getBoat() == true)
            {
                
                Heroes[i].setRow(newRow);
                
                //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
                
                if(Map[newRow - 1][currentCol - 1] == '*')
                {
                    Heroes[i].setPoints(2);
                    Heroes[i].setMoney(20);
                    Heroes[i].setArmSize(10);
                }
                
                else if(Map[newRow - 1][currentCol - 1] == '~')
                {
                    Heroes[i].setPoints(1);
                    Heroes[i].setMoney(10);
                }
                else
                {
                    
                    Board::heroHitsCity(Heroes[i]);
                }
                continue;
            }
            else if(Map[newRow - 1][currentCol - 1] != '~')
            {
              
              if(Map[newRow - 1][currentCol - 1] > 65 && Map[newRow - 1][currentCol - 1] < 91)
              {
                  Heroes[i].setRow(newRow);
                  Board::heroHitsCity(Heroes[i]);
                  continue;
              }
              
              Heroes[i].setRow(newRow);
              Heroes[i].setPoints(2);
              Heroes[i].setMoney(20);
              Heroes[i].setArmSize(10);
              //cout << endl;
              //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
              //cout << endl;
              continue;
            }
    
        }
        if(direction == 1) // south
        {
            
            int newRow = currentRow + 1;
          
            if(Map[newRow - 1][currentCol - 1] == '~' && Heroes[i].getBoat() == false)
            {
                direction++;
            }
            
            if(Heroes[i].getBoat() == true)
            {
                
                Heroes[i].setRow(newRow);
                
                //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
                
                if(Map[newRow - 1][currentCol - 1] == '*')
                {
                    Heroes[i].setPoints(2);
                    Heroes[i].setMoney(20);
                    Heroes[i].setArmSize(10);
                    continue;
                }
                
                else if(Map[newRow - 1][currentCol - 1] == '~')
                {
                    Heroes[i].setPoints(1);
                    Heroes[i].setMoney(10);
                    continue;
                }
                else
                {
                    Board::heroHitsCity(Heroes[i]);
                    continue;
                }
                
            }
            else if(Map[newRow - 1][currentCol - 1] != '~')
            {
              
              if(Map[newRow - 1][currentCol - 1] > 65 && Map[newRow - 1][currentCol - 1] < 91)
              {
                  Heroes[i].setRow(newRow);
                  Board::heroHitsCity(Heroes[i]);
                  continue;
              }
              
              Heroes[i].setRow(newRow);
              Heroes[i].setPoints(2);
              Heroes[i].setMoney(20);
              Heroes[i].setArmSize(10);
              //cout << endl;
              //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
              //cout << endl;
              continue;
            }
        }
        if(direction == 2) // east
        {
            
            int newCol = currentCol + 1;
            
            if(Map[currentRow - 1][newCol - 1] == '~' && Heroes[i].getBoat() == false)
            {
                direction++;
            }
            
            if(Heroes[i].getBoat() == true)
            {
                Heroes[i].setCol(newCol);
                
                //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
                
                if(Map[currentRow - 1][newCol - 1] == '*')
                {
                    
                    Heroes[i].setPoints(2);
                    Heroes[i].setMoney(20);
                    Heroes[i].setArmSize(10);
                    continue;
                }
                
                else if(Map[currentRow - 1][newCol - 1] == '~')
                {
                    Heroes[i].setPoints(1);
                    Heroes[i].setMoney(10);
                    continue;
                }
                else
                {
                    Board::heroHitsCity(Heroes[i]);
                    continue;
                }
                
            }
            else if(Map[currentRow - 1][newCol - 1] != '~')
            {
              
              if(Map[currentRow - 1][newCol - 1] > 65 && Map[currentRow - 1][newCol - 1] < 91)
              {
                  Heroes[i].setCol(newCol);
                  Board::heroHitsCity(Heroes[i]);
              }
              
              Heroes[i].setCol(newCol);
              Heroes[i].setPoints(2);
              Heroes[i].setMoney(20);
              Heroes[i].setArmSize(10);
              //cout << endl;
              //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
              //cout << endl;
              continue;
            }
        }
        
        if(direction == 3) // west
        {
            
            int newCol = currentCol - 1;
            
            if(Map[currentRow - 1][newCol - 1] == '~' && Heroes[i].getBoat() == false)
            {
                direction++;
            }
            
            if(Heroes[i].getBoat() == true)
            {
                Heroes[i].setCol(newCol);
                
                //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
                
                if(Map[currentRow - 1][newCol - 1] == '*')
                {
                    Heroes[i].setPoints(2);
                    Heroes[i].setMoney(20);
                    Heroes[i].setArmSize(10);
                    continue;
                }
                
                else if(Map[currentRow - 1][newCol - 1] == '~')
                {
                    Heroes[i].setPoints(1);
                    Heroes[i].setMoney(10);
                    continue;
                }
                else
                {
                    Board::heroHitsCity(Heroes[i]);
                    continue;
                }
                
            }
            else if(Map[currentRow - 1][newCol - 1] != '~')
            {
              
              if(Map[currentRow - 1][newCol - 1] > 65 && Map[currentRow - 1][newCol - 1] < 91)
              {
                  Heroes[i].setCol(newCol);
                  Board::heroHitsCity(Heroes[i]);
              }
              
              Heroes[i].setCol(newCol);
              Heroes[i].setPoints(2);
              Heroes[i].setMoney(20);
              Heroes[i].setArmSize(10);
              //cout << endl;
              //cout << Heroes[i].getName() << "'s new coordinates are (" << Heroes[i].getRow() << "," << Heroes[i].getCol() << ")" << endl;
              //cout << endl;
              continue;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "Warriors moving..." << endl;
    cout << endl;
    for(int j = 0; j < numWarriors; j++)
    {
        if(Warriors[j].getFree() == true)
        {
            int currentRow = Warriors[j].getRow();
            int currentCol = Warriors[j].getCol();
            
            int direction = rand() % 3;
            
            if(currentRow <= 0 && direction == 0)
            {
                direction++;
            }
            
            if(direction == 0) // north
            {
                if(currentRow <= 0)
                {
                    direction++;
                }
                int newRow = currentRow - 1;
                if(Map[newRow - 1][currentCol - 1] == '~' && Warriors[j].getBoat() == false)
                {
                    direction++;
                }
                
                if(Warriors[j].getBoat() == true)
                {
                    Warriors[j].setRow(newRow);
                    
                    //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                    //cout << endl;
                    continue;
                    
                }
                else if(Map[newRow - 1][currentCol - 1] != '~')
                {
                  Warriors[j].setRow(newRow);
                  //cout << endl;
                  //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                  //cout << endl;
                  continue;
                }
    
            }
            if(currentRow >= 25 && direction == 1)
            {
                direction++;
            }
            
            if(direction == 1) // south
            {
                int newRow = currentRow + 1;
                if(Map[newRow - 1][currentCol - 1] == '~' && Warriors[j].getBoat() == false)
                {
                    direction++;
                }
                
                if(Warriors[j].getBoat() == true)
                {
                    Warriors[j].setRow(newRow);
                    
                    //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                    //cout << endl;
                    continue;
                    
                }
                else if(Map[newRow - 1][currentCol - 1] != '~')
                {
                  Warriors[j].setRow(newRow);
                  //cout << endl;
                  //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                  //cout << endl;
                  continue;
                }
            }
            
            if(currentCol >= 16 && direction == 2)
            {
                direction++;
            }
            
            if(direction == 2) // east
            {
                int newCol = currentCol + 1;
                if(Map[currentRow - 1][newCol - 1] == '~' && Warriors[j].getBoat() == false)
                {
                    direction++;
                }
                
                if(Warriors[j].getBoat() == true)
                {
                    Warriors[j].setCol(newCol);
                    
                    //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                    //cout << endl;
                    continue;
                    
                }
                else if(Map[currentRow - 1][newCol - 1] != '~')
                {
                  Warriors[j].setCol(newCol);
                  //cout << endl;
                  //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                  //cout << endl;
                  continue;
                }
            }    
            if(currentCol <= 0 && direction == 3)
            {
                direction++;
            }
            
            if(direction == 3) // west
            {
                int newCol = currentCol - 1;
                if(Map[currentRow - 1][newCol - 1] == '~' && Warriors[j].getBoat() == false)
                {
                    direction++;
                }
                
                if(Warriors[j].getBoat() == true)
                {
                    Warriors[j].setCol(newCol);
                    
                    //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                    //cout << endl;
                    continue;
                    
                }
                else if(Map[currentRow - 1][newCol - 1] != '~')
                {
                  Warriors[j].setCol(newCol);
                  //cout << endl;
                  //cout << Warriors[j].getName() << "'s new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                  //cout << endl;
                  continue;
                }
            }
            cout << endl;
        }
        
        else
        {
            string mast = Warriors[j].getMaster();
            for(int q = 0; q < numHeroes; q++)
            {
                string matcher = Heroes[q].getName();
                if(matcher == mast)
                {
                    Warriors[j].setRow(Heroes[q].getRow());
                    Warriors[j].setCol(Heroes[q].getCol());
                    //cout << Warriors[j].getName() << " works for " << matcher << endl;
                    //cout << Warriors[j].getName() << "'s " << "new coordinates are (" << Warriors[j].getRow() << "," << Warriors[j].getCol() << ")" << endl;
                    //cout << endl;
                    break;
                }
            }
        }
    }
      
}                

void Board::heroProx()
// this function checks to see if the player is within 2 tiles of another hero. 
//if so, call encounter function and send it the two hero objects that are interacting
{
    for(int i = 0; i < numHeroes; i++)
    {
        if(Heroes[i].getDead() == true)
        {
            continue;
        }
        
        if(i == PlayerRo)
        {
            continue;
        }
        
        int playerRow = Heroes[PlayerRo].getRow();
        int playerCol = Heroes[PlayerRo].getCol();
        
        int compareRow = Heroes[i].getRow();
        int compareCol = Heroes[i].getCol();
        
        if(abs(playerRow - compareRow) <= 2 && abs(playerCol - compareCol) <= 2)
        {
           Board::encounter(Heroes[PlayerRo],Heroes[i]);
        }
    }
}                        
                        
void Board::heroWarProx()
// this function checks to see if a hero is within 2 tiles of any warrior and aquires them
{
    for(int i = 0; i < numWarriors; i++)
    {
        if(Warriors[i].getFree() == false)
        {
            continue;
        }
        string thisGuysName = Warriors[i].getName();
        if(thisGuysName == Heroes[PlayerRo].getWar1() || thisGuysName == Heroes[PlayerRo].getWar2() || thisGuysName == Heroes[PlayerRo].getWar3() || thisGuysName == Heroes[PlayerRo].getWar4())
        {
            continue;
        }
        int playerRow = Heroes[PlayerRo].getRow();
        int playerCol = Heroes[PlayerRo].getCol();
        
        int compareRow = Warriors[i].getRow();
        int compareCol = Warriors[i].getCol();
        
        if(abs(playerRow - compareRow) <= 2 && abs(playerCol - compareCol) <= 2)
        {
           if(Heroes[PlayerRo].getWar1() == "NULL" || Heroes[PlayerRo].getWar2() == "NULL" || Heroes[PlayerRo].getWar3() == "NULL" || Heroes[PlayerRo].getWar4() == "NULL")
           {
               if(Heroes[PlayerRo].getWar1() == "NULL")
               {
                   
                   string name = Warriors[i].getName();
                   Heroes[PlayerRo].setWar1(name);
                   Warriors[i].setMaster(Heroes[PlayerRo].getName());
                   Warriors[i].setFree("no");
                   Warriors[i].setRow(Heroes[PlayerRo].getRow());
                   Warriors[i].setCol(Heroes[PlayerRo].getCol());
                   Warriors[i].setLoyalty(10);
                   Warriors[i].setMorale(10);
                   if(Warriors[i].getBoat() == true)
                   {
                       cout << "You have a boat now thanks to this warrior" << endl;
                       cout << "Now the world is your oyster!" << endl;
                       Heroes[PlayerRo].setBoat("yes");
                   }
                   cout << name << " has joined your team!" << endl;
                   cout << endl;
                   continue;
               }
               
               if(Heroes[PlayerRo].getWar2() == "NULL")
               {
                   string name = Warriors[i].getName();
                   Heroes[PlayerRo].setWar2(name);
                   Warriors[i].setMaster(Heroes[PlayerRo].getName());
                   Warriors[i].setFree("no");
                   Warriors[i].setRow(Heroes[PlayerRo].getRow());
                   Warriors[i].setCol(Heroes[PlayerRo].getCol());
                   Warriors[i].setLoyalty(10);
                   Warriors[i].setMorale(10);
                   if(Warriors[i].getBoat() == true)
                   {
                       cout << "You have a boat now thanks to this warrior" << endl;
                       cout << "Now the world is your oyster!" << endl;
                       Heroes[PlayerRo].setBoat("yes");
                   }
                   cout << name << " has joined your team!" << endl;
                   cout << endl;
                   continue;
               }
               
               if(Heroes[PlayerRo].getWar3() == "NULL")
               {
                   string name = Warriors[i].getName();
                   Heroes[PlayerRo].setWar3(name);
                   Warriors[i].setMaster(Heroes[PlayerRo].getName());
                   Warriors[i].setFree("no");
                   Warriors[i].setRow(Heroes[PlayerRo].getRow());
                   Warriors[i].setCol(Heroes[PlayerRo].getCol());
                   Warriors[i].setLoyalty(10);
                   Warriors[i].setMorale(10);
                   if(Warriors[i].getBoat() == true)
                   {
                       cout << "You have a boat now thanks to this warrior" << endl;
                       cout << "Now the world is your oyster!" << endl;
                       Heroes[PlayerRo].setBoat("yes");
                   }
                   cout << name << " has joined your team!" << endl;
                   cout << endl;
                   continue;
               }
               
               if(Heroes[PlayerRo].getWar4() == "NULL")
               {
                   string name = Warriors[i].getName();
                   Heroes[PlayerRo].setWar4(name);
                   Warriors[i].setMaster(Heroes[PlayerRo].getName());
                   Warriors[i].setFree("no");
                   Warriors[i].setRow(Heroes[PlayerRo].getRow());
                   Warriors[i].setCol(Heroes[PlayerRo].getCol());
                   Warriors[i].setLoyalty(10);
                   Warriors[i].setMorale(10);
                   if(Warriors[i].getBoat() == true)
                   {
                       cout << "You have a boat now thanks to this warrior" << endl;
                       cout << "Now the world is your oyster!" << endl;
                       Heroes[PlayerRo].setBoat("yes");
                   }
                   cout << name << " has joined your team!" << endl;
                   cout << endl;
                   continue;
               }
           }
           else
           {
               cout << "You already have 4 warriors" << endl;
               cout << "Switch one out?" << endl;
               cout << endl;
               cout << "Press 'y' for yes or 'n' for no" << endl; 
               string YorN;
               cin >> YorN;
               
               if(YorN == "n" || YorN == "N")
               {
                   cout << endl;
                   return;
               }
               
               if(YorN == "y" || YorN == "Y")
               {
                   cout << endl;
                   cout << "Press 1 for " << Heroes[PlayerRo].getWar1() << endl;
                   cout << "Press 2 for " << Heroes[PlayerRo].getWar2() << endl;
                   cout << "Press 3 for " << Heroes[PlayerRo].getWar3() << endl;
                   cout << "Press 4 for " << Heroes[PlayerRo].getWar4() << endl;
                   string chooser;
                   cin >> chooser;
                   
                   if(chooser == "1")
                   {
                       string switcher = Heroes[PlayerRo].getWar1();
                       for(int z = 0; z < numWarriors; z++)
                       {
                           string check = Warriors[z].getName();
                           if(check == switcher)
                           {
                               cout << Warriors[z].getName() << " has been set free!" << endl;
                               Warriors[z].setFree("yes");
                               Heroes[PlayerRo].setWar1(Warriors[i].getName());
                               Warriors[i].setFree("no");
                               Warriors[i].setLoyalty(10);
                               Warriors[i].setMorale(10);
                               if(Warriors[i].getBoat() == true)
                               {
                                   cout << "You have a boat now thanks to this warrior" << endl;
                                   cout << "Now the world is your oyster!" << endl;
                                   Heroes[PlayerRo].setBoat("yes");
                               }
                               cout << Warriors[i].getName() << " has joined the team" << endl;
                               cout << endl;
                               continue;
                             
                           }
                       }
                   }
                   
                   if(chooser == "2")
                   {
                       string switcher = Heroes[PlayerRo].getWar2();
                       for(int z = 0; z < numWarriors; z++)
                       {
                           string check = Warriors[z].getName();
                           if(check == switcher)
                           {
                               cout << Warriors[z].getName() << " has been set free!" << endl;
                               Warriors[z].setFree("yes");
                               Heroes[PlayerRo].setWar2(Warriors[i].getName());
                               Warriors[i].setFree("no");
                               Warriors[i].setLoyalty(10);
                               Warriors[i].setMorale(10);
                               if(Warriors[i].getBoat() == true)
                               {
                                   cout << "You have a boat now thanks to this warrior" << endl;
                                   cout << "Now the world is your oyster!" << endl;
                                   Heroes[PlayerRo].setBoat("yes");
                               }
                               cout << Warriors[i].getName() << " has joined the team" << endl;
                               cout << endl;
                               continue;
                             
                           }
                       }
                   }
                   if(chooser == "3")
                   {
                       string switcher = Heroes[PlayerRo].getWar3();
                       for(int z = 0; z < numWarriors; z++)
                       {
                           string check = Warriors[z].getName();
                           if(check == switcher)
                           {
                               cout << Warriors[z].getName() << " has been set free!" << endl;
                               Warriors[z].setFree("yes");
                               Heroes[PlayerRo].setWar3(Warriors[i].getName());
                               Warriors[i].setFree("no");
                               Warriors[i].setLoyalty(10);
                               Warriors[i].setMorale(10);
                               if(Warriors[i].getBoat() == true)
                               {
                                   cout << "You have a boat now thanks to this warrior" << endl;
                                   cout << "Now the world is your oyster!" << endl;
                                   Heroes[PlayerRo].setBoat("yes");
                               }
                               cout << Warriors[i].getName() << " has joined the team" << endl;
                               cout << endl;
                               continue;
                             
                           }
                       }
                   }
                   if(chooser == "4")
                   {
                       string switcher = Heroes[PlayerRo].getWar4();
                       for(int z = 0; z < numWarriors; z++)
                       {
                           string check = Warriors[z].getName();
                           if(check == switcher)
                           {
                               cout << Warriors[z].getName() << " has been set free!" << endl;
                               Warriors[z].setFree("yes");
                               Heroes[PlayerRo].setWar4(Warriors[i].getName());
                               Warriors[i].setFree("no");
                               Warriors[i].setLoyalty(10);
                               Warriors[i].setMorale(10);
                               if(Warriors[i].getBoat() == true)
                               {
                                   cout << "You have a boat now thanks to this warrior" << endl;
                                   cout << "Now the world is your oyster!" << endl;
                                   Heroes[PlayerRo].setBoat("yes");
                               }
                               cout << Warriors[i].getName() << " has joined the team" << endl;
                               cout << endl;
                               continue;
                             
                           }
                       }
                   }
               }
           }
        }
    }
    //other heroes getting warriors
    
    for(int x = 0; x < numHeroes; x++)
    {
        if(Heroes[x].getDead() == true)
        {
            continue;
        }
        
        if(x == PlayerRo)
        {
            continue;
        }
        
        int wars = 0;
        if(Heroes[x].getWar1() != "NULL")
        {
            wars++;
        }
        if(Heroes[x].getWar2() != "NULL")
        {
            wars++;
        }
        if(Heroes[x].getWar3() != "NULL")
        {
            wars++;
        }
        if(Heroes[x].getWar4() != "NULL")
        {
            wars++;
        }
        
        if(wars == 4)
        {
            continue;
        }
        
        int roRow = Heroes[x].getRow();
        int roCol = Heroes[x].getCol();
        
        for(int w = 0; w < numWarriors; w++)
        {
            if(Warriors[w].getFree() == false)
            {
                continue;
            }
            int warRow = Warriors[w].getRow();
            int warCol = Warriors[w].getCol();
            if(abs(roRow - warRow) <= 2 && abs(roCol - warCol) <= 2)
            {
                if(wars < 4)
                {
                    if(wars == 0)
                    {
                       string name = Warriors[w].getName();
                       Heroes[x].setWar1(name);
                       Warriors[w].setMaster(Heroes[x].getName());
                       Warriors[w].setFree("no");
                       Warriors[w].setRow(Heroes[x].getRow());
                       Warriors[w].setCol(Heroes[x].getCol());
                       Warriors[w].setLoyalty(10);
                       Warriors[w].setMorale(10);
                       if(Warriors[w].getBoat() == true)
                       {
                           cout << Heroes[x].getName() << " has a boat now!" << endl;
                           Heroes[x].setBoat("yes");
                       }
                       cout << name << " has joined " << Heroes[x].getName() << "'s team!" << endl;
                       cout << endl;
                       continue;
                    }
                    if(wars == 1)
                    {
                       string name = Warriors[w].getName();
                       Heroes[x].setWar2(name);
                       Warriors[w].setMaster(Heroes[x].getName());
                       Warriors[w].setFree("no");
                       Warriors[w].setRow(Heroes[x].getRow());
                       Warriors[w].setCol(Heroes[x].getCol());
                       Warriors[w].setLoyalty(10);
                       Warriors[w].setMorale(10);
                       if(Warriors[w].getBoat() == true)
                       {
                           cout << Heroes[x].getName() << " has a boat now!" << endl;
                           Heroes[x].setBoat("yes");
                       }
                       cout << name << " has joined " << Heroes[x].getName() << "'s team!" << endl;
                       cout << endl;
                       continue;
                    }
                    if(wars == 2)
                    {
                       string name = Warriors[w].getName();
                       Heroes[x].setWar3(name);
                       Warriors[w].setMaster(Heroes[x].getName());
                       Warriors[w].setFree("no");
                       Warriors[w].setRow(Heroes[x].getRow());
                       Warriors[w].setCol(Heroes[x].getCol());
                       Warriors[w].setLoyalty(10);
                       Warriors[w].setMorale(10);
                       if(Warriors[w].getBoat() == true)
                       {
                           cout << Heroes[x].getName() << " has a boat now!" << endl;
                           Heroes[x].setBoat("yes");
                       }
                       cout << name << " has joined " << Heroes[x].getName() << "'s team!" << endl;
                       cout << endl;
                       continue;
                    }
                    if(wars == 3)
                    {
                       string name = Warriors[w].getName();
                       Heroes[x].setWar4(name);
                       Warriors[w].setMaster(Heroes[x].getName());
                       Warriors[w].setFree("no");
                       Warriors[w].setRow(Heroes[x].getRow());
                       Warriors[w].setCol(Heroes[x].getCol());
                       Warriors[w].setLoyalty(10);
                       Warriors[w].setMorale(10);
                       if(Warriors[w].getBoat() == true)
                       {
                           cout << Heroes[x].getName() << " has a boat now!" << endl;
                           Heroes[x].setBoat("yes");
                       }
                       cout << name << " has joined " << Heroes[x].getName() << "'s team!" << endl;
                       cout << endl;
                       continue;
                    }
                }
            }
        }
    
    }
}

void Board::othersInteract()
//this function automates every other hero v hero encounter and gives them warriors
//takes advantage of heroProx and heroWarProx
{
    for(int mainRo = 0; mainRo < numHeroes; mainRo++)
    {
        if(mainRo == PlayerRo)
        {
            continue;
        }
        
        if(Heroes[mainRo].getDead() == true)
        {
            continue;
        }
        
        for(int compareRo = 0; compareRo < numHeroes; compareRo++)
        {
            if(compareRo == PlayerRo)
            {
                continue;
            }
            
            if(Heroes[compareRo].getDead() == true)
            {
                continue;
            }
            
            if(compareRo == mainRo)
            {
                continue;
            }
            
            int mainRoRow = Heroes[mainRo].getRow();
            int mainRoCol = Heroes[mainRo].getCol();
            
            int compareRoRow = Heroes[compareRo].getRow();
            int compareRoCol = Heroes[compareRo].getCol();
            
            
            if(abs(mainRoRow - compareRoRow) <= 2 && abs(mainRoCol - compareRoCol) <= 2)
            {
                cout << Heroes[mainRo].getName() << " and " << Heroes[compareRo].getName() << " have locked eyes..." << endl;
                
                int mainRoWars = 0;
                int compareRoWars = 0;
                
                if(Heroes[mainRo].getWar1() != "NULL")
                {
                    mainRoWars++;
                }
                
                if(Heroes[mainRo].getWar2() != "NULL")
                {
                    mainRoWars++;
                }
                
                if(Heroes[mainRo].getWar3() != "NULL")
                {
                    mainRoWars++;
                }
                
                if(Heroes[mainRo].getWar4() != "NULL")
                {
                    mainRoWars++;
                }
                
                //second count
                
                if(Heroes[compareRo].getWar1() != "NULL")
                {
                    compareRoWars++;
                }
                
                if(Heroes[compareRo].getWar2() != "NULL")
                {
                    compareRoWars++;
                }
                
                if(Heroes[compareRo].getWar3() != "NULL")
                {
                    compareRoWars++;
                }
                
                if(Heroes[compareRo].getWar4() != "NULL")
                {
                    compareRoWars++;
                }
                
                //scenario where both are warriorless
                if(mainRoWars == 0 && compareRoWars == 0)
                {
                    cout << "Neither of them have a warrior..." << endl;
                    cout << endl;
                    int mainArm = Heroes[mainRo].getArmSize();
                    int compArm = Heroes[compareRo].getArmSize();
                    if(mainArm == 0 && compArm == 0)
                    {
                        Board::soloDeath(Heroes[mainRo]);
                        Board::soloDeath(Heroes[compareRo]);
                        cout << "Both die!" << endl;
                        cout << endl;
                        continue;
                    }
                    else if(mainArm > compArm)
                    {
                        Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                        cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                        continue;
                    }
                    else if(compArm > mainArm)
                    {
                        Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                        cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                        continue;
                    }
                }
                
                //one is warriorless
                else if(mainRoWars > 0 && compareRoWars == 0)
                {
                    cout << Heroes[compareRo].getName() << " has no warriors..." << endl;
                    cout << endl;
                    Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                    
                    continue;
                }
                
                else if(compareRoWars > 0 && mainRoWars == 0)
                {
                    cout << Heroes[mainRo].getName() << " has no warriors..." << endl;
                    cout << endl;
                    Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                    
                    continue;
                }
                
                //both have warriors
                else if(compareRoWars > 0 && mainRoWars > 0)
                {
                    
                    int mainRoChoice;
                    int compareRoChoice;
                    for(int f = 0; f < 10000; f++)
                    {
                        mainRoChoice = rand() % mainRoWars;
                        compareRoChoice = rand() % compareRoWars;
                        if(mainRoChoice > 0 && compareRoChoice > 0)
                        {
                            break;
                        }
                    
                        else if(mainRoChoice == 0 && compareRoChoice == 0)
                        {
                            mainRoChoice++;
                            compareRoChoice++;
                            break;
                        }
                        else if(mainRoChoice == 0)
                        {
                            mainRoChoice++;
                            break;
                        }
                        else if(compareRoChoice == 0)
                        {
                            compareRoChoice++;
                            break;
                        }
                    }
                    
                    if(mainRoChoice == 1 && compareRoChoice == 1)
                    {
                        
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar1() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar1() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar1();
                        string chosenComp = Heroes[compareRo].getWar1();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                        
                    }
                    if(mainRoChoice == 1 && compareRoChoice == 2)
                    {
                        
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar1() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar2() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar1();
                        string chosenComp = Heroes[compareRo].getWar2();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 1 && compareRoChoice == 3)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar1() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar3() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar1();
                        string chosenComp = Heroes[compareRo].getWar3();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 1 && compareRoChoice == 4)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar1() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar4() << endl;
                       
                        string chosenMain = Heroes[mainRo].getWar1();
                        string chosenComp = Heroes[compareRo].getWar4();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 2 && compareRoChoice == 1)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar2() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar1() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar2();
                        string chosenComp = Heroes[compareRo].getWar1();
                        int d;
                        for(int d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(int g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 2 && compareRoChoice == 2)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar2() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar2() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar2();
                        string chosenComp = Heroes[compareRo].getWar2();
                        int d;
                        for(int d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(int g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 2 && compareRoChoice == 3)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar2() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar3() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar2();
                        string chosenComp = Heroes[compareRo].getWar3();
                        int d;
                        for(int d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(int g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 2 && compareRoChoice == 4)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar2() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar4() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar2();
                        string chosenComp = Heroes[compareRo].getWar4();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 3 && compareRoChoice == 1)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar3() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar1() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar3();
                        string chosenComp = Heroes[compareRo].getWar1();
                        int d;
                        for(int d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(int g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 3 && compareRoChoice == 2)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar3() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar2() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar3();
                        string chosenComp = Heroes[compareRo].getWar2();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 3 && compareRoChoice == 3)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar3() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar3() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar3();
                        string chosenComp = Heroes[compareRo].getWar3();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 3 && compareRoChoice == 4)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar3() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar4() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar3();
                        string chosenComp = Heroes[compareRo].getWar4();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 4 && compareRoChoice == 1)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar4() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar1() << endl;
                       
                        string chosenMain = Heroes[mainRo].getWar4();
                        string chosenComp = Heroes[compareRo].getWar1();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 4 && compareRoChoice == 2)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar4() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar2() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar4();
                        string chosenComp = Heroes[compareRo].getWar2();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 4 && compareRoChoice == 3)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar4() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar3() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar4();
                        string chosenComp = Heroes[compareRo].getWar3();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                    if(mainRoChoice == 4 && compareRoChoice == 4)
                    {
                        cout << Heroes[mainRo].getName() << " has chosen " << Heroes[mainRo].getWar4() << endl;
                        cout << Heroes[compareRo].getName() << " has chosen " << Heroes[compareRo].getWar4() << endl;
                        
                        string chosenMain = Heroes[mainRo].getWar4();
                        string chosenComp = Heroes[compareRo].getWar4();
                        int d;
                        for(d = 0; d < numWarriors; d++)
                        {
                            if(Warriors[d].getName() == chosenMain)
                            {
                                break;
                            }
                        }
                        int g;
                        for(int g = 0; g < numWarriors; g++)
                        {
                            if(Warriors[g].getName() == chosenComp)
                            {
                                break;
                            }
                        }
                        
                        int mainStrength = Warriors[d].getStrength();
                        int compStrength = Warriors[g].getStrength();
                        
                        int mainArm = Heroes[mainRo].getArmSize();
                        int compArm = Heroes[compareRo].getArmSize();
                        
                        int mainMult = mainStrength * mainArm;
                        int compMult = compStrength * compArm;
                        
                        if(mainMult > compMult)
                        {
                            
                            
                            cout << Heroes[mainRo].getName() << " has defeated " << Heroes[compareRo].getName() << endl;
                            
                            Board::otherHeroDeath(Heroes[mainRo], Heroes[compareRo]);
                            
                            cout << endl;
                            continue;
                        }
                        else if(compMult > mainMult)
                        {
                            
                            cout << Heroes[compareRo].getName() << " has defeated " << Heroes[mainRo].getName() << endl;
                            Board::otherHeroDeath(Heroes[compareRo], Heroes[mainRo]);
                            cout << endl;
                            continue;
                        }
                    }
                }
            }
        }
    }
}

void Board::turn()
{

    while(turns < 55 || Heroes[PlayerRo].getArmSize() >= 2000 || Heroes[PlayerRo].getPoints() >= 400) // + 50% map control or if you're last alive
    {
        if(turns >= 50)
        {
            cout << endl;
            cout << "White Walkers are close" << endl;
            cout << "Attack them head-on, or run?" << endl;
            cout << "(attack) or (run)" << endl;
            string answer;
            int switcher = 1;
            while(switcher == 1)
            {        
                cin >> answer;
                if(answer == "attack" || answer == "run")
                {
                    switcher = 0;
                    break;
                }
                cout << "Try again, attack or run?" << endl;
                cout << endl;
            }
            
            if(answer == "attack")
            {
                Board::whiteWalk();
            }
            
        }
        // this function dictates everything that needs to happen in a turn
        //1. print map to user - prints 7x7 area around user hero
        cout << "It is your turn" << endl;
        cout << "This is the area around you in a 7x7 square" << endl;
        cout << "If you do not see a full square, you are at the map's edge!" << endl;
        cout << endl;
        Board::printMap();
        cout << endl;
        //2. Asks the user what action they want to take (travel, rest, or consult)
        
        cout << "Do you want to travel, rest, or consult with the gods?" << endl;
        cout << "Type (travel) to travel in a direction, (rest) to rest, or (consult) to consult with the gods " << endl;
        string action;
        cin >> action;
        
        if(action == "travel")
        {
            Board::travel();
        }
        
        if(action == "rest")
        {
            Board::rest();
        }
        
        if(action == "consult")
        {
            Board::consult();
        }
        cout << endl;
        cout << "Enter anything to continue" << endl;
        string fill;
        cin >> fill;
        //3. randomly moves all of the other heros and free warriors
        cout << endl;
        Board::othersMove();
    
        //4. checks proximity of hero. If other hero is within range, call encounter
        Board::heroProx();
        
        //5. check proximity of hero to warriors, add them
        cout << endl;
        Board::heroWarProx();
        cout << "Enter anything to start automated interactions" << endl;
        string fill4;
        cin >> fill4;
        //6. call automatic encounters
        cout << endl;
        Board::othersInteract();
        
        //7. call endTurnRandom for random possibilities at ed of turn
        cout << endl;
        Board::endTurnRandom();
        cout << "Enter anything to start the next turn" << endl;
        string fill6;
        cin >> fill6;
        //8. Update overall values  
        
    }
    
    Board::whiteWalk();

    
}

void Board::endTurnRandom()
//this function randomly calculates if drought, deserters, kindness or jackpot occur after a turn ends.
//updates stats accordingly
//turn++
{
    cout << endl;
    cout << "End of turn" << endl;
    cout << endl;
    int thpercent = rand() % 10;
    if(thpercent <= 3)
    {
        int wapercent = rand() % 100;
        if(wapercent <= 25) // drought
        {
            cout << "There is a drought! Your warrior's morale and strength is weakened" << endl;
            cout << endl;
            if(Heroes[PlayerRo].getWar1() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar1())
                    {
                        Warriors[u].setMorale(-10);
                        Warriors[u].setStrength(-10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar2() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar2())
                    {
                        Warriors[u].setMorale(-10);
                        Warriors[u].setStrength(-10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar3() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar3())
                    {
                        Warriors[u].setMorale(-10);
                        Warriors[u].setStrength(-10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar4() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar4())
                    {
                        Warriors[u].setMorale(-10);
                        Warriors[u].setStrength(-10);
                        break;
                    }
                }
            }
        }
        else if(wapercent > 25 && wapercent <= 50) // deserters
        {
            
            cout << "Your army is abandoning you... Warrior loyalty is weakened" << endl;
            cout << endl;
            Heroes[PlayerRo].setArmSize(-10);
            
            if(Heroes[PlayerRo].getWar1() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar1())
                    {
                        Warriors[u].setLoyalty(-10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar2() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar2())
                    {
                        Warriors[u].setLoyalty(-10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar3() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar3())
                    {
                        Warriors[u].setLoyalty(-10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar4() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar4())
                    {
                        Warriors[u].setLoyalty(-10);
                        break;
                    }
                }
            }
        }
        else if(wapercent > 50 && wapercent <= 75) // jackpot
        {
            cout << "You have won the hearts of benefactors! Money doubles!" << endl;
            cout << endl;
            int mon = Heroes[PlayerRo].getMoney();
            Heroes[PlayerRo].setMoney(mon * 2);
        }
        else if(wapercent > 75)
        {
            cout << "You offer shelter to refugees. Army size increases, and warrior loyalty is strengthened!" << endl;
            cout << endl;
            
            Heroes[PlayerRo].setArmSize(10);
            
            if(Heroes[PlayerRo].getWar1() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar1())
                    {
                        Warriors[u].setLoyalty(10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar2() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar2())
                    {
                        Warriors[u].setLoyalty(10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar3() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar3())
                    {
                        Warriors[u].setLoyalty(10);
                        break;
                    }
                }
            }
            if(Heroes[PlayerRo].getWar4() != "NULL")
            {
                for(int u  = 0; u < numWarriors; u++)
                {
                    if(Warriors[u].getName() == Heroes[PlayerRo].getWar4())
                    {
                        Warriors[u].setLoyalty(-10);
                        break;
                    }
                }
            }
        }
    }
    turns++;
}                        

void Board::whiteWalk()
//this gets called at the very end of a turn if - 1. turn = 50  2. User army size >= 2000  3. User owns 200+ tiles  
//  4. User has 400+ points  5. User is the only hero left
//user can delay this function for 5 turns by saying no
//when they accept, do this nasty probability equation to see if the user wins
{
    cout << "Things are about to get crazy" << endl;
    cout << endl;
    
    int power;
    power = Heroes[PlayerRo].getArmSize();
    cout << "Your power starts at " << Heroes[PlayerRo].getArmSize();
    cout << endl;
    
    int numWars = 0;
    if(Heroes[PlayerRo].getWar1() != "NULL")
    {
        numWars++;
    }
                
    if(Heroes[PlayerRo].getWar2() != "NULL")
    {
        numWars++;
    }
    
    if(Heroes[PlayerRo].getWar3() != "NULL")
    {
        numWars++;
    }
                
    if(Heroes[PlayerRo].getWar4() != "NULL")
    {
        numWars++;
    }
    
    if(numWars == 0)
    {
        cout << "You have no warriors.." << endl;
        cout << endl;
    }
    
    else if(numWars == 1)
    {
        cout << "1 warrior adds to your power" << endl;
        cout << endl;
        string realName = Heroes[PlayerRo].getWar1();
        int z;
        for(int z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName)
            {
                break;
            }
        }
        
        int warS = Warriors[z].getStrength();
        int warM = Warriors[z].getMorale();
        int calc = (warM / 50) * warS;
        power = power + calc;
    }
    
    else if(numWars == 2)
    {
        cout << "2 warriors adds to your power" << endl;
        cout << endl;
        string realName = Heroes[PlayerRo].getWar1();
        int z;
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName)
            {
                break;
            }
        }
        
        int warS = Warriors[z].getStrength();
        int warM = Warriors[z].getMorale();
        int calc = (warM / 50) * warS;
        power = power + calc;
        
        string realName2 = Heroes[PlayerRo].getWar2();
        
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName2)
            {
                break;
            }
        }
        
        int warS2 = Warriors[z].getStrength();
        int warM2 = Warriors[z].getMorale();
        int calc2 = (warM2 / 50) * warS2;
        power = power + calc2;
    }
    
    else if(numWars == 3)
    {
        cout << "3 warriors adds to your power" << endl;
        cout << endl;
        string realName = Heroes[PlayerRo].getWar1();
        int z;
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName)
            {
                break;
            }
        }
        
        int warS = Warriors[z].getStrength();
        int warM = Warriors[z].getMorale();
        int calc = (warM / 50) * warS;
        power = power + calc;
        
        string realName2 = Heroes[PlayerRo].getWar2();
        
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName2)
            {
                break;
            }
        }
        
        int warS2 = Warriors[z].getStrength();
        int warM2 = Warriors[z].getMorale();
        int calc2 = (warM2 / 50) * warS2;
        power = power + calc2;
        
        string realName3 = Heroes[PlayerRo].getWar3();
        
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName3)
            {
                break;
            }
        }
        
        int warS3 = Warriors[z].getStrength();
        int warM3 = Warriors[z].getMorale();
        int calc3 = (warM3 / 50) * warS3;
        power = power + calc3;
        
    }
    
    else if(numWars == 4)
    {
        cout << "3 warriors adds to your power" << endl;
        cout << endl;
        string realName = Heroes[PlayerRo].getWar1();
        int z;
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName)
            {
                break;
            }
        }
        
        int warS = Warriors[z].getStrength();
        int warM = Warriors[z].getMorale();
        int calc = (warM / 50) * warS;
        power = power + calc;
        
        string realName2 = Heroes[PlayerRo].getWar2();
        
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName2)
            {
                break;
            }
        }
        
        int warS2 = Warriors[z].getStrength();
        int warM2 = Warriors[z].getMorale();
        int calc2 = (warM2 / 50) * warS2;
        power = power + calc2;
        
        string realName3 = Heroes[PlayerRo].getWar3();
        
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName3)
            {
                break;
            }
        }
        
        int warS3 = Warriors[z].getStrength();
        int warM3 = Warriors[z].getMorale();
        int calc3 = (warM3 / 50) * warS3;
        power = power + calc3;
        
        string realName4 = Heroes[PlayerRo].getWar4();
        
        for(z = 0; z < numWarriors; z++)
        {
            string match = Warriors[z].getName();
            if(match == realName4)
            {
                break;
            }
        }
        
        int warS4 = Warriors[z].getStrength();
        int warM4 = Warriors[z].getMorale();
        int calc4 = (warM4 / 50) * warS4;
        power = power + calc4;
    }
    
    cout << "Your control of cities also increases your power" << endl;
    cout << endl;
    int yourCities = 0;
    string yourName = Heroes[PlayerRo].getName();
    for(int b = 0; b < numCities; b++)
    {
        string compare = Cities[b].getOwner();
        if(compare == yourName)
        {
            yourCities++;
        }
    }
    
    int citiesValue = yourCities + 1;
    int flu = Heroes[PlayerRo].getInfluence();
    int anothrCalc = (flu / 4) * citiesValue;
    power = power + anothrCalc;
    
    //if hero has DG
    
    cout << "Your total power is " << power << endl;
    cout << endl;
    
    //probability that hero wins
    int probWin = 1 - (exp ((power * -1) / 30000));
    
    //battle loop
    int chances = 0;
    int probUp = probWin * 100;
    
    int spot = rand() % 100;
    if(spot <= probUp)
    {
        Board::userWins();
    }
    
    else
    {
        if(chances == 3)
        {
            Board::userDeath();
        }
        chances++;
    }
    
    
}

void Board::saveResults()
//this function takes all of the data at the end of the game and sends it to an output file
//this file records the hero that the user used, as well as their points
//high score table basically
{
    
}


