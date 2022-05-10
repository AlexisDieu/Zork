#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "World.h"

using namespace std;

int main()
{
	//variable to create the world and allow input reading
	string input;
	World world;

    cout << "Welcome in the Zork universe \n";
    cout << "-------------------------------- \n";


    cout << "Where you want to go ? \n";

    cout << " ? \n";

	while (1)
	{
		if (_kbhit() != 0)
		{
				cin >> input;
				if (input.compare("leave") == 0) 
				{
					cout << "Do you want to leave the game ? yes/no \n";
					cin >> input;
					if (input.compare("yes") == 0) 
					{
						return 0;
					}

				}
				else
				world.GameCommand(input); //check the input wanted
				input = "";
		}
	}
	return 0;





}