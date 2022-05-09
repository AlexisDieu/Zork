#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "World.h"

using namespace std;

int main()
{
	//variable to create the world and allow input reading
	char ch;
	string input;
	World world;

    cout << "Welcome in the Zork universe \n";
    cout << "-------------------------------- \n";


    cout << "Where you want to go ? \n";

	world.GameCommand("look");

    cout << " ? \n";

	while (1)
	{
		if (_kbhit() != 0)
		{
			ch = _getch();
			 if (ch != '\r') // if press return
			{
				input += ch;
				cout << ch;
			}
			else
				return 0;
		}
	}
	cout << "Goodbye \n";
	return 0;





}