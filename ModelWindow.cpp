#include "ModelWindow.h"
#include<iostream>

ModelWindow::ModelWindow(std::string name_window, int x_cord, int y_cord, int width_size, int height_size, std::string color_window, bool is_visible, bool is_with_border)
{
	this->name_window = name_window;
	this->x_cord = x_cord;
	this->y_cord = y_cord;
	this->width_size = width_size;
	this->height_size = height_size;
	this->color_window = color_window;
	this->is_visible = is_visible;
	this->is_with_border = is_with_border;
}

void ModelWindow::move_window_in_X(int move_in_X)
{
	this->x_cord += move_in_X;
	if (x_cord + width_size > 1920)
	{
		std::cout << "Window is crossed with screen edge\n";
		x_cord = 1920 - width_size;
	}
}

void ModelWindow::move_window_in_Y(int move_in_Y)
{
	this->y_cord += move_in_Y;
	if (y_cord + width_size > 1200)
	{
		std::cout << "Window is crossed with screen edge\n";
		y_cord= 1200 - height_size;
	}
}

void ModelWindow::change_window_width(int width)
{
	this->width_size = width;
	if (x_cord + width_size > 1920)
	{
		std::cout << "Window is crossed with screen edge\n";
		width_size = 1920 - x_cord;
	}
}

void ModelWindow::change_window_height(int height)
{
	this->height_size = height;
	if (y_cord + width_size > 1200)
	{
		std::cout << "Window is crossed with screen edge\n";
		height_size = 1200 - y_cord;
	}
}

void ModelWindow::change_window_color(std::string color)
{
	this->color_window = color;
}

void ModelWindow::change_window_conditions(bool is_visible, bool is_with_border)
{
	this->is_visible = is_visible;
	this->is_with_border = is_with_border;
}

std::string ModelWindow::get_name_window()
{
	return name_window;
}

void ModelWindow::get_window_conditions()
{
	if (is_visible)
		std::cout << "Window is visible\n";
	else
		std::cout << "Window is invisible\n";

	if (is_with_border)
		std::cout << "Window is with border\n";
	else
		std::cout << "Window is without border\n";

}


int ModelWindow::get_X_cord()
{
	return x_cord;
}

int ModelWindow::get_Y_cord()
{
	return y_cord;
}

int ModelWindow::get_width_size()
{
	return width_size;
}

int ModelWindow::get_height_size()
{
	return height_size;
}

std::string ModelWindow::get_color_window()
{
	return color_window;
}

bool ModelWindow::is_crossed_with_other_window(ModelWindow other_window)
{
	bool result = false;
	if (this->x_cord <= (other_window.x_cord + other_window.width_size) && other_window.x_cord <= (this->x_cord + this->width_size) &&
		this->y_cord <= (other_window.y_cord + other_window.height_size) && other_window.y_cord <= (this->y_cord + this->height_size))
		result = true;

	return result;
}
