#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
};

struct list {
	node *pHead;
	node *next;
};

//stack
struct stack {
	node *top;
	int count;

	stack(){
		this->top = NULL;
		this->count = 0;
	}
	void push(int data);
	int pop();
	int Top();
	bool isEmpty();
	bool isFull();
	void clear();
	int size();
	void print();
};

struct queue{
	node *front;
	node *rear;
	int count;
	queue(){
		this->front = NULL;
		this->rear = NULL;
		count = 0;
	}
	void enqueue(int data);
	int dequeue();
	int queuefront();
	int queuerear();
	bool isEmpty();
	void clear();
	int size();
	void print();
};

//stack function
void stack::push(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->next = this->top;
	this->top = newNode;
	this->count++;
}

int stack::pop(){
	if (this->isEmpty()){
		cout << "Stack is empty!\n";
		return -999999999;
	}
	else{
		node* delPtr = this->top;
		int dataOut = delPtr->data;
		this->top = delPtr->next;
		delete delPtr;
		delPtr = NULL;
		this->count--;
		return dataOut;
	}
	
}

int stack::Top(){
	if (this->isEmpty()){
		cout << "Stack is empty!\n";
		return -999999999;
	}		
	else
		return this->top->data;
}

bool stack::isEmpty(){
	if (this->count == 0)
		return true;
	else
		return false;
}

void stack::clear(){
	if (this->isEmpty())
		return;
	else{
		while (this->top != NULL){
			node* temp;
			temp = this->top;
			this->top = temp->next;
			delete temp;
		}
		this->count = 0;
		return;
	}
}

int stack::size(){
	return this->count;
}

void stack::print(){
	if (this->isEmpty()){
		cout << "Stack is empty!\n";
		return;
	}
	else{
		node* p = this->top;
		while (p != NULL){
			cout << p->data << endl;
			p = p->next;
		}
		return;
	}
}




//queue function
void queue::enqueue(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;

	if (this->count == 0)
		this->front = newNode;
	else
		this->rear->next = newNode;
	this->rear = newNode;
	this->count++;
}

int queue::dequeue(){
	int outData;
	node* temp = new node();
	temp = this->front;
	outData = temp->data;
	this->front = temp->next;
	delete temp;
	temp = NULL;
	this->count--;
	return outData;
}

int queue::queuefront(){
	return this->front->data;
}

int queue::queuerear(){
	return this->rear->data;
}

bool queue::isEmpty(){
	if (this->count == 0)
		return true;
	else
		return false;
}

void queue::clear(){
	while (this->front != NULL){
		node* temp;
		temp = this->front;
		this->front = temp->next;
		delete temp;
	}
	this->count = 0;
	return;
}
int queue::size(){
	return this->count;
}

void queue::print(){
	if (this->isEmpty()){
		cout << "Queue is empty!\n";
		return;
	}
	else{
		node* p = this->front;
		while (p != NULL){
			cout << p->data << endl;
			p = p->next;
		}
		return;
	}
}
//problem 3
void invertStack(stack& s1){
	int count = s1.size();
	stack s2;
	for (int i = 1; i < count; i++){
		int temp = s1.pop();
		for (int j = 0; j < count - i; j++)
			s2.push(s1.pop());
		s1.push(temp);
		for (int j = 0; j < count - i; j++)
			s1.push(s2.pop());
	}
}

//problem 4
void DecimalToBinary(int n){
	stack binary;
	while (n != 0){
		binary.push(n % 2);
		n = n / 2;
	}
	while (binary.top != NULL){
		cout << binary.pop();
	}
	cout << endl;
}

//problem 5a
queue stackToQueue(stack s){
	queue newQueue;
	stack temp = s;
	invertStack(temp);
	while (temp.top != NULL)
		newQueue.enqueue(temp.pop());
	return newQueue;
}

//problem 5b
stack queueToStack(queue q){
	stack newStack;
	queue temp = q;
	while (temp.front != NULL)
		newStack.push(temp.dequeue());
	invertStack(newStack);
	return newStack;
}

int main(){
	stack stackA;
	stackA.push(1);
	stackA.push(2);
	stackA.push(3);
	stackA.push(4);
	stackA.push(5);

	queue queueB;
	queueB.enqueue(6);
	queueB.enqueue(7);
	queueB.enqueue(8);
	queueB.enqueue(9);
	queueB.enqueue(10);

	//DecimalToBinary(100);

	//queue queueA;
	//queueA = stackToQueue(stackA);

	//queueA.print();
	//cout << endl << queueA.dequeue() << endl << endl;
	//queueA.print();

	//cout << "---------------------------" << endl;
	stack stackB;
	stackB = queueToStack(queueB);
	cout << "queueB :\n";
	queueB.print();
	cout << "stackB:\n";
	stackB.print();
	system("pause");
	return 0;
}