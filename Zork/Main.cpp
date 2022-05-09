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

    cout << " ? \n";

	while (1)
	{
		if (_kbhit() != 0)
		{
			ch = _getch();
/*			if (ch == '\b') //to delete character
			{
				input.substr(0, input.size() - 1);
				cout << '\b';
				cout << " ";
			}
			*/
			 if (ch != '\r') // allow to write and if return pressed, check de command in the else
			{
				input += ch;
				cout << ch;
				
			}
			 else
			 {
				 cout << "\n";
				 world.GameCommand(input); //check the input wanted
				 input = "";
				 cout << "\n";
			 }

			  if (input.compare("leave")==0) {

				return 0;//leave the console
			 }
		}
	}
	return 0;





}