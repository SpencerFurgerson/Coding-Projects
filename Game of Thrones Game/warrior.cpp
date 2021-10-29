#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
#include "warrior.h"
using namespace std;


Warrior::Warrior()
{
    
    row = 0;
    column = 0;
    warName = "";
    strength = 0;
    loyalty = 0;
    morale = 0;
    freedom = false;
    ship = false;
    dragonglass = false;
    
}

Warrior::Warrior(int warRow, int warCol, string nameWar, int warStrength, int warLoy, int warMor, bool freeBee, bool boatBee, bool DGBee)
{
    
    row = warRow;
    column = warCol;
    warName = nameWar;
    strength = warStrength;
    loyalty = warLoy;
    morale = warMor;
    freedom = freeBee;
    ship = boatBee;
    dragonglass = DGBee;
    
}

int Warrior::setRow(int warRow)
{
    row = warRow;
}

int Warrior::setCol(int warCol)
{
    column = warCol;
}

string Warrior::setName(string nameWar)
{
    warName = nameWar;
}

int Warrior::setStrength(int warStrength)
{
    if((strength + warStrength) < 0 )
    {
        return 0;
    }
    
    if((strength + warStrength) > 200 )
    {
        return 0;
    }
    strength = strength + warStrength;
}

int Warrior::setLoyalty(int warLoy)
{
    if((loyalty + warLoy) < 0 )
    {
        return 0;
    }
    
    if((loyalty + warLoy) > 100 )
    {
        return 0;
    }
    loyalty = loyalty + warLoy;
}

int Warrior::setMorale(int warMor)
{
    
    if((morale + warMor) < 0 )
    {
        return 0;
    }
    
    if((morale + warMor) > 100 )
    {
        return 0;
    }
    morale = morale + warMor;
}

bool Warrior::setFree(string freeBee)
{
    bool TorF;

    if(freeBee == "yes")
    {
        TorF = true;
        freedom = TorF;
        return true;
            
    }
    else if(freeBee == "no")
    {
        TorF = false;
        freedom = TorF;
        return true;
            
    }

    return false;
}

bool Warrior::setBoat(string boatBee)
{
    bool TorF;
    if(boatBee != "yes" || boatBee != "no")
    {
        cout << "Invalid entry" << endl;
        return false;
    }
    else
    {
        if(boatBee == "yes")
        {
            TorF = true;
        }
        else
        {
            TorF = false;
        }
    }
    ship = TorF;
}

bool Warrior::setDG(string DGBee)
{
    bool TorF;
    if(DGBee != "yes" || DGBee != "no")
    {
        cout << "Invalid entry" << endl;
        return false;
    }
    else
    {
        if(DGBee == "yes")
        {
            TorF = true;
        }
        else
        {
            TorF = false;
        }
    }
    dragonglass = TorF;
    
}

void Warrior::setMaster(string warMaster)
{
    master = warMaster;
}

int Warrior::getRow()
{
    return row;
}

int Warrior::getCol()
{
    return column;
}

string Warrior::getName()
{
    return warName;
}

int Warrior::getStrength()
{
    return strength;
}

int Warrior::getLoyalty()
{
    return loyalty;
}

int Warrior::getMorale()
{
    return morale;
}

bool Warrior::getFree()
{
    return freedom;
}

bool Warrior::getBoat()
{
    return ship;
}

bool Warrior::getDG()
{
    return dragonglass;
}

string Warrior::getMaster()
{
    return master;
}