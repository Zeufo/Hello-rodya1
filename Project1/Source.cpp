#include<iostream>
#include<cstdlib>
#include<cmath>

double tool = 0;
double tool2 = 0;

void one(double a, double b) {
	if ((b - a) > 0)
	{
		std::cout << "R2 is bigger R1, unacceptable\n";
		return;
	}

	tool = ((a - b) * 2 * 3.14);
	std::cout << tool << std::endl;

}

void two(double c) {
	std::cout << c << "kg" << std::endl;
	double f = c * 2.20462;
	f = std::round(f);
	std::cout << f << "ft" << std::endl;

}

void three(short number) {
	short hundreds, tens, units, summ; //special thanks to radion for remind me that % exist

	hundreds = number / 100;
	tens = (number % 100) / 10;
	units = number % 10;

	summ = hundreds + tens + units;
	std::cout << "summ is\n" << summ << std::endl;

}

void four(int x_cord)
{
	double func_1, func_2;

	func_1 = x_cord * (cos(x_cord) - sin(x_cord));
	func_2 = (1 + x_cord) * (log(1 + x_cord));
	std::cout << "x equal " << func_1 << " in finction 1\n";
	std::cout << "x equal " << func_2 << " in finction 2\n";
}

void tclean()
{

}

int mafin()
{
	short is_running = 0;

	while (is_running != 1)
	{

		short main_choice;

		std::cout << "1.Circle 2.Mass 3.Summ 4.Function 5.i hate ur code how to leave" << std::endl;
		std::cin >> main_choice;

		if (main_choice > 5 || main_choice < 1)
		{
			std::cout << "Hello?\n";
			continue;
		}

		switch (main_choice)
		{
		case 1:
		{
			double Radius_1, Radius_2;

			std::cout << "first num is... \n";
			std::cin >> Radius_1;


			std::cout << "second num is... \n";
			std::cin >> Radius_2;

			one(Radius_1, Radius_2);
			break;
		}

		case 2:
		{
			double kilo_int;
			std::cout << "Enter kilogramms\n";
			std::cin >> kilo_int;
			two(kilo_int);
			break;
		}

		case 3:
		{
			short case3_tool;
			std::cout << "Enter numb\n";
			std::cin >> case3_tool;
			three(case3_tool);
			break;
		}
		case 4:
		{
			short case_4;
			std::cout << "x is...\n";
			std::cin >> case_4;
			four(case_4);
			break;

		}
		case 5:
		{
			std::cout << "hello world\n";
			is_running = 1;
			break;
		}
		}
	}
	return 0;
}