Khởi Động chương trình ta insert index và value vào 2 Array A và B
	A[1 0 2 3 4 2 3 5]
	B[55 100 88 75 55 100]

Ta dùng hàm removeAt xóa value tại index thứ 4 của ArrayA
	Mảng A sau khi thực hiện A->removeVal(4);
	=> A[1 0 2 3 2 3 5]

Ta dùng hàm searchVal để tìm giá trị của trong 1 array trả về vị trí của giá trị trong Array
	A->search(0,index);
	Giá trị index được trả về là 1

Ta dùng hàm removeVal xóa các giá trị mong muốn trong Array A
	removeVal(2)
	=>A[1 0 3 3 5]

Ta dùng hàm mergeArray để merge 2 array A và B
	mergeArray(A,B)
	=>merge_Array[1 0 3 3 5 55 100 88 75 55 100 1 0 3 3 5]

Ta dùng hàm frequencyOfElement và sort để kiểm tra tần xuất suất hiện của các phần tử trong arrayB
	ta Sort array B bằng Hàm sort(b)
	sau đó dùng hàm frequencyOfElement để xác định tần xuất suất hiện của elements
	=>frequency[55 2 75 1 88 1]
Kết thúc chương trình.