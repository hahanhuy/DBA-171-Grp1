// Polynamial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"

using namespace std;

struct Term
{
	double coefficient;
	int exponent;
};

class Polynamial {
private:
	LinkedList<Term> *value;

};



int main()
{
	string s;
	char tmp[20];
	cout << "Enter polynamial: ";
	cin >> s;
	int i = 0;
	while (s[i] != '\0') {
		int j = i;
		do {
			tmp[j - i] = s[j];
			j++;
		} while (s[j] != '+' && s[j] != '-' && s[j] != '\0');
		tmp[j - i] = '\0';
		string s1(tmp);
		cout << s1 << " ";
		i = j;
	}

	system("pause");
    return 0;
}

