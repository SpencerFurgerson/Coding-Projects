#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//header for all city objcts

class City
{
    public:
    
    City(); // default constructor
    City(int cityRow, int cityCol, string cityLet, string cityName, int cityMoney, int cityArmy, int cityPoints, string cityOwner); // parameterized constructor
    
    int setRow(int cityRow);
    int setCol(int cityCol);
    string setLetter(string cityLet);
    string setName(string cityName); 
    int setMoney(int cityMoney);
    int setArmy(int cityArmy);
    int setPoints(int cityPoints);
    void setOwner(string cityOwner);
    int getRow(); 
    int getCol(); 
    string getLetter();
    string getName();
    int getMoney();
    int getArmy();
    int getPoints();
    string getOwner();
    
    private:
    
    int row;
    int column;
    string letter;
    string name;
    int money;
    int army;
    int points;
    string owner;
    
};

