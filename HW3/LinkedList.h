#pragma once

template <class ItemType>
struct Node
{
	ItemType data;
	Node<ItemType> *next;
};

/* ==============
**	Linked List
** ==============
*/	
template <class List_ItemType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void			InsertFirst(List_ItemType value);
	void			InsertLast(List_ItemType value);
	int				InsertItem(List_ItemType value, int position);
	void			Clear();

//protected:
	int				InsertNode(Node<List_ItemType>* pPre, List_ItemType value);
	List_ItemType	DeleteNode(Node<List_ItemType>* pPre, Node<List_ItemType>* pLoc);
	int				Search(List_ItemType value, Node<List_ItemType>* &pPre, Node<List_ItemType>* &pLoc);
	
	Node<List_ItemType>*	getHead();
	int						getCount();
	void					setHead(Node<List_ItemType>* newHead);
	void					setCount(int newCount);

private:
	Node<List_ItemType> *head;
	int count;
};


template <class List_ItemType>
LinkedList<List_ItemType>::LinkedList()
{
	this->head = NULL;
	this->count = 0;
}

template <class List_ItemType>
LinkedList<List_ItemType>::~LinkedList()
{
	this->Clear();
}

template <class List_ItemType>
void LinkedList<List_ItemType>::InsertFirst(
	List_ItemType value)
{
	Node<List_ItemType> *pNew = new Node<List_ItemType>();

	// cannot allocate memory for new node
	if (pNew == NULL) return;

	// insert
	pNew->data = value;
	pNew->next = this->head;
	this->head = pNew;
	this->count++;
}

template <class List_ItemType>
void LinkedList<List_ItemType>::InsertLast(
	List_ItemType value)
{
	Node<List_ItemType> *pNew = new Node<List_ItemType>();
	Node<List_ItemType> *pLast;

	// cannot allocate memory for new node
	if (pNew == NULL) return;

	// insert
	pNew->data = value;
	if (this->head == NULL) this->head = pNew;
	else {
		pLast = this->head;
		for (int i = 0; i < this->count - 1; i++) pLast = pLast->next;
		pLast->next = pNew;
	}
	this->count++;
}

template <class List_ItemType>
int LinkedList<List_ItemType>::InsertItem(
	List_ItemType value,
	int position)
{
	// position is out of bound
	if (position < 0 || position > this->count) return 0;

	Node<List_ItemType> *pNew = new Node<List_ItemType>();
	Node<List_ItemType> *pPre;

	// cannot allocate memory for new node
	if (pNew == NULL) return 0;

	// insert
	pNew->data = value;
	if (this->head == NULL) {
		this->head = pNew;
		pNew->next = NULL;
	}
	else {
		if (position == 0) {
			pNew->next = this->head;
			this->head = pNew;
		}
		else {
			pPre = this->head;
			for (int i = 0; i < position - 1; i++) pPre = pPre->next;
			pNew->next = pPre->next;
			pPre->next = pNew;
		}
	}

	this->count++;
	return 1;
}


template <class List_ItemType>
void LinkedList<List_ItemType>::Clear()
{
	Node<List_ItemType> *tmp;
	while (this->head != NULL)
	{
		tmp = this->head;
		this->head = this->head->next;
		delete tmp;
	}
	this->count = 0;
}

template <class List_ItemType>
int LinkedList<List_ItemType>::InsertNode(
	Node<List_ItemType>* pPre,
	List_ItemType value)
{

	Node<List_ItemType> *pNew = new Node<List_ItemType>();

	if (pNew == NULL) return 0;

	pNew->data = value;
	if (pPre == NULL) {
		pNew->next = this->head;
		this->head = pNew;
	}
	else {
		pNew->next = pPre->next;
		pPre->next = pNew;
	}
	this->count++;
	return 1;
}

template <class List_ItemType>
List_ItemType LinkedList<List_ItemType>::DeleteNode(
	Node<List_ItemType>* pPre,
	Node<List_ItemType>* pLoc)
{

	List_ItemType result = pLoc->data;

	if (pPre == NULL) this->head = pLoc->next;
	else			  pPre->next = pLoc->next;

	this->count--;
	delete pLoc;
	return result;
}

template <class List_ItemType>
int	LinkedList<List_ItemType>::Search(
	List_ItemType value,
	Node<List_ItemType>* &pPre,
	Node<List_ItemType>* &pLoc)
{
	pPre = NULL;
	pLoc = this->head;

	while (pLoc != NULL && pLoc->data != value) {
		pPre = pLoc;
		pLoc = pLoc->next;
	}
	return (pLoc != NULL);
}

//getHead
template <class List_ItemType>
Node<List_ItemType>* LinkedList<List_ItemType>::getHead(){
	return head;
}

template <class List_ItemType>
int LinkedList<List_ItemType>::getCount(){
	return count;
}

template<class List_ItemType>
void LinkedList<List_ItemType>::setHead(Node<List_ItemType>* newHead){
	this->head = newHead;
}

template<class List_ItemType>
void LinkedList<List_ItemType>::setCount(int newCount){
	this->count = newCount;
}

