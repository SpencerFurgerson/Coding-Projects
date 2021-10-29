#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
#include "land.h"
using namespace std;

Land::Land() //default
{
    row = 0;
    column = 0;
    points = 0;
    money = 0;
    army = 0;
}

Land::Land(int landRow, int landCol, int landPoints, int landMoney, int landArmy) //parameterized
{
    row = landRow;
    column = landCol;
    points = landPoints;
    money = landMoney;
    army = landArmy;
}

int Land::setRow(int landRow)
{
    row = landRow;
}

int Land::setCol(int landCol)
{
    column = landCol;
}

int Land::setPoints(int landPoints)
{
    points = landPoints;
}

int Land::setMoney(int landMoney)
{
    money = landMoney;
}

int Land::setArmy(int landArmy)
{
    army = landArmy;
}

int Land::getRow()
{
    return row;
}

int Land::getCol()
{
    return column;
}

int Land::getPoints()
{
    return points;
}

int Land::getMoney()
{
    return money;
}

int Land::getArmy()
{
    return army;
}
