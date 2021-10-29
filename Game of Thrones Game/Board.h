#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <fstream>
#include "land.cpp"
#include "hero.cpp"
#include "warrior.cpp"
#include "city.cpp"
using namespace std;

//header file for biggest baddest function on the project

class Board //keeps track of pretty much everything
{
    public:
    
    Board(); // default constructor
    
    int matcher(string warName);
    void intBoard(string mapFile, string cityFile);
    void readHeros(string heroFile);
    void readWarriors(string warriorFile);
    void peopleToMap();
    void startUp();
    void userDeath();
    Hero soloDeath(Hero badguy);
    Hero otherHeroDeath(Hero winner, Hero loser);
    void userWins();
    void printMap();
    Hero heroHitsCity(Hero hitter);
    void heroHitsDG();
    Hero speech(Hero hero1, Hero hero2);
    Hero buyout(Hero hero1, Hero hero2);
    Hero battle(Hero hero1, Hero hero2);
    void encounter(Hero Ro1, Hero Ro2);
    void travel();
    void rest();
    void consult();
    void othersMove();
    void heroProx();
    void heroWarProx();
    void othersInteract();
    void turn();
    void endTurnRandom();
    void whiteWalk();
    void saveResults();
    
    private:
    
    int turns;
    City Cities[26];
    char Map[25][16];
    int numCities;
    int numHeroes;
    int numWarriors;
    Land Tiles[25][16];
    Hero Heroes[7];
    Warrior Warriors[14];
    int PlayerRo;
};

