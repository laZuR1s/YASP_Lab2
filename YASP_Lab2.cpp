#include <iostream>
#include "ModelWindow.h"
#include<Windows.h>

int main_menu();
int input_menu();
int output_menu();
int check_file(std::ifstream& file);


template<typename T> 
T validated_input();
int main()
{
	SetConsoleOutputCP(1251);

	int choice;
	int option_choice;
	ModelWindow Window1;
	ModelWindow Window2;


	do {
		choice = main_menu();
		switch (choice)
		{
		case 1:
			option_choice = input_menu();
			if (option_choice == 1)
			{
				std::string file_name;
				std::cout << "\nВведите имя файла: ";
				file_name = validated_input<std::string>();
				std::ifstream file(file_name);

				switch (check_file(file))
				{
				case -1:
					std::cout << "Некорректное имя фала\n";
					break;
				case 0:
					std::cout << "Пустой файл\n";
					break;
				default:
					Window1.fill(file);
					std::cout << "\nДанные получены\n";

				}
			}
			else
			{
				Window1.fill(std::cin);
				std::cout << "\nДанные получены\n";
			}
			break;
		case 2:
			option_choice = input_menu();
			if (option_choice == 1)
			{
				std::string file_name;
				std::cout << "\nВведите имя файла: ";
				file_name = validated_input<std::string>();
				std::ifstream file(file_name);
				switch (check_file(file))
				{
				case -1:
					std::cout << "Некорректное имя фала\n";
					break;
				case 0:
					std::cout << "Пустой файл\n";
					break;
				default:
					Window2.fill(file);
					std::cout << "\nДанные получены\n";
				}
			}
			else
			{
				Window2.fill(std::cin);
			}
			break;
		case 3:
			std::cout << "\nВведите на сколько вы ходите сдвинуть окно по Х: ";
			int x;
			x = validated_input<int>();
			Window1.move_window_in_X(x);
			break;
		case 4:
			std::cout << "\nВведите на сколько вы ходите сдвинуть окно по Y: ";
			int y;
			y = validated_input<int>();
			Window1.move_window_in_Y(y);
			break;
		case 5:
			std::cout << "\nВведите новую ширину окна: ";
			int width;
			std::cin >> width;
			Window1.change_window_width(width);
			break;
		case 6:
			std::cout << "\nВведите новую высоту окна: ";
			int heigth;
			heigth = validated_input<int>();
			Window1.change_window_height(heigth);
			break;
		case 7:
		{
			std::cout << "\n Введите новый цвет окна: ";
			std::string color;
			color = validated_input <std::string>();
			Window1.change_window_color(color);
		}
		break;
		case 8:
			Window1.get_window_conditions();
			break;
		case 9:
			option_choice = output_menu();
			if (option_choice == 1)
			{
				std::string file_name;
				std::cout << "\nВведите имя файла: ";
				file_name = validated_input<std::string>();
				std::ofstream file(file_name);
				
					std::cout << '\n';
					Window1.print(file);
			}
			else
			{
				std::cout << '\n';
				Window1.print(std::cout);

			}
			break;
		case 10:
			std::cout << '\n' << Window1.to_string() << '\n';
			break;
		case 11:
			if (Window1.is_crossed_with_other_window(Window2))
				std::cout << "\nCrossed\n";
			else
				std::cout << "\nNot crossed\n";
			break;

		case 12:
			if (Window1 > Window2)
				std::cout << "\nWindow1 > Window2\n";
			if (Window1 < Window2)
				std::cout << "\nWindow1 < Window2\n";
			if (Window1 == Window2)
				std::cout << "\nWindow1 == Window2\n";
			break;
		}


	} while (choice != 13);

}

template<typename T>
T validated_input() {
	T data;

	while (true) {
		std::cin >> data;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Ошибка ввода!\n";
		}
		else {
			return data;
		}
	}
}


int input_menu()
{
	std::cout << "\n\nВыбор формата ввода\n";
	std::cout << "1. Заполнить из файла\n";
	std::cout << "2. Заполнить с клавиатуры\n";
	int choice;
	do {
		std::cout << "\nВведите пункт меню: ";
		choice = validated_input<int>();
	} while (!(choice >= 0 && choice <= 2));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}

int output_menu()
{
	std::cout << "\n\nВыбор формата\n";
	std::cout << "1. Вывод в файл\n";
	std::cout << "2. Вывод в консоль\n";
	int choice;
	do {
		std::cout << "\nВведите пункт меню: ";
		choice = validated_input<int>();
	} while (!(choice >= 0 && choice <= 2));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}

int check_file(std::ifstream& file)
{
	int res = 1;
	if (!file)
	{
		res = -1; 
	}
	else
		if (file.peek() == EOF)
			res = 0; 
	return res;
}

int main_menu()
{
	std::cout << "\n\n\nМеню\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Заполнить ModelWindow1\n";
	std::cout << "2. Заполнить ModelWindow2\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "ИЗМЕНИТЬ ModelWindow1\n";
	std::cout << "3. Изменить координату X\n";
	std::cout << "4. Изменить координату Y\n";
	std::cout << "5. Изменить ширину окна\n";
	std::cout << "6. Изменить высоту окна\n";
	std::cout << "7. Изменить цвет окна\n";
	std::cout << "8. Изменить состояния окна\n";
	std::cout << "9. Вывести информацию об окне 1\n";
	std::cout << "10. Вывести информацию об окне 1 в виде строки\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "11. Проверить пересечение окна 1 и окна 2\n";
	std::cout << "12. Сравнить размеры окна 1 и окна 2\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "13. Выход\n";
	std::cout << "-----------------------------------------------------\n"; \
		int choice;
	do {
		std::cout << "\nВведите пункт меню: ";
		choice = validated_input<int>();
	} while (!(choice >= 0 && choice <= 13));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}
