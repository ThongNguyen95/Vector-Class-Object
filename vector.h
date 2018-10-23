#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
namespace VECTOR {
	class Vector {
	private:
		double x;
		double y;
		double mag;
		double ang;
		char mode;
		//private methods for setting values
		void set_x();
		void set_y();
		void set_mag();
		void set_ang();
	public:
		Vector();
		Vector(double n1, double n2, char form = 'r');
		~Vector();
		//Member Functions
		void set(double n1, double n2, char form = 'r');
		double get_x() const { return x; }
		double get_y() const { return y; }
		double get_mag() const { return mag; }
		double get_ang() const { return ang; }
		void polar_mode();
		void rect_mode();

		//Operator Overloading
		const Vector operator+(const Vector & b) const;
		const Vector operator-(const Vector & b) const;
		const Vector operator-() const;
		const Vector operator*(double n) const;
		
		//friend functions
		friend Vector operator*(const double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & a);
	};
}
#endif