#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	
	// allocate memory of int sie an int pointer
	int* ptr = (int*) malloc(4);
	
	//assign the value 5 to allocated memory
	*ptr = 5;

	cout << *ptr;

	return 0;
}
