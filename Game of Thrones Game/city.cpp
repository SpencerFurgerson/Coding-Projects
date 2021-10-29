#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
#include "city.h"
using namespace std;


City::City()
{
    row = 0;
    column = 0;
    letter = ' ';
    name = "";
    money = 0;
    army = 0;
    points = 0;
    owner = "";
}

City::City(int cityRow, int cityCol, string cityLet, string cityName, int cityMoney, int cityArmy, int cityPoints, string cityOwner)
{
    row = cityRow;
    column = cityCol;
    letter = cityLet;
    name = cityName;
    money = cityMoney;
    army = cityArmy;
    points = cityPoints;
    owner = cityOwner;
}

int City::setRow(int cityRow)
{
    row = cityRow;
}

int City::setCol(int cityCol)
{
    column = cityCol;
}

string City::setLetter(string cityLet)
{
    letter = cityLet;
}

string City::setName(string cityName)
{
    name = cityName;
}

int City::setMoney(int cityMoney)
{
    money = cityMoney;
}

int City::setArmy(int cityArmy)
{
    army = cityArmy;
}

int City::setPoints(int cityPoints)
{
    points = cityPoints;
}

void City::setOwner(string cityOwner)
{
    owner = cityOwner;
}

int City::getRow()
{
    return row;
}

int City::getCol()
{
    return column;
}

string City::getLetter()
{
    return letter;
}

string City::getName()
{
    return name;
}

int City::getMoney()
{
    return money;
}

int City::getArmy()
{
    return army;
}

int City::getPoints()
{
    return points;
}

string City::getOwner()
{
    return owner;
}
