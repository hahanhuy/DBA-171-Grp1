// Polynamial.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "LinkedList.h"

using namespace std;

struct Term
{
	double coefficient;
	int exponent;

};

Node<double>* ConvertToLinkedList(double arr[], int size) {
	Node<double> *head, *pCur, *pPre;
	head = new Node<double>{ arr[0], NULL };
	pPre = head;
	for (int i = 1; i < size; i++) {
		pCur = new Node<double>{ arr[i], NULL };
		pPre->next = pCur;
		pPre = pCur;
	}
	return head;
}

class Polynomial {
private:
	LinkedList<Term> *list;

public:
	Polynomial() {
		list = new LinkedList<Term>;
	}
	void create(string s);
	void print();
	Polynomial* add(Polynomial* P);
	Polynomial* sub(Polynomial* P);
	Polynomial* mul(Polynomial* P);
	LinkedList<Term>* getValue();
};

LinkedList<Term>* Polynomial::getValue() {
	return this->list;
}

void Polynomial::create(string s) {
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
		if (tmp[0] == '+' && tmp[1] == 'x'){
			value.coefficient = 1;
			iss >> x >> x >> x;
			if (iss.eof())
				value.exponent = 1;
			else
				iss >> value.exponent;
		}
		else{
			if (tmp[0] == 'x'){
				value.coefficient = 1;
				iss >> x >> x;
				if (iss.eof())
					value.exponent = 1;
				else
					iss >> value.exponent;
			}
			else{
				iss >> value.coefficient;
				if (iss.eof())
					value.exponent = 0;
				else {
					iss >> x >> x;
					if (iss.eof())
						value.exponent = 1;
					else
						iss >> value.exponent;
				}
			}
		}
		
		//cout << value.coefficient << " " << value.exponent << endl<< endl;
		iss.clear();
		list->InsertLast(value);
		i = j;
	}

	int degree = list->getHead()->data.exponent;
	Node<Term>* monomial = list->getHead();
	for (int i = 0; i < degree + 1; i++) {
		if (monomial == NULL) {
			Term temp_monomial;
			temp_monomial.coefficient = 0;
			temp_monomial.exponent = degree - i;
			list->InsertItem(temp_monomial, i);
		}
		else {
			int current_expo = monomial->data.exponent;
			if (current_expo != (degree - i)) {
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

void Polynomial::print() {
	Node<Term> * temp = list->getHead();
	while (true) {
		double coefficient = temp->data.coefficient;
		int exponent = temp->data.exponent;

		if (temp == list->getHead()){
			if (coefficient == 1)
				cout << "x^" << exponent;
			else
				cout << coefficient << "x^" << exponent;
			temp = temp->next;
			continue;
		}

		if (temp->next == NULL){
			if (coefficient > 0)
				cout << "+"; 
			cout << coefficient << endl;
			break;
		}

		if (coefficient == 0){
			temp = temp->next;
			continue;
		}
		
		if (coefficient > 0)
			cout << "+";
		
		if (coefficient == 1)
			cout << "x^" << exponent;
		else
			cout << coefficient << "x^" << exponent;		
		temp = temp->next;
	}
}

Polynomial* Polynomial::add(Polynomial* P) {
	Polynomial* result = new Polynomial();
	int thisdegree = this->list->getHead()->data.exponent;
	int thatdegree = P->list->getHead()->data.exponent;
	int length = ((thisdegree > thatdegree) ? thisdegree : thatdegree) + 1;
	Node<Term> *node1, *node2;
	node1 = this->list->getHead();
	node2 = P->list->getHead();

	for (int i = 0; i < length; i++) {
		Term temp;
		int expo1 = node1->data.exponent;
		int expo2 = node2->data.exponent;

		if (expo1 > expo2) {
			temp.coefficient = node1->data.coefficient;
			temp.exponent = node1->data.exponent;
			node1 = node1->next;
		}
		else {
			if (expo2 > expo1) {
				temp.coefficient = node2->data.coefficient;
				temp.exponent = node2->data.exponent;
				node2 = node2->next;
			}
			else {
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

Polynomial* Polynomial::sub(Polynomial* P) {
	Polynomial* result = new Polynomial();
	int thisdegree = this->list->getHead()->data.exponent;
	int thatdegree = P->list->getHead()->data.exponent;
	int length = ((thisdegree > thatdegree) ? thisdegree : thatdegree) + 1;
	Node<Term> *node1, *node2;
	node1 = this->list->getHead();
	node2 = P->list->getHead();

	for (int i = 0; i < length; i++) {
		Term temp;
		int expo1 = node1->data.exponent;
		int expo2 = node2->data.exponent;

		if (expo1 > expo2) {
			temp.coefficient = node1->data.coefficient;
			temp.exponent = node1->data.exponent;
			node1 = node1->next;
		}
		else {
			if (expo2 > expo1) {
				temp.coefficient = -node2->data.coefficient;
				temp.exponent = node2->data.exponent;
				node2 = node2->next;
			}
			else {
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

Polynomial* Polynomial::mul(Polynomial* P) {
	if (this->list->getHead() == NULL || P->getValue()->getHead() == NULL) {
		cout << "Polynomial is empty" << endl;
		return NULL;
	}

	Polynomial *res = new Polynomial();
	Node<Term> *firstTmp, *secondTmp;
	//Node<Term> *cur, *pre;
	double firstArr[100] = {};
	double secondArr[100] = {};
	double resultArr[100] = {};
	int firstSize = 0;
	int secondSize = 0;

	firstTmp = this->list->getHead();
	secondTmp = P->getValue()->getHead();

	// convert 2 linked lists to 2 arrays
	cout << "First poly: " << endl;
	while (firstTmp) {
		firstArr[firstSize] = firstTmp->data.coefficient;		
		cout << firstTmp->data.coefficient << " ";
		firstTmp = firstTmp->next;
		firstSize++;
	}
	cout << endl;

	cout << "Second poly: " << endl;
	while (secondTmp) {
		secondArr[secondSize] = secondTmp->data.coefficient;
		cout << secondTmp->data.coefficient << " ";
		secondTmp = secondTmp->next;
		secondSize++;
	}
	cout << endl;

	// write output to array
	int resultSize = firstSize + secondSize - 1;
	for (int i = 0; i < secondSize; i++) {
		for (int j = 0; j < firstSize; j++) {
			resultArr[i + j] += secondArr[i] * firstArr[j];
		}
	}

	//cout << "Result poly: " << endl;
	for (int i = 0; i < resultSize; i++) {
		Term newTerm;
		newTerm.coefficient = resultArr[i];
		//cout << resultArr[i] << " ";
		newTerm.exponent = resultSize - 1 - i;
		//cout << resultSize - 1 - i << endl;
		res->getValue()->InsertLast(newTerm);
	}
	cout << endl;

	return res;
}

int main() {
	const int NUM_POLY = 20;
	string s;
	string option;
	int polyListSize = 0;

	Polynomial* polyList[NUM_POLY];

	// input polynomial
	do {
		cout << "Enter polynamial (a1x^n1+a2x^n2+...): ";
		getline(cin, s);

		Polynomial *newPoly = new Polynomial();

		// cannot allocate memory
		if (newPoly == NULL) {
			cout << "Memory is full!" << endl;
			system("pause");
			return -1;
		}

		newPoly->create(s);
		polyList[polyListSize] = newPoly;
		polyList[polyListSize]->print();
		polyListSize++;

		do {
			cout << "Do you want to continue (y/n): ";
			getline(cin, option);
		} while (option != "y" && option != "n");

	} while (option != "n");
	
	cout << "Stop input polynomial." << endl;

	// calculate
	do {
		char c;
		string expr[3];
		int i = 0;
		string tmp;
		istringstream iss(s);
		int leftIdx = 0, rightIdx = 0;
		double xValue = 0;
		cout << "Perform math operations: (Pi add\\sub\\mul\\div Pj || Pj cal n)" << endl;
		getline(cin, s);

		// split string and store to expr
		iss.str(s);
		while (getline(iss, tmp, ' ')) expr[i++] = tmp;
		iss.clear();

		// get left index
		iss.str(expr[0]);
		iss >> c >> leftIdx;
		iss.clear();
		if (leftIdx - 1 < 0 || leftIdx - 1 >= polyListSize) {
			cout << "Index is out of bound" << endl;
			continue;
		}

		// code for cal
		// leftIdx - 1, rightIdx - 1 store the index of polynomial in polyList
		// xValue store the value of x for 'cal'
		if (expr[1] == "cal") {

			// get value of x
			iss.str(expr[2]);
			iss >> xValue;
			iss.clear();

			// cal here
		}
		// code for other operations
		else {
			// get right index
			iss.str(expr[2]);
			iss >> c >> rightIdx;
			iss.clear();
			if (rightIdx - 1 < 0 || rightIdx - 1 >= polyListSize) {
				cout << "Index is out of bound" << endl;
				continue;
			}
			if (expr[1] == "add") {
				// add here
			}
			else if (expr[1] == "sub") {
				// sub here
			}
			else if (expr[1] == "mul") {
				Polynomial *res = new Polynomial();
				cout << leftIdx - 1 << " " << expr[1] << " " << rightIdx - 1 << endl;
				res = polyList[leftIdx - 1]->mul(polyList[rightIdx - 1]);
				res->print();
			}
			else if (expr[1] == "div") {
				// div here
			}
			else {
				cout << "Error operator" << endl;
				continue;
			}
		}

		do {
			cout << "Do you want to continue (y/n): ";
			getline(cin, option);
		} while (option != "y" && option != "n");
	} while (option != "n");

	//string s2 = "x^3+x^2+4";
	//Polynomial *p1 = new Polynomial();
	//p1->create(s2);
	////p1->print();
	////cout << endl;
	//s2 = "x^4+x^2+7";
	//Polynomial *p2 = new Polynomial();
	//p2->create(s2);
	////p2->print();
	////cout << endl;
	//Polynomial *res = new Polynomial();
	//res = p1->mul(p2);
	//res->print();
	//cout << "P1: ";
	//p1->print();


	system("pause");
	return 0;
}

