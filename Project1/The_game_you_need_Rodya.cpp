#include<iostream>
#include<string>
#include<random>
#include<conio.h> //to not use cout or cin. used to no stop programm running
#include<windows.h> //special for sleep();

short Main_menu(char Main_menu_choice) //the first funcnrion appears
{
	system("cls");
	Main_menu_choice = '0';

	while (Main_menu_choice != '1' && Main_menu_choice != '2' && Main_menu_choice != '3')
	{
		std::cout << "1.Play 2.Rules 3.Exit\n";
		std::cin.get(Main_menu_choice);
		std::cin.ignore(100,'\n');
		system("cls");
	}
	return  Main_menu_choice;
} 

short interFace() //the second
{
	int Square_size = 0;
	std::random_device rfms; //Random For map Size = rfms
	std::mt19937 gen(rfms()); //Firstrly i wanted to make random size for withd and leght, but sicnec
	std::uniform_int_distribution<>distrib(0, 6);//i dont know enough will stop at square

	Square_size = distrib(gen);

	return Square_size;//too bad arrays must be created with int alredy known, so ill use it for Ox and Oy
}

void interface_draw(short Ox, short Oy, short coin_1, short coin_2, short count)
{
	const int width = 7, lenght = 7;

	short array[width][lenght] = { 0 };

	if((coin_1 != 0 || coin_2 != 0) && !(coin_1 == Oy && coin_2 == Ox))
	{
		array[coin_1][coin_2] = 9;
	}

	array[Oy][Ox] = 1;
	std::cout << std::endl;
	
	std::cout << "\033[37;40m";
	std::cout << "_______________" << std::endl;

	for (int i = 0; i != 7; i++) {
		std::cout << '|';
		for (int y = 0; y != 7; y++) {
			
			

			if(array[i][y] == 9)
			{
				std::cout << "\033[31;40m";// for red 30m for black 31 for red
				std::cout << array[i][y] << ' ';
				std::cout << "\033[37;40m"; //for green 32m

			} else if(array[i][y] == 1)
				{
					std::cout << "\033[32;40m";// for red 30m for black 31 for red
					std::cout << array[i][y] << ' ';
					std::cout << "\033[37;40m"; //for green 32m

				} else if ((y == 7 && i == 7) || i == 7 || y == 7)
					{
						std::cout << "\033[37;40m";
						std::cout << '0';
					} else std::cout << array[i][y] << ' ';
				
		}
		std::cout << '|';
		std::cout << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\033[37;40m";
	std::cout << std::endl << "Moves count >> " << count;
}

short get_button(char button)
{
	short what_to_return = 0;

	switch (button) {
	case 'd': {
		what_to_return = 4;break;
	}
	case 'a': {
		what_to_return = 2; break;
	}
	case 'w': {
		what_to_return = 1; break;
	}
	case 's': {
		what_to_return = 3; break;
	}
	}

	return what_to_return;
}

int main() 
{
	system("color 0F");
	char ch;
	bool is_running = true;
	short is_running_int = 1;
	short check = 1;
	char main_operation = '1';
	short moves_count = 0;

	short coin = 0, coin1 = 0, player_Ox = 0, player_Oy = 0;
	short main_menu = 0;
	char one = 's';

	while(main_menu ==  0)
	{
		one = Main_menu(main_operation);
		switch(one)
		{
			case '1':
			{
				main_menu = 1; break;
			}
			case '2':
			{
				std::cout << "1 symbol is you, 9 symbol is your goal\nPress W =UP S =DOWN D =right A =left\n";
				std::cout << "Be careful to not cross map wall or game will crush. good luck!\np.s YOU MUST USE ENGLISH layout\npress any key to continue"; 
				std::cin.get(ch); break;
			}
			case '3':
			{
				is_running_int = 0, main_menu = 1; break;
			}
		}
	
	}

	if (one == '1'){
		
		while (is_running_int == 1)
		{
			check = 1;
			is_running = true;

			while (check == 1)
			{
				 coin = interFace();
				 coin1 = interFace();
				 player_Ox = interFace();
				 player_Oy = interFace();
				if((player_Ox != coin1 && player_Oy != coin))
					check = 0;
			}
			
			system("cls");
			interface_draw(player_Ox, player_Oy, coin, coin1, moves_count);

			while (is_running) {
				short get_key = 0;
				short button = 0;

				while (get_key != 1)
				{
					ch = ' ';
					if (_kbhit())
						ch = _getch();
					if (ch != ' ')
						get_key = 1;
				}

				button = get_button(ch);
				moves_count++;

				switch (button)
				{
				case(1):
				{
					player_Oy--; break;
				}
				case(2):
				{
					player_Ox--; break;
				}
				case(3):
				{
					player_Oy++; break;
				}
				case(4):
				{
					player_Ox++; break;
				}
				}

				if (player_Oy > 6) //work 
					player_Oy--;

				if (player_Ox > 6)//not
					player_Ox--;

				if (player_Oy < 0)
					player_Oy++;

				if (player_Ox < 0) //work
					player_Ox++;
				
				if ((player_Oy == coin && player_Ox == coin1))
				{
					coin = 0;
					coin1 = 0;
				}

				system("cls");
				interface_draw(player_Ox, player_Oy, coin, coin1, moves_count);

				if(coin == 0 && coin1 == 0)
				{
					 coin = 0, coin1 = 0, player_Ox = 0, player_Oy = 0;
					is_running = false;
				}
			}
		}

	}
	return 0;
}
