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

protected:
	int				InsertNode(Node<List_ItemType>* pPre, List_ItemType value);
	List_ItemType	DeleteNode(Node<List_ItemType>* pPre, Node<List_ItemType>* pLoc);
	int				Search(List_ItemType value, Node<List_ItemType>* &pPre, Node<List_ItemType>* &pLoc);

private:
	Node<List_ItemType> *head;
	int count;
};

