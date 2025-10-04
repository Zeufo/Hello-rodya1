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

    std::cout << "Добро пожаловать в библиотеку!\n";
    std::cout << "Убедительная просьба, учтите, что при выборе автора или чего-либо необходимо вводить ТОЧНОЕ название\n";
    std::cout << "Буковка в буковку. Да, не очень удобно, но мы работаем над этим. Спасибо\n";

    while (main_while != 1)
    {
        short Main_choice = 0;
        short onemore = 2;

        while (onemore != 1)
        {
            std::cout << "Выберите действие\n1.Открыть каталог\n2.Добавить автора\n3.Редактировать\n4.Выход\n";
            std::cin >> Main_choice;
            bool Main_check = std::cin.fail();

            if (Main_check == true)
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Убедительная просьба, следуйте инструкциям!\n";
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
            std::ifstream aut_list("Авторы.txt");

            if (!aut_list.is_open())
            {
                std::cout << "Не удалось открыть список, возможно список пуст\n";
                break;
            }

            std::cout << "Список доступных авторов:\n";
            std::string case1 = "";

            while (aut_list >> case1)
            {
                std::cout << case1 << std::endl;
            }

            short check = 2;
            std::cout << "Хотите посмотреть доступные произведения? 1.Нет 2.Да\n";
            std::cin >> check;

            while (check != 1)
            {
                std::cout << "Выберите автора для просмотра произведений\n";
                std::string case1_choice;
                std::cin >> case1_choice;
                std::string case1_after_choice = case1_choice + ".txt";

                std::ifstream c1w(case1_after_choice);
                if (!c1w.is_open())
                {
                    std::cout << "Не удалось открыть нужный файл,возможно библиотека пуста\n";
                    continue;
                }

                std::cout << "Доступные произведения автора:\n";
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
            std::ofstream aut_list("Авторы.txt", std::ofstream::app);
            std::string case2;

            std::cout << "Введите автора:\n";
            std::cin >> case2;
            aut_list << case2 << std::endl;

            std::string filename = case2 + ".txt";
            std::ofstream aut(filename);

            if (!aut.is_open() || !aut_list.is_open())
            {
                std::cout << "Не удалось создать файл для записи\n";
                break;
            }

            char case2_while = '2';
            while (case2_while != '1')
            {
                std::cout << "Введите произведение автора без пробелов\n";
                case2 = "";
                std::cin >> case2;
                aut << case2 << std::endl;

                std::cout << "Добавить еще одно произведение? 1.Нет\n";
                std::cin >> case2_while;
            }

            aut.close();
            aut_list.close();
            break;
        }

        case(3):
        {
            short case3 = 5;
            std::cout << "Выберите действие\n1.Удалить автора\n2.Изменить имя автора\n3.Изменить название произведения\n4.Удалить произведение\n";
            std::cin >> case3;

            switch (case3)
            {
            case (1):
            {
                std::ifstream aut("Авторы.txt");
                std::ofstream time("time.txt");

                if (!aut.is_open() || !time.is_open())
                {
                    std::cout << "Не удалось открыть файл\n";
                    break;
                }

                std::cout << "Введите имя автора\n";
                std::cin >> case3_1;
                tool = case3_1 + ".txt";
                std::filesystem::remove(tool);
                std::cout << "Автор удален\n";
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
                std::filesystem::remove("Авторы.txt");
                std::filesystem::rename("time.txt", "Авторы.txt");
                break;
            }

            case(2):
            {
                std::fstream aut("Авторы.txt");
                std::ofstream time("time.txt");

                if (!aut.is_open())
                {
                    std::cout << "Не удалось найти файл с авторами\n";
                    break;
                }

                std::cout << "Введите имя автора\n";
                std::cin >> case3_1;
                tool = case3_1 + ".txt";
                std::string new_name = "";

                std::cout << "Введите новое имя\n";
                std::cin >> new_name;
                std::string new_name1 = new_name + ".txt";
                std::filesystem::rename(tool, new_name1);
                std::cout << "Автор переименован\n";

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
                std::filesystem::remove("Авторы.txt");
                std::filesystem::rename("time.txt", "Авторы.txt");
                break;
            }

            case(3):
            {
                std::string case3_tool;
                std::cout << "Введите автора\n";
                std::cin >> case3_tool;

                std::string auth = case3_tool + ".txt";
                std::fstream aut(auth);
                std::ofstream time("time.txt");

                if (!aut.is_open())
                {
                    std::cout << "Не удалось найти файл с авторами\n";
                    break;
                }

                std::cout << "Введите название которое нужно поменять\n";
                std::cin >> tool;

                std::string case3_tool2;
                std::cout << "Введите новое название\n";
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
                std::cout << "Введите автора\n";
                std::cin >> case3_tool;

                std::string auth = case3_tool + ".txt";
                std::fstream aut(auth);
                std::ofstream time("time.txt");

                if (!aut.is_open())
                {
                    std::cout << "Не удалось найти файл с авторами\n";
                    break;
                }

                std::cout << "Введите произведение для удаления\n";
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