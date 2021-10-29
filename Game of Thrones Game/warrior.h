#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//header for all warrior objects

class Warrior
{
    
    public:
    
    Warrior();
    Warrior(int warRow, int warCol, string nameWar, int warStrength, int warLoy, int warMor, bool freeBee, bool boatBee, bool DGBee);
    
    int setRow(int warRow);
    int setCol(int warCol);
    string setName(string nameWar);
    int setStrength(int warStrength);
    int setLoyalty(int warLoy);
    int setMorale(int warMor);
    bool setFree(string freeBee);
    bool setBoat(string boatBee);
    bool setDG(string DGBee);
    void setMaster(string warMaster);
    
    int getRow();
    int getCol();
    string getName();
    int getStrength();
    int getLoyalty();
    int getMorale();
    bool getFree();
    bool getBoat();
    bool getDG();
    string getMaster();
    
    private:
    
    int row;
    int column;
    string warName;
    int strength;
    int loyalty;
    int morale;
    bool freedom;
    bool ship;
    bool dragonglass;
    string master;
    
};

