#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "Board.cpp"

int main()
{
    srand(time(NULL));
    Board GoT = Board();
    
    
    GoT.intBoard("map.txt","cities.txt");
    GoT.readHeros("heros.txt");
    GoT.readWarriors("warriors.txt");

    GoT.peopleToMap();
    
    GoT.startUp();
    
    GoT.turn();
    
}