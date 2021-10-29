#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
#include "hero.h"
using namespace std;

Hero::Hero() //defaults
{
    name = "";
    money = 0;
    influence = 0;
    armySize = 0;
    war1 = "";
    war2 = "";
    war3 = "";
    war4 = "";
    row = 0;
    column = 0;
    boat = false;
    points = 0;
    dead = false;
}

//parameterized
Hero::Hero(string heroName, int heroMoney, int heroInf, int heroArm, string heroW1, string heroW2, string heroW3, string heroW4, int heroRow, int heroCol, bool gills, int points, bool dead)
{
    name = heroName;
    money = heroMoney;
    influence = heroInf;
    armySize = heroArm;
    war1 = heroW1;
    war2 = heroW2;
    war3 = heroW3;
    war4 = heroW4;
    row = heroRow;
    column = heroCol;
    boat = gills;
    points = 0;
    dead = false;
}

string Hero::setName(string heroName)
{
    name = heroName;
}

int Hero::setMoney(int heroMoney)
{
    money = heroMoney;
}

int Hero::setInfluence(int heroInf)
{
    influence = heroInf;
}

int Hero::setArmSize(int heroArm)
{
    armySize = armySize + heroArm;
}

void Hero::setWar1(string heroW1)
{
    war1 = heroW1;
}

void Hero::setWar2(string heroW2)
{
    war2 = heroW2;
}

void Hero::setWar3(string heroW3)
{
    war3 = heroW3;
}

void Hero::setWar4(string heroW4)
{
    war4 = heroW4;
}

int Hero::setRow(int heroRow)
{
    row = heroRow;
}

int Hero::setCol(int heroCol)
{
    column = heroCol;
}

bool Hero::setBoat(string boatBee)
{
    bool TorF;

    if(boatBee == "yes")
    {
        TorF = true;
        boat = TorF;
        return true;
            
    }
    else if(boatBee == "no")
    {
        TorF = false;
        boat = TorF;
        return true;
            
    }

    return false;
}

int Hero::setPoints(int adder)
{
    points = points + adder;
}

void Hero::setDead(string deadboy)
{

    if(deadboy == "yes")
    {
        dead = true;
            
    }
    else if(deadboy == "no")
    {
        dead = false;
            
    }

}

string Hero::getName()
{
    return name;
}

int Hero::getMoney()
{
    return money;    
}

int Hero::getInfluence()
{
    return influence;
}

int Hero::getArmSize()
{
    return armySize;
}

string Hero::getWar1()
{
    return war1;
}

string Hero::getWar2()
{
    return war2;
}

string Hero::getWar3()
{
    return war3;
}

string Hero::getWar4()
{
    return war4;
}

int Hero::getRow()
{
    return row;
}

int Hero::getCol()
{
    return column;
}

bool Hero::getBoat()
{
    return boat;
}

int Hero::getPoints()
{
    return points;
}

bool Hero::getDead()
{
    return dead;
}