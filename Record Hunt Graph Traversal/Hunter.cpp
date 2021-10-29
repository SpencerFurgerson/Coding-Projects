#include "hunter.hpp"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void RecordCity::addEdge(string v1, string v2, int num)
{
	int sizzle = allShops.size();

	for(int i = 0; i < sizzle; i++)
	{
        if(allShops[i]->name == v1)
        {
            for(int j = 0; j < sizzle; j++)
            {
                if(allShops[j]->name == v2 && i != j)
                {
                    adjShop road;
                    road.s = allShops[j];
                    road.weight = num;
                    allShops[i]->adj.push_back(road);

                    //another vertex for edge in other direction
                    adjShop road2;
                    road2.s = allShops[i];
                    road2.weight = num;
                    allShops[j]->adj.push_back(road2);
                }
            }
        }
    }
}

void RecordCity::addShop(string n)
{

	bool found = false;
    for(int i = 0; i < allShops.size(); i++)
    {
        if(allShops[i]->name == n)
        {
            found = true;
        }
    }
    if(found == false)
    {
        Shop * newOne = new Shop;
        newOne->name = n;
        allShops.push_back(newOne);
    }

}

void RecordCity::displayEdges()
{

	int sizzle = allShops.size();

	for(int i = 0; i < sizzle; i++)
	{
		cout << allShops[i]->name << " --> ";
		int adjsize = allShops[i]->adj.size();
		for(int j = 0; j < adjsize; j++)
		{
			Shop* current = allShops[i]->adj[j].s;
			cout << current->name << " ";
		}
		cout << endl;
	}

}


void RecordCity::setAllUnvisited()
{

	int shopCount = allShops.size();
	for(int j = 0; j< shopCount; j++)
	{
		allShops[j]->visited = false;
	}

}
       
Shop* RecordCity::travel(Shop* start, Shop* end)
{
	
	cout << start->name << endl;
	cout << end->name << endl;
	cout << endl;
	stack <Shop*> solved;
	Shop* solvedV = NULL;

	int minDist = 0;
	int sizzle = allShops.size();

	int i;
	for(i = 0; i < sizzle; i++ )
    {
        if(allShops[i]->name == start->name)
        {  	
        	break;
        }    
    }

    int j;
    for(j = 0; j < sizzle; j++ )
    {
        if(allShops[j]->name == end->name)
        {    	
        	break;
        }    
    }

	allShops[i]->visited = true;
	solved.push(allShops[i]);
	int solvedSize = solved.size();

	while(allShops[j]->visited == false)
	{

		for(int x = 0; x < solvedSize; x++)
		{
	
			solved.top()->visited = true;
			int ssize = solved.top()->adj.size();

			int currMin = 1000000;
			Shop* temp = solved.top();
			for(int y = 0; y < ssize; y++)
			{
				if(temp->adj[y].s->visited == false)
				{
					int dist = temp->adj[y].weight;

					if(dist<currMin)
					{
						int adjMin = 100000;
						if(temp->pred != NULL)
						{

						    int predAdjSize = temp->pred->adj.size();

    						for(int w = 0; w < predAdjSize; w++)
    						{
    						   Shop* pre = temp->pred->adj[w].s;
    						   if(temp->pred->adj[w].weight < adjMin && pre->visited == false)
    						   {
    						       adjMin = temp->pred->adj[w].weight;
    						   }
    						}  
						}

						
						if(minDist+dist < minDist+adjMin || temp->adj[y].s->name == end->name)
						{
						   
						    currMin = dist;
						
    						solvedV = temp->adj[y].s;
    						solvedV->pred = temp;
        					solved.push(solvedV);
						    
						}
						

					}

				}

			}
			solved.push(solvedV);
			temp = solved.top();

			minDist = minDist + currMin;
			solvedV->distance = minDist - 1000000;

		}
	}

	return solvedV;

}
   
void RecordCity::calcAv(vector<Record*> purchased)
{
	
	float totalRate = 0;
	float avRate;
	int cartSize = purchased.size();
	for(int i = 0; i < cartSize; i++)
	{
		totalRate = totalRate + purchased[i]->rating;
	}

	avRate = totalRate / cartSize;
	cout << "Average rating of cart is: " << avRate << endl;

}

void RecordCity::setBudget(float input)
{
	budget = input;
}


float RecordCity::getBudget()
{
	return budget;
}

void RecordCity::setGas(int inputGas)
{
	gas = inputGas;
}

int RecordCity::getGas()
{
	return gas;
}

void printHelper(Record* currNode)
{
	if(currNode)
    {

        printHelper(currNode->left);
        if(currNode->bought == false)
        {
        	cout << "Record: " << currNode->name << endl;
        	cout << "Artist: " << currNode->artist << ", Rating is: " << currNode->rating << ", Price is: " << currNode->price << endl;
        	cout << endl;
        }

        printHelper(currNode->right);
    }
}

void Shop::printRecordInventory(Shop* present)
{

	if(treeHead == NULL)
	{
		cout << "Shop has no inventory!" << endl;
	}

	printHelper(present->treeHead);

}

Record* createNode(string title, string author, float cost, int rating)
{
    Record* newNode = new Record(title,author,cost,rating,false);
   
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Record* addNodeHelper(Record* currNode, string compTitle, string author, float cost, int rate)
{
	
	if(currNode == NULL)
	{
		//cout << compTitle << "," << author << "," << cost << "," << rate << endl;
		//cout << endl;
		return createNode(compTitle,author,cost,rate);
	}
	
	else if(currNode->name < compTitle)
	{
		currNode->right = addNodeHelper(currNode->right,compTitle,author,cost,rate);
	}
	
	else if(currNode->name > compTitle)
	{
		currNode->left = addNodeHelper(currNode->left,compTitle,author,cost,rate);
	}
	
	return currNode;	
}

void Shop::addRecord(string name, string artist, float price, int rating)
{

	treeHead = addNodeHelper(treeHead,name,artist,price,rating);
}


Record* findHelper(Record* currNode, string compTitle)
{

	if(currNode == NULL)
	{   
        return NULL;
	}

    if(currNode->name == compTitle)
    {
        return currNode;
    }
    if(currNode->name > compTitle)
    {
        return findHelper(currNode->left, compTitle);
    }
  
    return findHelper(currNode->right, compTitle);
    
}

Record* Shop::findRec(Shop* inside, string tite) 
{
	
	if(inside->treeHead == NULL)
    {
    	return NULL;
    }
    
    Record* tree = findHelper(inside->treeHead, tite);
  
    return tree;

}