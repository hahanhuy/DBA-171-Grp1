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

//void PrintList(LinkedList<Term> list){
//	Node<Term> * temp = list.getHead();
//	while (temp != NULL){
//		cout << temp->data.coefficient << " " << temp->data.exponent << endl;
//		temp = temp->next;
//	}
//}

void addelement(string s){
//	LinkedList<Term> list;
	
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
		Term value;
		char x;
		
		iss >> value.coefficient;
		if (iss.eof())
			value.exponent = 0;
		else{
			iss >> x >> x;
			if (iss.eof())
				value.exponent = 1;
			else
				iss >> value.exponent;
		}
		//list.InsertFirst(value);
		cout << value.coefficient << " " << value.exponent << endl;
		i = j;
		
	}
	//PrintList(list);
}

int main(){
	string s;
	LinkedList<Term> list;
	//cout << "Enter polynamial: ";
	//cin >> s;

	s = "5.2x^2-3x-4.213123213";
	addelement(s);
	

	system("pause");
    return 0;
}

