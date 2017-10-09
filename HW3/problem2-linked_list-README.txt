
IMPLEMENT LINKED LIST
  - Tạo 1 LinkedList 
	vd: LinkedList<int>* myList = new LinkedList<int>();
  - Insert các Node vào bằng cách gọi các hàm Insert như InsertFirst, InsertLast, InsertItem.
	vd: myList->InsertFirst(5);
    	    myList->InsertItem(18,3);
            myList->InsertLast(25);
  - Xoá các Node bằng cách gọi các hàm delete như DeleteFirst, DeleteLast, DeleteItem.
	vd: myList->DeleteItem(2);
  - Lấy giá trị của 1 Node bằng hàm getItem.
	vd:  myList2->GetItem(1, value);
  - Duyệt tất cả các Node trong List và thực hiện phép toán, gọi hàm Traverse().
	vd: myList2->Traverse();
  - In tất cả giá trị các Node trong List bằng hàm Print2Console().
	vd: myList2->Print2Console();
  - Hàm trả về 1 List, Clone().
	vd: LinkedList<int>* myList2 = myList->Clone();
  - Xoá hết các Node trong list bằng hàm Clear().
	vd: myList->Clear();
  - Xoá data của 1 Node dùng hàm DeleteValue(List_ItemType value)
	vd: myList->DeleteValue(5);
  - Đảo LinkedList bằng hàm Reserve()
	vd: myList->Reserve();