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
	LinkedList<Term> *list = new LinkedList<Term>();
public:
	void create(string s);
	void print();
	Polynomial* add(Polynomial* P);
	Polynomial* sub(Polynomial* P);
};

void Polynomial::create(string s){
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
		if (monomial == NULL){
			Term temp_monomial;
			temp_monomial.coefficient = 0;
			temp_monomial.exponent = degree - i;
			list->InsertItem(temp_monomial, i);
		}
		else{
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

	}
}

void Polynomial::print(){
	Node<Term> * temp = list->getHead();
	while (temp != NULL){
		cout << temp->data.coefficient << " " << temp->data.exponent << endl;
		temp = temp->next;
	}
}

Polynomial* Polynomial::add(Polynomial* P){
	Polynomial* result = new Polynomial();
	int thisdegree = this->list->getHead()->data.exponent;
	int thatdegree = P->list->getHead()->data.exponent;
	int length = ((thisdegree > thatdegree) ? thisdegree : thatdegree) + 1;
	Node<Term> *node1, *node2;
	node1 = this->list->getHead();
	node2 = P->list->getHead();

	for (int i = 0; i < length; i++){
		Term temp;
		int expo1 = node1->data.exponent;
		int expo2 = node2->data.exponent;
		
		if (expo1 > expo2){
			temp.coefficient = node1->data.coefficient;
			temp.exponent = node1->data.exponent;
			node1 = node1->next;
		}
		else{
			if (expo2 > expo1){
				temp.coefficient = node2->data.coefficient;
				temp.exponent = node2->data.exponent;
				node2 = node2->next;
			}
			else{
				temp.coefficient = node1->data.coefficient + node2->data.coefficient;
				temp.exponent = node1->data.exponent;
				node1 = node1->next;
				node2 = node2->next;
			}
		}
		result->list->InsertLast(temp);
	}
	return result;
}

Polynomial* Polynomial::sub(Polynomial* P){
	Polynomial* result = new Polynomial();
	int thisdegree = this->list->getHead()->data.exponent;
	int thatdegree = P->list->getHead()->data.exponent;
	int length = ((thisdegree > thatdegree) ? thisdegree : thatdegree) + 1;
	Node<Term> *node1, *node2;
	node1 = this->list->getHead();
	node2 = P->list->getHead();

	for (int i = 0; i < length; i++){
		Term temp;
		int expo1 = node1->data.exponent;
		int expo2 = node2->data.exponent;

		if (expo1 > expo2){
			temp.coefficient = node1->data.coefficient;
			temp.exponent = node1->data.exponent;
			node1 = node1->next;
		}
		else{
			if (expo2 > expo1){
				temp.coefficient = -node2->data.coefficient;
				temp.exponent = node2->data.exponent;
				node2 = node2->next;
			}
			else{
				temp.coefficient = node1->data.coefficient - node2->data.coefficient;
				temp.exponent = node1->data.exponent;
				node1 = node1->next;
				node2 = node2->next;
			}
		}
		result->list->InsertLast(temp);
	}
	return result;
}

///////////////----------------//////////////////////////
int main(){
	string s;

	//cout << "Enter polynamial: ";
	//cin >> s;

	Polynomial *P1 = new Polynomial();
	Polynomial *P2 = new Polynomial();
	Polynomial *result = new Polynomial();
	

	s = "5.2x^4-3x";
	cout << "poly1: " << s << endl << endl;
	P1->create(s);
	//P1->print();
	s = "5.2x^7-3x-6969";
	cout << "poly2: " << s << endl << endl;
	P2->create(s);
	//P2->print();
	result = P1->add(P2);
	result->print();

	cout << "SUB:\n";

	result = P1->sub(P2);
	result->print();

	system("pause");
    return 0;
}

