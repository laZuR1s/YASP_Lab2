#include <iostream>
#include "ModelWindow.h"
#include<Windows.h>


int main_menu();

int main()
{
	SetConsoleOutputCP(1251);

	int choice;

	do {
		choice= main_menu();
		//////////////////////////////////////////////////


	} while (choice!=9);

	std::string name_window1 = "window1";
	int x_cord1 = 20;
	int y_cord1 = 25;
	int width_size1 = 30;
	int height_size1 = 35;
	std::string color_window1 = "white";
	bool is_visible1 = true;
	bool is_with_order1 = false;;
	ModelWindow Window1(name_window1, x_cord1, y_cord1, width_size1, height_size1, color_window1, is_visible1, is_with_order1);
	ModelWindow Window2(name_window1, x_cord1, y_cord1, width_size1, height_size1, color_window1, is_visible1, is_with_order1);

	std::cout << Window1.get_X_cord() << '\n';
	std::cout << Window1.get_Y_cord() << '\n';
	std::cout << Window1.get_width_size() << '\n';
	std::cout << Window1.get_height_size() << '\n';
	std::cout << Window1.get_color_window() << '\n';
	Window1.get_window_conditions();

	std::cout << '\n';

	Window1.move_window_in_X(30);
	Window1.move_window_in_Y(20);
	Window1.change_window_width(300);
	Window1.change_window_height(350);
	Window1.change_window_color("red");
	Window1.change_window_conditions(false, true);

	std::cout << Window1.get_X_cord() << '\n';
	std::cout << Window1.get_Y_cord() << '\n';
	std::cout << Window1.get_width_size() << '\n';
	std::cout << Window1.get_height_size() << '\n';
	std::cout << Window1.get_color_window() << '\n';
	Window1.get_window_conditions();

	if (Window1.is_crossed_with_other_window(Window2))
		std::cout << "Crossed";
	else
		std::cout << "Not crossed";

	std::cout << '\n';




}

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message)
{
	std::cout << message << "\n>>> ";
	while (!(std::cin >> x && condition(x)))
	{
		std::cout << "Îøèáêà ââîäà!" << '\n';
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << message << "\n>>> ";
	}
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
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "9. Выход\n";
	std::cout << "-----------------------------------------------------\n";
	int choice;
	std::cin >> choice;

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}
