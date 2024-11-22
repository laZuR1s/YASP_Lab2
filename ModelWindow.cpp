#include "ModelWindow.h"
#include<iostream>

const int MAX_HEIGHT = 1200;
const int MAX_WIDTH = 1920;

ModelWindow::ModelWindow()
{
	name_window = {};
	x_cord = {};
	y_cord = {};
	width_size = {};
	height_size = {};
	color_window = {};
	is_visible = {};
	is_with_border = {};
}

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

ModelWindow::ModelWindow(std::ifstream& file)
{
	file >> name_window;
	file >> x_cord;
	file >> y_cord;
	file >> width_size;
	file >> height_size;
	file >> color_window;
	file >> is_visible;
	file >> is_with_border;
}

void ModelWindow::fill(std::istream& stream)
{
	stream >> name_window;
	stream >> x_cord;
	stream >> y_cord;
	stream >> width_size;
	stream >> height_size;
	stream >> color_window;
	stream >> is_visible;
	stream >> is_with_border;
}

void ModelWindow::print(std::ostream& stream) const //
{
	stream << name_window << '\n';
	stream << x_cord << '\n';
	stream << y_cord << '\n';
	stream << width_size << '\n';
	stream << height_size << '\n';
	stream << color_window << '\n';
	stream << is_visible << '\n';
	stream << is_with_border << '\n';

}

bool ModelWindow::move_window_in_X(int move_in_X)
{
	bool flag = false;
	this->x_cord += move_in_X;
	if (x_cord < 0)
	{
		this->x_cord = 0;
		flag = true;
	}
	else
		if (x_cord + width_size > MAX_WIDTH) //
		{
			flag = true;//
			x_cord = MAX_WIDTH - width_size;
		}
	
	return flag;
}

bool ModelWindow::move_window_in_Y(int move_in_Y)
{
	bool flag = false;
	this->y_cord += move_in_Y;
	if (y_cord < 0)
	{
		this->y_cord = 0;
		flag = true;
	}
	else
		if (y_cord + height_size > MAX_HEIGHT) //
		{
			flag = true;//
			y_cord = MAX_HEIGHT - height_size;
		}
	return flag;
}

bool ModelWindow::change_window_width(int width)
{
	bool flag = false;
	if (width < 0)
	{
		flag = true;
	}
	else
	{
		this->width_size = width;
		if (x_cord + width_size > MAX_WIDTH)
		{
			flag = true;
			width_size = MAX_WIDTH - x_cord;
		}
	}
	return flag;
}

bool ModelWindow::change_window_height(int height)
{
	bool flag = false;
	if (height < 0)
	{
		flag = true;
	}
	else
	{
		this->height_size = height;
		if (y_cord + height_size > MAX_HEIGHT)
		{
			flag = true;
			height_size = MAX_HEIGHT - y_cord;
		}
	}
	return flag;
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

void ModelWindow::get_window_conditions(std::ostream& stream) const //
{
	if (is_visible)
		stream<< "Window is visible\n";
	else
		stream<< "Window is invisible\n";

	if (is_with_border)
		stream<< "Window is with border\n";
	else
		stream<< "Window is without border\n";

}

std::string ModelWindow::to_string() const //
{
	std::string result = "";
	result += name_window + " ";
	result += std::to_string(x_cord) + " ";
	result += std::to_string(y_cord) + " ";
	result += std::to_string(width_size) + " ";
	result += std::to_string(height_size) + " ";
	result += color_window + " ";
	if (is_visible)
		result += "1 ";
	else
		result += "0 ";
	if (is_with_border)
		result += "1 ";
	else
		result += "0 ";
	return result;
}


int ModelWindow::get_X_cord() const
{
	return x_cord;
}

int ModelWindow::get_Y_cord() const
{
	return y_cord;
}

int ModelWindow::get_width_size() const
{
	return width_size;
}

int ModelWindow::get_height_size() const
{
	return height_size;
}

std::string ModelWindow::get_color_window()
{
	return color_window;
}

bool ModelWindow::is_crossed_with_other_window(ModelWindow other_window) const
{
	bool result = false;
	if (this->x_cord <= (other_window.x_cord + other_window.width_size) && other_window.x_cord <= (this->x_cord + this->width_size) &&
		this->y_cord <= (other_window.y_cord + other_window.height_size) && other_window.y_cord <= (this->y_cord + this->height_size))
		result = true;

	return result;
}





bool operator==(ModelWindow& w1, ModelWindow& w2)
{
	return 	 w1.height_size * w1.width_size == w2.height_size * w2.width_size;
}

bool operator!=(ModelWindow& w1, ModelWindow& w2)
{
	return w1.height_size * w1.width_size != w2.height_size * w2.width_size;
}


