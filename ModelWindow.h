#include <string>
#include <fstream>

class ModelWindow {
private:
	std::string name_window;
	int x_cord;
	int y_cord;
	int width_size;
	int height_size;
	std::string color_window;
	bool is_visible;
	bool is_with_border;
public:
	ModelWindow();
	ModelWindow(std::string name_window, int x_cord, int y_cord, int width_size, int height_size, std::string color_window, bool is_visible,bool is_with_border);
	ModelWindow(std::ifstream& file);

	void fill(std::istream& stream);
	void print(std::ostream& stream);
	
	void move_window_in_X(int move_in_X);
	void move_window_in_Y(int move_in_Y);
	void change_window_width(int width);
	void change_window_height(int height);
	void change_window_color(std::string color);
	void change_window_conditions(bool is_visible, bool is_with_border);
	
	std::string get_name_window();
	int get_X_cord();
	int get_Y_cord();
	int get_width_size();
	int get_height_size();
	std::string get_color_window();
	void get_window_conditions();
	
	std::string to_string();

	bool is_crossed_with_other_window(ModelWindow other_window);


	friend bool operator == (ModelWindow& w1, ModelWindow& w2);
	std::strong_ordering operator<=>(ModelWindow& w2) {
		return  this->height_size * this->width_size <=> w2.height_size * w2.width_size;
	}

};