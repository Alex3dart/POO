// POO.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Vector.h"

using namespace std;


int main()
{
	Vector<int> v(8);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;

	v.push_back(value1);
	v.push_back(value2);
	v.push_back(value3);
	v.remove_at(0);

	for(int i=0;i<2;i++)
	{
		try {
				
		}
		catch (std::exception e) {

		}
		cout << "v[" << i << "]=" << v[i] << endl;

	}


	system("pause");

	return 0;
}
