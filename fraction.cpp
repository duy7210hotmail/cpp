#include <iostream>

namespace name {
	int add(int& x, int& y) {
		return x + y;
	}
}

void fraction(int& x, int& y);
void divFraction(int& x, int& y);

int main() {

	int a, b;
	a = 10;
	b = 11;

	int x = name::add(a, b);
	std::cout << x << '\n';

	/*-----------------------*/
	//Fraction function call 
	divFraction(a, b);

	return 0;
}

/*-------------------------------------------------------------------*/

void fraction(int& x, int& y) {
	
	char frac {'/'};
	std::cout << "Enter the two Fraction Number: ";
	std::cin >> x >> y;

	std::cout << "You Enter a Fraction: " << x << frac << y <<'\n';
}

void divFraction(int& x, int& y) {
 	
 	char frac {'/'};
 
	std::cout << "Enter the two Fraction Number: ";
 	std::cin >> x >> y;
 	std::cout << "You Enter a Fraction: " << x << frac << y << '\n' ;
	
	std::cout << "Enter the two Fraction Number: ";
	int a, b;
 	std::cin >> a >> b;
 	std::cout << "You Enter a Fraction: " << a << frac << b << '\n';

	std::cout << "the two fractions multiplied: " << x* a << frac << y * b << '\n';
}

