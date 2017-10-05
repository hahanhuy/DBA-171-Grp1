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

class Polynomial {
private:
	LinkedList<Term> *value;

};

void addelement(string s){
	//LinkedList<Term> list;
	int i = 0;
	char tmp[20];
	while (s[i] != '\0') {
		int j = i;
		do {
			tmp[j - i] = s[j];
			j++;
		} while (s[j] != '+' && s[j] != '-' && s[j] != '\0');
		tmp[j - i] = '\0';

		istringstream iss(tmp);
		double coefficient;
		int exponent;
		char x;
		iss >> coefficient;
		if (iss.eof())
			exponent = 0;
		else{
			iss >> x >> x;
			if (iss.eof())
				exponent = 1;
			else
				iss >> exponent;
		}
		cout << coefficient << " " << exponent << endl;
		i = j;
	}

}

int main(){
	string s;
	
	//cout << "Enter polynamial: ";
	//cin >> s;

	s = "5.2x^2-3x-4.213123213";
	addelement(s);


	system("pause");
    return 0;
}

