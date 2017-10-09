#include <iostream>
using namespace std;
template <class ItemType>
class Node {
public:
    ItemType data;
    Node<ItemType> *link;
    Node(){
        this->link = NULL;
    }
    
    Node(ItemType data){
        this->data = data;
        this->link = NULL;
    }
};
template <class List_ItemType>

class LinkedList{
    Node<List_ItemType>* head;
    int count;
protected:
    int InsertNode(Node<List_ItemType>* pPre,List_ItemType value);
    
    List_ItemType DeleteNode(Node<List_ItemType>* pPre, Node<List_ItemType>* pLoc);
    
    int Search(List_ItemType value, Node<List_ItemType>* &pPre, Node<List_ItemType>* &pLoc);
    
public:
    LinkedList();
    
    void InsertFirst(List_ItemType value);
    void InsertLast(List_ItemType value);
    int InsertItem(List_ItemType value, int position);
    
    void DeleteFirst();
    void DeleteLast();
    int DeleteItem(int postion);
    int GetItem(int position, List_ItemType &dataOut);
    
    void Traverse();
    LinkedList<List_ItemType>* Clone();
    void Print2Console();
    void Clear();
    int DeleteValue(List_ItemType value);
    void Reserve();
};
//Tao List
template <class List_ItemType>
LinkedList<List_ItemType >:: LinkedList (){
    this->head = NULL;
    this->count = 0;
}
//InsertFirst
template<class List_ItemType>
void LinkedList<List_ItemType>::InsertFirst(List_ItemType value){
    Node<List_ItemType>* pNew = new Node<List_ItemType>(value);
    if (this->head == NULL) {
        this->head = pNew;
        this->count = 1;
    }
    else {
        pNew->link = this->head;
        this->head = pNew;
        this->count++;
    }
}
//InsertLast
template<class List_ItemType>
void LinkedList<List_ItemType>::InsertLast(List_ItemType value){
    Node<List_ItemType> *pNew = new Node<List_ItemType>(value);
    if (this->head == NULL) {
        this->head = pNew;
        this->count = 1;
    }
    else {
        Node<List_ItemType> *pPre = this->head;
        for (int i = 0; i < this->count - 1; i++) {
            pPre = pPre->link;
        }
        pPre->link = pNew;
        this->count++;
    }
}
//InsertItem
template <class List_ItemType>
int LinkedList<List_ItemType>::InsertItem(List_ItemType value, int position) {
    
    if (position < 0 || position > this->count)
        return 0;
    
    Node<List_ItemType> *newPtr, *pPre;
    newPtr = new Node<List_ItemType>();
    if (newPtr == NULL)
        return 0;
    
    newPtr->data = value;
    
    if (head == NULL) {
        head = newPtr;
        newPtr->link = NULL;
    } else if (position == 0) {
        newPtr->link = head;
        head = newPtr;
    }
    else {
        pPre = this->head;
        
        for (int i = 0; i < position-1; i++)
            pPre = pPre->link;
        
        newPtr->link = pPre->link;
        pPre->link = newPtr;
    }
    
    this->count++;
    return 1;
}
//DeleteFirst
template <class List_ItemType>
void LinkedList<List_ItemType>::DeleteFirst(){
    if (this->head == NULL) {
        return;
    }
    else if (this->count == 1){
        delete this->head;
        this->head = NULL;
        this->count--;
    }
    else{
        Node<List_ItemType> *pTemp = this->head;
        this->head = pTemp->link;
        delete pTemp;
        this->count--;
    }
}
//DeleteItem
template <class List_ItemType>
int LinkedList<List_ItemType>::DeleteItem(int position){
    if (position < 0 || position >= this->count)
        return 0;
    
    Node<List_ItemType> *dltPtr, *pPre;
    
    if (position == 0) {
        dltPtr = head;
        head = head->link;
    } else {
        pPre= this->head;
        for (int i = 0; i < position-1; i++)
            pPre = pPre->link;
        dltPtr = pPre->link;
        pPre->link = dltPtr->link;
    }
    
    delete dltPtr;
    this->count--;
    return 1;
}
//GetItem
template <class List_ItemType>
int LinkedList<List_ItemType>::GetItem(int position, List_ItemType &dataOut){
    Node<List_ItemType> *pTemp = this->head;
    for (int i = 0; i < position; i++) {
        pTemp = pTemp->link;
    }
    dataOut = pTemp->data;
    return dataOut;
}
//Traverse
template <class List_ItemType>
void LinkedList<List_ItemType>::Traverse() {
    Node<List_ItemType> *p = head;
    while (p != NULL){
        p->data++;
        p = p->link;
    }
}
//Clone
template <class List_ItemType>
LinkedList<List_ItemType>* LinkedList<List_ItemType>::Clone()
{
    LinkedList<List_ItemType>* result = new LinkedList<List_ItemType>();
    
    Node<List_ItemType>* p = this->head;
    
    while (p != NULL) {
        result->InsertLast(p->data);
        p = p->link;
    }
    
    result->count = this->count;
    return result;
}
// Print2Console
template <class List_ItemType>
void LinkedList<List_ItemType>::Print2Console(){
    Node<List_ItemType> *pTemp = this->head;
    for (int i = 0; i < count; i++) {
        std::cout << pTemp->data << '\t';
        pTemp = pTemp->link;
    }
    std::cout << '\n';
}
// Clear
template <class List_ItemType>
void LinkedList<List_ItemType>::Clear(){
    Node<List_ItemType> *temp;
    while (this->head != NULL) {
        temp = this->head;
        this->head = temp->link;
        delete temp;
    }
    this->count = 0;
}
//Delete value
template <class List_ItemType>
int LinkedList<List_ItemType>::DeleteValue(List_ItemType value){
    Node<List_ItemType> *pTemp = this->head;
    while (pTemp != NULL) {
        if (pTemp->data == value) {
            pTemp->data = 0;
        }
        pTemp = pTemp->link;
    }
    return 1;
}
//Reserve List
template <class List_ItemType>
void LinkedList<List_ItemType>::Reserve(){
    if(head == NULL) return;
    Node<List_ItemType> *prev, *current, *next;
    prev = next = NULL;
    current = this->head;
    while (current!= NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    this->head = prev;
}
int main() {
    LinkedList<int>* myList = new LinkedList<int>();
    //insert items
	cout << "Insert items into list:\n";
	cout << "- Insert first 15, 10, 5:\n";
	myList->InsertFirst(15);
    myList->InsertFirst(10);
    myList->InsertFirst(5);

	cout << "List 1: ";
	myList->Print2Console();

	cout << "- Insert '18' at position 3:\n";
    myList->InsertItem(18,3);
	cout << "List 1: ";
	myList->Print2Console();

	cout << "- Insert '20' at position 3:\n";
	myList->InsertItem(20, 3);
	cout << "List 1: ";
	myList->Print2Console();

	cout << "- Insert '25' at the last position:\n";
	myList->InsertLast(25);
	cout << "List 1: ";
	myList->Print2Console();

	cout << endl;

	//delete an item
	cout << "Delete an item at position 2\n";
	myList->DeleteItem(2);
    cout << "List 1: ";
    myList->Print2Console();
    
	cout << endl;
	
	//clone a list
	int value;
    LinkedList<int>* myList2 = myList->Clone();
	cout << "Clone List 1 to List 2:\n";
	cout << "List 2: ";
    myList2->Print2Console();
	
	cout << endl;

	//get an item
	myList2->GetItem(1, value);
	cout << "Value at position 1 of list 2: " << value << '\n';
	
	//Traverse
	cout << "Traverse the List 2\n";
    myList2->Traverse();
	cout << "List 2.1: ";
    myList2->Print2Console();
    
	cout << endl;

	//Reserve
	myList->Reserve();
	cout << "Reserve List 1: ";
    myList->Print2Console();
    
	
	delete myList;
    delete myList2;

	system("pause");
    return 0;
}
