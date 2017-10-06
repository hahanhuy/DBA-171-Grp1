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

void PrintList(LinkedList<Term>* list){
	Node<Term> * temp = list->getHead();
	while (temp != NULL){
		cout << temp->data.coefficient << " " << temp->data.exponent << endl;
		temp = temp->next;
	}
}

LinkedList<Term>* addelement(string s){
	LinkedList<Term>* list = new LinkedList<Term>();
	int i = 0;
	char tmp[50];

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
		list->InsertLast(value);
		i = j;
	}
	
	int degree = list->getHead()->data.exponent;
	Node<Term>* monomial = list->getHead();
	for (int i = 0; i < degree + 1; i++){
		int current_expo = monomial->data.exponent;
		if (current_expo != (degree - i)){
			Term temp_monomial;
			temp_monomial.coefficient = 0;
			temp_monomial.exponent = degree - i;
			list->InsertItem(temp_monomial, i);
		}
		else
			monomial = monomial->next;
	}

	PrintList(list);
	return list;
}

int main(){
	string s;
	LinkedList<Term>* list = new LinkedList<Term>();
	//cout << "Enter polynamial: ";
	//cin >> s;

	s = "5.2x^4-3x-4.213123213";
	cout << s << endl << endl;
	list = addelement(s);
	

	system("pause");
    return 0;
}

