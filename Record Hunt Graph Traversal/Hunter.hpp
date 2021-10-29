#include <vector>
#include <iostream>
#include <vector>
using namespace std;


struct Record
{
	string name;
	string artist;
	float price;
	int rating;
	bool bought;

	Record* left = NULL;
	Record* right = NULL;
	Record* parent;

	Record(string n, string a, float p, int r,bool b) 
	{
        name = n;
        artist = a;
        rating = r;
        price = p;
        bought = b;

    }

};

struct Shop;
struct adjShop
{
    Shop *s;
    int weight;
};


struct Shop
{
		
		Shop() 
		{
	        this->name = "";
	        this->visited = false;
	        this->distance = 0;
	        this ->pred = NULL;
	        treeHead = NULL;
	    }

	    bool visited;
	    string name;
	    int distance;
	    Shop *pred;
	    vector<adjShop> adj;

	    Record* treeHead;
	    
        void printRecordInventory(Shop* present);

        Record* findRec(Shop* inside, string tite);
        void addRecord(string name, string author, float price, int rating);

};

class RecordCity
{

	public:
        
		RecordCity(float budge, int tank)
		{

			budget = budge;
			gas = tank;

		}

        void addEdge(string v1, string v2, int num);
        void addShop(string name);
        void displayEdges();
        
        void setAllUnvisited();
		Shop* travel(Shop* start, Shop* end);
   
        //calculate average stats of cart
        void calcAv(vector<Record*> purchased);
        float getBudget();
        void setBudget(float inputBudge);
        int getGas();
        void setGas(int inputGas);
        vector<Record*> getPurchased();

        vector <Shop*> allShops;
        vector <Record*> purchased;

    private:
        
        float budget;
        int gas;

};
