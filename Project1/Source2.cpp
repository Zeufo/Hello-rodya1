#include <iostream>
#include <filesystem>
#include <fstream> 
#include <string>
#include <locale.h>
#include <windows.h>

int main123()
{
    short main_while = 2;
    std::string case3_1 = "";
    std::string tool;
    std::string while_tool;

    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "����� ���������� � ����������!\n";
    std::cout << "������������ �������, ������, ��� ��� ������ ������ ��� ����-���� ���������� ������� ������ ��������\n";
    std::cout << "������� � �������. ��, �� ����� ������, �� �� �������� ��� ����. �������\n";

    while (main_while != 1)
    {
        short Main_choice = 0;
        short onemore = 2;

        while (onemore != 1)
        {
            std::cout << "�������� ��������\n1.������� �������\n2.�������� ������\n3.�������������\n4.�����\n";
            std::cin >> Main_choice;
            bool Main_check = std::cin.fail();

            if (Main_check == true)
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "������������ �������, �������� �����������!\n";
                Main_check = false;
                Main_choice = 0;
                continue;
            }
            onemore = 1;
        }

        switch (Main_choice)
        {
        case(1):
        {
            std::ifstream aut_list("������.txt");

            if (!aut_list.is_open())
            {
                std::cout << "�� ������� ������� ������, �������� ������ ����\n";
                break;
            }

            std::cout << "������ ��������� �������:\n";
            std::string case1 = "";

            while (aut_list >> case1)
            {
                std::cout << case1 << std::endl;
            }

            short check = 2;
            std::cout << "������ ���������� ��������� ������������? 1.��� 2.��\n";
            std::cin >> check;

            while (check != 1)
            {
                std::cout << "�������� ������ ��� ��������� ������������\n";
                std::string case1_choice;
                std::cin >> case1_choice;
                std::string case1_after_choice = case1_choice + ".txt";

                std::ifstream c1w(case1_after_choice);
                if (!c1w.is_open())
                {
                    std::cout << "�� ������� ������� ������ ����,�������� ���������� �����\n";
                    continue;
                }

                std::cout << "��������� ������������ ������:\n";
                while (c1w >> tool)
                {
                    std::cout << tool << std::endl;
                }

                std::cout << std::endl;
                c1w.close();
                check = 1;
            }
            aut_list.close();
            break;
        }

        case(2):
        {
            std::ofstream aut_list("������.txt", std::ofstream::app);
            std::string case2;

            std::cout << "������� ������:\n";
            std::cin >> case2;
            aut_list << case2 << std::endl;

            std::string filename = case2 + ".txt";
            std::ofstream aut(filename);

            if (!aut.is_open() || !aut_list.is_open())
            {
                std::cout << "�� ������� ������� ���� ��� ������\n";
                break;
            }

            char case2_while = '2';
            while (case2_while != '1')
            {
                std::cout << "������� ������������ ������ ��� ��������\n";
                case2 = "";
                std::cin >> case2;
                aut << case2 << std::endl;

                std::cout << "�������� ��� ���� ������������? 1.���\n";
                std::cin >> case2_while;
            }

            aut.close();
            aut_list.close();
            break;
        }

        case(3):
        {
            short case3 = 5;
            std::cout << "�������� ��������\n1.������� ������\n2.�������� ��� ������\n3.�������� �������� ������������\n4.������� ������������\n";
            std::cin >> case3;

            switch (case3)
            {
            case (1):
            {
                std::ifstream aut("������.txt");
                std::ofstream time("time.txt");

                if (!aut.is_open() || !time.is_open())
                {
                    std::cout << "�� ������� ������� ����\n";
                    break;
                }

                std::cout << "������� ��� ������\n";
                std::cin >> case3_1;
                tool = case3_1 + ".txt";
                std::filesystem::remove(tool);
                std::cout << "����� ������\n";
                tool = case3_1;

                while (aut >> while_tool)
                {
                    if (while_tool == tool)
                    {
                        continue;
                    }
                    time << while_tool << std::endl;
                }

                aut.close();
                time.close();
                std::filesystem::remove("������.txt");
                std::filesystem::rename("time.txt", "������.txt");
                break;
            }

            case(2):
            {
                std::fstream aut("������.txt");
                std::ofstream time("time.txt");

                if (!aut.is_open())
                {
                    std::cout << "�� ������� ����� ���� � ��������\n";
                    break;
                }

                std::cout << "������� ��� ������\n";
                std::cin >> case3_1;
                tool = case3_1 + ".txt";
                std::string new_name = "";

                std::cout << "������� ����� ���\n";
                std::cin >> new_name;
                std::string new_name1 = new_name + ".txt";
                std::filesystem::rename(tool, new_name1);
                std::cout << "����� ������������\n";

                while (aut >> while_tool)
                {
                    if (while_tool == case3_1)
                    {
                        time << new_name << std::endl;
                        continue;
                    }
                    else
                    {
                        time << while_tool << std::endl;
                    }
                }

                aut.close();
                time.close();
                std::filesystem::remove("������.txt");
                std::filesystem::rename("time.txt", "������.txt");
                break;
            }

            case(3):
            {
                std::string case3_tool;
                std::cout << "������� ������\n";
                std::cin >> case3_tool;

                std::string auth = case3_tool + ".txt";
                std::fstream aut(auth);
                std::ofstream time("time.txt");

                if (!aut.is_open())
                {
                    std::cout << "�� ������� ����� ���� � ��������\n";
                    break;
                }

                std::cout << "������� �������� ������� ����� ��������\n";
                std::cin >> tool;

                std::string case3_tool2;
                std::cout << "������� ����� ��������\n";
                std::cin >> case3_tool2;

                while (aut >> while_tool)
                {
                    if (while_tool == tool)
                    {
                        time << case3_tool2 << std::endl;
                        continue;
                    }
                    else
                    {
                        time << while_tool << std::endl;
                    }
                }

                aut.close();
                time.close();
                std::filesystem::remove(auth);
                std::filesystem::rename("time.txt", auth);
                break;
            }

            case(4):
            {
                std::string case3_tool;
                std::cout << "������� ������\n";
                std::cin >> case3_tool;

                std::string auth = case3_tool + ".txt";
                std::fstream aut(auth);
                std::ofstream time("time.txt");

                if (!aut.is_open())
                {
                    std::cout << "�� ������� ����� ���� � ��������\n";
                    break;
                }

                std::cout << "������� ������������ ��� ��������\n";
                std::cin >> tool;

                while (aut >> while_tool)
                {
                    if (while_tool == tool)
                    {
                        continue;
                    }
                    else
                    {
                        time << while_tool << std::endl;
                    }
                }

                aut.close();
                time.close();
                std::filesystem::remove(auth);
                std::filesystem::rename("time.txt", auth);
                break;
            }
            }
            break;
        }

        case(4):
        {
            main_while = 1;
            break;
        }
        }
    }
    return 0;
}