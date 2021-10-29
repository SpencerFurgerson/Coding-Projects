#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//header for all land tiles that are NOT cities

class Land
{
    public:
    
    Land(); // default constructor
    Land(int landRow, int landCol, int landPoints, int landMoney, int landArmy); // parameterized constructor
    
    int setRow(int landRow); 
    int setCol(int landCol); 
    int setPoints(int landPoints);
    int setMoney(int landMoney);
    int setArmy(int landArmy);
    int getRow();
    int getCol();
    int getMoney();
    int getPoints();
    int getArmy();
    
    private:
    
    int row;
    int column;
    int money;
    int points;
    int army;
    
};




