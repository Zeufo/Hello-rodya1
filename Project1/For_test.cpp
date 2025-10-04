#include<iostream>
#include<conio.h>


int main12()
{
	int exit = 1;
	while(exit != 0)
	{
		if (_kbhit()) {
			char ch = _getch();

			if (ch == 'w')
				std::cout << "You pressed W";
			exit = 0;
		}


	
	}



	return 0;
}