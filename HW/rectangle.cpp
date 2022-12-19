/*
Author: Sahel Reja
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E9.5
The program creates the Rectangle class.
*/
class Rectangle {
	private:
		double width;
		double length;
	public:
		Rectangle(double w, double l);
		double get_perimeter();
		double get_area();
		void resize(double factor);
};
Rectangle::Rectangle(double w, double l):width(w),length(l) {}
double Rectangle::get_perimeter() { return 2*width + 2*length; }
double Rectangle::get_area() { return width * length; }
void Rectangle::resize(double factor) { 
	width *= factor;
	length *= factor;
}