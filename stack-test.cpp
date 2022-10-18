#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
	Stack<int> st1;
	cout<< st1.empty() <<endl;
	cout<< st1.size() <<endl;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	cout<< st1.empty() <<endl;
	cout<< st1.size() <<endl;
	cout<< st1.top() <<endl;
	

	return 0;
}