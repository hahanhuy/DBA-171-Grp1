#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
class DynamicArray {

private:
	int size;
	int capacity;
	int *storage;
public:
	DynamicArray() {
		size = 0;
		capacity = 10;
		storage = new int[capacity];
	}

	DynamicArray(int capacity) {
		this->capacity = capacity;
		size = 0;
		storage = new int[capacity];
	}
	~DynamicArray() {
		delete[] storage;
	}
	void setCapacity(int);
	void ensureCapacity(int);
	void pack();
	void trim();
	void rangeCheck(int);
	void set(int, int);
	int get(int);
	void removeAt(int);
	void insertAt(int, int);
	int searchval(int, int &index);
	void removeval(int);
	DynamicArray* sort(DynamicArray* arr);
	DynamicArray* frequencyOfElement(DynamicArray *arr);
	DynamicArray* mergeArray(DynamicArray *da, DynamicArray *da1);
	void print();
};

void DynamicArray::setCapacity(int newCapacity) {
	int *newStorage = new int[capacity];
	memcpy(newStorage, storage, sizeof(int)*size);
	capacity = newCapacity;
	delete[] storage;
	storage = newStorage;
}

void DynamicArray::ensureCapacity(int minCapacity) {
	if (minCapacity > capacity) {
		int newCapacity = (capacity * 3) / 2 + 1;
		if (newCapacity < minCapacity)
			newCapacity = minCapacity;
		setCapacity(newCapacity);
	}
}

void DynamicArray::pack() {
	if (size <= capacity / 2) {
		int newCapacity = (size * 3) / 2 + 1;
		setCapacity(newCapacity);
	}
}
void DynamicArray::trim() {
	int newCapacity = size;
	setCapacity(newCapacity);
}

void DynamicArray::rangeCheck(int index) {
	if (index < 0 || index >= size)
		throw "Index out of bounds!";
}

void DynamicArray::set(int index, int value) {
	rangeCheck(index);
	storage[index] = value;
}

int DynamicArray::get(int index) {
	rangeCheck(index);
	return storage[index];

}
void DynamicArray::insertAt(int index, int value) {
	if (index < 0 || index>size)
		throw "Index out of bounds!";
	ensureCapacity(size + 1);
	int moveCount = size - index;
	if (moveCount != 0)
		memmove(storage + index + 1, storage + index, sizeof(int)*moveCount);
	storage[index] = value;
	size++;
}

void DynamicArray::removeAt(int index) {
	rangeCheck(index);
	int moveCount = size - index - 1;
	if (moveCount > 0)
		memmove(storage + index, storage + (index + 1), sizeof(int) * moveCount);
	size--;
	pack();
}
void DynamicArray::print() {
	for (int i = 0; i < this->size; i++) {
		cout << storage[i] << " ";
	}
}
int DynamicArray::searchval(int val, int &index) {
	for (int i = 0; i < this->size; i++) {
		if (val == storage[i]) {
			index = i;
			break;
		}
	}
	return index;
}

void DynamicArray::removeval(int val) {

	for (int i = 0; i < this->size; i++) {
		if (val == storage[i]) {
			removeAt(i);
		}
	}
}
DynamicArray* DynamicArray::mergeArray(DynamicArray *first_da, DynamicArray *second_da) {
	DynamicArray *merged_array = new DynamicArray();
	for (int i = 0; i < first_da->size; i++) {
		merged_array->insertAt(merged_array->size, first_da->storage[i]);
	}
	for (int i = 0; i < second_da->size; i++) {
		merged_array->insertAt(merged_array->size, second_da->storage[i]);
	}
	return merged_array;
}
DynamicArray* DynamicArray::sort(DynamicArray* arr) {//insertion sort
	int t, j;
	for (int i = 1; i < arr->size; i++) {
		j = i - 1;
		t = arr->storage[i];
		while (t<(arr->storage[j]) && j >= 0)
		{
			arr->storage[j + 1] = arr->storage[j];
			j--;
		}
		arr->storage[j + 1] = t;
	}
	return arr;

}
DynamicArray* DynamicArray::frequencyOfElement(DynamicArray *arr) {
	int count = 0;
	DynamicArray *output = new DynamicArray();
	vector<int> _vector;
	//_vector.resize(100);
	for (int i = 0; i < arr->size -1; i++) {
		count++;
		if (arr->storage[i] < arr->storage[i + 1]) {
			_vector.push_back(arr->storage[i]);
			_vector.push_back(count);
			count = 0;
		}
		if (i == arr->size - 2 && arr->storage[i + 1] >= arr->storage[i]) {
			count++;
			_vector.push_back(arr->storage[i+1]);
			_vector.push_back(count);
		}
	}
	for (int i = 0; i < _vector.size(); i++) {
		output->insertAt(i, _vector[i]);
	}

	//delete frequency;
	return output;
}


int main() {
	int _index;
	/*int n,h;
	int , _value;*/
	//_CrtSetDbgFlag(_CRTDBG_CHECK_ALWAYS_DF);
	//cout << "Dynamic Array" << endl;
	DynamicArray* da = new DynamicArray(10);
	DynamicArray* da1 = new DynamicArray(10);
	//ARRAY_A
	da->insertAt(0, 1);
	da->insertAt(1, 0);
	da->insertAt(2, 2);
	da->insertAt(3, 3);
	da->insertAt(4, 4);
	da->insertAt(5, 2);
	da->insertAt(6, 3);
	da->insertAt(7, 5);
	//ARRAY_B
	da1->insertAt(0, 55);
	da1->insertAt(1, 100);
	da1->insertAt(2, 88);
	da1->insertAt(3, 75);
	da1->insertAt(4, 100);
	da1->insertAt(5, 55);
	da1->insertAt(6, 100);
//-------------------------------------------------------------------
	cout << "Insert 2 Array A and B We have below :" << endl;
	cout << "A: ["; da->print(); cout << "]\n";
	cout << "B: ["; da1->print(); cout << "]\n\n";
	cout << "Remove value at B[4].\n";
	cout << "B: ["; da1->print(); cout << "]\n";
	da1->removeAt(4);
	cout << "B: ["; da1->print(); cout << "]\n\n";
	cout << "Search element in Array A with value 5, => index :\n";
	da->searchval(5, _index);
	cout << "B: ["; da->print(); cout << "]\n";
	cout << "index: " << _index << endl << endl;
	cout << "Remove all elements have value 100 in Array B.\n";
	cout << "B: ["; da1->print(); cout << "]\n";
	da1->removeval(100);
	cout << "B: ["; da1->print(); cout << "]\n\n";
	cout << "Merge 2 array A and B\n";
	cout << "A: ["; da->print(); cout << "]\n";
	cout << "B: ["; da1->print(); cout << "]\n";
	cout << "Merge ["; da->mergeArray(da, da1)->print(); cout << "]\n\n";
	cout << "Frequence of elements in Array A:\n";
	cout << "A: ["; da->print(); cout << "]\n";
	cout << "Ference: ["; da->frequencyOfElement(da->sort(da))->print(); cout << "]\n\n";

//--------------------------------------------------------------------------------------

	system("pause");
	return 0;
}