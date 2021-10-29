#include "hunter.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{


	//create city and store nodes, connect them with roads(edges)

	//populate each store with 20 records

	cout << "Welcome to - RECORD HUNT!" << endl;
	cout << endl;
	cout << "In this game, you will travel around a city with multiple record stores, looking at their inventory and trying to purchase as many of the best records you can for the cheapest price!" << endl;

	cout << endl;
	cout << "Enter any key to continue" << endl;

	string empty;
	cin >> empty;

	cout << endl;

	float budget;

	cout << "Please enter your budget! (Between $1.00 and $1,000.00) You can include cents!" << endl;

	bool realBudge = false;
	while(realBudge == false)
	{
		cin >> budget;
		if(budget > 1000.00 || budget < 0)
		{
			cout << "Invalid budget! Try again." << endl;
			continue;
		}
		realBudge = true;
	}

	RecordCity Boulder(budget,100);

	Boulder.addShop("Xang's");
	Boulder.addShop("Spin Shop");
	Boulder.addShop("Independent Records");
	Boulder.addShop("Record Palace");
	Boulder.addShop("Alex's Awesome Albums");
	Boulder.addShop("Circles");
	Boulder.addShop("Schwartz Sounds");
	Boulder.addShop("Back Alley Beats");


	//create edges

	Boulder.addEdge("Xang's","Independent Records",4);
	Boulder.addEdge("Xang's","Spin Shop",4);
	Boulder.addEdge("Xang's","Record Palace",5);
	Boulder.addEdge("Independent Record","Record Palace",3);
	Boulder.addEdge("Spin Shop","Circles",6);
	Boulder.addEdge("Record Palace","Circle",7);
	Boulder.addEdge("Record Palace","Alex's Awesome Albums",5);
	Boulder.addEdge("Alex's Awesome Albums","Circles",5);
	Boulder.addEdge("Alex's Awesome Albums","Schwartz Sounds",4);
	Boulder.addEdge("Circles","Schwartz Sounds",4);
	Boulder.addEdge("Schwartz Sounds","Back Alley Beats",3);

	int numStores = Boulder.allShops.size();


	//open record data file

	//populate stores w 20 records each

	ifstream recordfile;
	string file = argv[1];
	recordfile.open(file);

	// Check for failed open file
	if (recordfile.fail()) {cout << "fail"; return -1;} 
	        
	// Hold each line; at this point it is comma separated
	string line; 
	
	int reccount = 0;     

	for(int i = 0; i < numStores; i++)
	{

		for(int j = 0; j < 20; j++)
		{
	      
			while (getline(recordfile, line)) // while loop that checks each line
			{	

		    	istringstream ss(line);
		        
		    	if (line.empty() == false) // as long as the line isn't empty
		    	{

	           		string name;
	           		string artist;
	           		float price;
	           		int rate;

	           		int component = 0;
	           		string temp;
	           		while (getline(ss, temp, ','))
	           		{
	           		
	           			if(component == 0) 
	           			{
		           			artist = temp;
		           			component++;
	           			}
	           			else if(component == 1)
	           			{
		           			name = temp;
		           			component++;
	           			}
	           			else if(component == 2)
	           			{
	           				price = stod(temp);
	           				component++;
	           			
	           			}
	           			else if(component == 3)
	           			{
	           				rate = stoi(temp);
	           			}
	           		}

	           		Boulder.allShops[i]->addRecord(name,artist,price,rate);
	     
	           		reccount++;
	           		break;
		    	}

			}
		}
	}

	int startStore = rand() % numStores + 1;

	cout << endl;
	cout << "You will begin at " << Boulder.allShops[startStore]->name << endl;
	cout << endl;
	//print map
	cout << "Xang's = 1" << endl;
	cout << "Spin Shop = 2" << endl;
	cout << "Independent Records = 3" << endl;
	cout << "Record Palace = 4" << endl;
	cout << "Alex's Awesome Albums = 5" << endl;
	cout << "Circles = 6" << endl;
	cout << "Schwartz Sounds = 7" << endl;
	cout << "Back Alley Beats = 8" << endl;

	cout << "x x x x x x x x x 8" << endl;
	cout << "x x x x x x x x / x" << endl;
	cout << "x x x x x x x / x x" << endl;
	cout << "x x x x x x / x x x" << endl;
	cout << "x x x x x 7 x x x x" << endl;
	cout << "x x x x / x \\ x x x" << endl;
	cout << "x x x / x x x \\ x x" << endl;
	cout << "x x 5 - - - - - 6 x" << endl;
	cout << "x x x \\ x x x / | x" << endl;
	cout << "x x x x \\ x / x | x" << endl;
	cout << "x x x x x 4 x x | x" << endl;
	cout << "x x x x / | x x 2 x" << endl;
	cout << "x x x 3 x | x / x x" << endl;
	cout << "x x x x \\ | / x x x" << endl;
	cout << "x x x x x 1 x x x x" << endl;
	cout << endl;
	cout << endl;


	Shop* currStore = Boulder.allShops[startStore];

	bool TorE;

	int gasCheck = Boulder.getGas();
	float budgeCheck = Boulder.getBudget();

	while(gasCheck > 0 && budgeCheck > 0)
	{
		char decision;
		
		TorE = false;
		while(TorE == false)
		{

			cout << "Travel or Enter? ('T' for travel or 'E' for enter)" << endl;
			char ans;
			cin >> ans;
			cout << endl;


			if(ans == 'T' || ans == 't')
			{


				TorE = true;
				decision = 'T';
			}

			else if(ans == 'E' || ans == 'e')
			{

				TorE = true;
				decision = 'E';
			}

			else
			{
				cout << "Not a valid answer, try again!" << endl;
			}

		}

		if(decision == 'T')
		{
			//traveling
			cout << "Here is a map of the city" << endl;
			//print city

			cout << endl;
			//print map
			cout << "Xang's = 1" << endl;
			cout << "Spin Shop = 2" << endl;
			cout << "Independent Records = 3" << endl;
			cout << "Record Palace = 4" << endl;
			cout << "Alex's Awesome Albums = 5" << endl;
			cout << "Circles = 6" << endl;
			cout << "Schwartz Sounds = 7" << endl;
			cout << "Back Alley Beats = 8" << endl;

			cout << "x x x x x x x x x 8" << endl;
			cout << "x x x x x x x x / x" << endl;
			cout << "x x x x x x x / x x" << endl;
			cout << "x x x x x x / x x x" << endl;
			cout << "x x x x x 7 x x x x" << endl;
			cout << "x x x x / x \\ x x x" << endl;
			cout << "x x x / x x x \\ x x" << endl;
			cout << "x x 5 - - - - - 6 x" << endl;
			cout << "x x x \\ x x x / | x" << endl;
			cout << "x x x x \\ x / x | x" << endl;
			cout << "x x x x x 4 x x | x" << endl;
			cout << "x x x x / | x x 2 x" << endl;
			cout << "x x x 3 x | x / x x" << endl;
			cout << "x x x x \\ | / x x x" << endl;
			cout << "x x x x x 1 x x x x" << endl;
			cout << endl;

			cout << endl;
			bool storeCheck = false;
			
			int destination;
			Shop* newShopper;
			

			cout << "Which store would you like to visit? (Type the number)" << endl;
				
			cin >> destination;

			while(destination > 8 || destination < 0)
			{
				cout << "Type a number between 1 and 8!" << endl;
				cin >> destination;
				cout << endl;
			}
				
			destination--;
			int holder = 0;
			int y;

			for(y = 0; y < destination; y++)
			{
				holder++;
			}

			newShopper = Boulder.allShops[y];
			cout << newShopper->name << endl;

			cout << endl;

			currStore = newShopper;

			cout << "Arrived at: " << currStore->name << endl;
			cout << endl;

		}

		else
		{
			//entering
			float budge = Boulder.getBudget();

			while(budge > 0)
			{

				cout << "INVENTORY of " << currStore->name << ": " << endl;
				cout << endl;

				int i;
				for(i = 0; i < numStores; i++)
				{
					if(Boulder.allShops[i]->name == currStore->name)
					{
						Boulder.allShops[i]->printRecordInventory(Boulder.allShops[i]);
						break;
					}
				}

				cout << "Would you like to buy an album, or leave? ('Buy' or 'Leave')" << endl;
				cout << endl;

				bool valid = false;
				string choice;
				while(valid == false)
				{
					
					cin >> choice;

					if(choice == "Buy" || choice == "buy")
					{

						valid = true;
						cout << "Which Record would you like to buy? (Be exact)"  << endl;
						string alb;

						Record* bought;
						
						bool realRec = false;
						while(realRec == false)
						{
							
							string alb;
							cin >> alb;
							cout << endl;

							//search tree of this shop for proper record
							bought = Boulder.allShops[i]->findRec(Boulder.allShops[i],alb);

							if(bought == NULL)
							{
								cout << "Invalid Record, try again! (Be exact with the title)" << endl;
								continue;
							}

							realRec = true;

						}
						
						float moneyDown = bought->price;
						float currMoney = Boulder.getBudget();
						
						Boulder.setBudget(currMoney - moneyDown);
						cout << "You have " << "$" << Boulder.getBudget() << " left." << endl;

						Boulder.purchased.push_back(bought);
						bought->bought = true;

						cout << "Purchased: " << bought->name << endl;
						budge = Boulder.getBudget();
						cout << endl;

					}

					else if(choice == "Leave" || choice == "leave")
					{

						valid = true;
						cout << "Leaving store" << endl;
						cout << endl;

					}

					else
					{
						cout << "Invalid response! Try again (Buy or Leave)" << endl;
						cout << endl;
					}

				}

				if(choice == "leave" || choice == "Leave")
				{
					break;
				}
			}


		}
		budgeCheck = Boulder.getBudget();
		gasCheck = Boulder.getGas();

	}

	cout << "You are out of gas or money! The hunt has ended!" << endl;
	cout << endl;

	cout << "Calculating final statistics..." << endl;

	int numPurchased = Boulder.purchased.size();

	cout << numPurchased << " records purchased!" << endl;
	cout << endl;

	for(int j = 0; j < numPurchased; j++)
	{
		cout << Boulder.purchased[j]->name << endl;
	}

	cout << endl;

	Boulder.calcAv(Boulder.purchased);
	cout << endl;

	cout << "Thanks for playing!" << endl;

}
