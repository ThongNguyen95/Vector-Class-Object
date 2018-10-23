#include<cmath>
#include"vector.h"
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR {

	const double Rad_to_deg = 57.2957795130823;
	//Private methods

	//Calculate x and y from magnitude and angle
	void Vector::set_x() {
		x = mag * cos(ang);
	}
	void Vector::set_y() {
		y = mag * sin(ang);
	}

	//Calculate magnitude and angle from x and y
	void Vector::set_mag() {
		mag = sqrt(x*x + y*y);
	}
	void Vector::set_ang() {
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else {
			ang = atan2(y, x);
		}
	}

	//Constructors & Destructor
	Vector::Vector() {
		x = y = mag = ang = 0;
		mode = 'r';
	}

	Vector::Vector(double n1, double n2, char form) {
		mode = form;
		if (form == 'r') {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		} else if (form == 'p') {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- "
				<< "vector set to 0\n";
			x = y = ang = mag = 0;
			mode = 'r';
		}
	}

	Vector::~Vector() {}
	
	//Member Functions
	void Vector::set(double n1, double n2, char form) {
		mode = form;
		if (form == 'r') {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		} else if (form == 'p') {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- "
				<< "vector set to 0\n";
			x = y = ang = mag = 0;
			mode = 'r';
		}
	}
	void Vector::polar_mode() {
		mode = 'p';
	}
	void Vector::rect_mode() {
		mode = 'r';
	}

	//Operators Overloading
	//Add 2 vectors
	const Vector Vector::operator+(const Vector & b) const {
		return Vector(x + b.x, y + b.y);
	}
	//Subtract 2 Vectors
	const Vector Vector::operator-(const Vector & b) const {
		return Vector(x - b.x, y - b.y);
	}
	//reverse sign of vector
	const Vector Vector::operator-() const {
		return Vector(-x, -y);
	}
	//Multiply a vector by n
	const Vector Vector::operator*(const double n) const {
		return Vector(x * n, y * n);
	}

	//Friend Functions
	//Multiply n by a Vector b
	Vector operator*(const double n, const Vector & b) {
		return b * n;
	}
	//Display the vector based on its mode ('r':rectangular or 'p':polar coordinate)
	std::ostream & operator<<(std::ostream & os, const Vector & a) {
		if (a.mode == 'r') {
			os << "(x,y) = (" << a.x <<","<< a.y << ")";
		}
		else if (a.mode == 'p') {
			os << "(m,a) = (" << a.mag << ","
				<< a.ang << ")";
		}
		else
			os << "Vector object mode is invalid";
	}
}