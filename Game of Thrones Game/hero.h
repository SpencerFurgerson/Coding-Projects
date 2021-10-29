#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//class file for all Hero objects

class Hero
{
    public:
    
    Hero(); // default constructor
    Hero(string heroName, int heroMoney, int heroInf, int heroArm, string heroW1, string heroW2, string heroW3, string heroW4, int heroRow, int heroCol, bool gills, int points, bool dead); // parameterized constructor
    
    string setName(string heroName);
    int setMoney(int heroMoney);
    int setInfluence(int heroInf);
    int setArmSize(int heroArm);
    void setWar1(string heroW1);
    void setWar2(string heroW2);
    void setWar3(string heroW3);
    void setWar4(string heroW4);
    int setRow(int heroRow);
    int setCol(int heroCol);
    bool setBoat(string gills);
    int setPoints(int adder);
    void setDead(string dead);
    string getName();
    int getMoney();
    int getInfluence();
    int getArmSize();
    string getWar1();
    string getWar2();
    string getWar3();
    string getWar4();
    int getRow();
    int getCol();
    bool getBoat();
    int getPoints();
    bool getDead();
    
    private:
    
    string name;
    int money;
    int influence;
    int armySize;
    string war1;
    string war2;
    string war3;
    string war4;
    int row;
    int column;
    bool boat;
    int points;
    bool dead;
    
};

