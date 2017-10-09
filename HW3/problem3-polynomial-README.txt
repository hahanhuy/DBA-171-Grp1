HƯỚNG DẪN SỬ DỤNG CHƯƠNG TRÌNH TÍNH ĐA THỨC:
- Khởi động chương trình
- Nhập đa thức theo đúng chuẩn như sau: ax^n+bx^m+..c rồi nhấn phím Enter
	+ a,c,b là các hệ số, thuộc tập số thực
	+ n,m là các số mũ, thuộc tập số nguyên
	+ Ví dụ nhập đa thức: 3x^4+1.2x^-3-5
- Chương trình hiện thông báo "Do you want to continue (y/n)?"
- Nếu muốn tiếp tục nhập đa thức khác, nhập 'y' rồi nhấn Enter. Ngược lại, nhập 'n' rồi nhấn Enter.
- Sau khi nhập 'n', chương trình hiện thông báo "Stop input polynomial" để kết thúc nhập đa thức
- Chương trình tiếp tục hiện thông báo "Perform math operations: ((Pi add\sub\mul\div Pj || Pi cal n))" để nhập phép tính.
	+ Pi, Pj là đa thức muốn tính toán (đa thức nhập đầu tiên là P1, thứ 2 là P2...)
	+ n là một số thực thay thế cho biến x để tính giá trị đa thức (chỉ sử dụng cho phép "cal")
	+ Các lệnh: add - cộng, sub - trừ, mul - nhân, div - chia, cal - là tính giá trị đa thức với x = n
	+ Ví dụ: P1 add P2
- Sau khi nhập phép tính, nhấn Enter để hiện thị kết quả.
- Chương trình hiện thị kết quả và thông báo: "Do you want to continue (y/n)?"
- Nếu muốn tiếp tục nhập phép tính khác, nhập 'y' rồi nhấn Enter. Ngược lại, nhập 'n' rồi nhấn Enter.
- Sau khi nhập 'n' chương trình kết thúc, nhấn Enter để thoát chương trình.
========

CÁC LỖI GẶP PHẢI TRONG QUÁ TRÌNH THỰC THI CHƯƠNG TRÌNH:
- Memory is full!	: Không thể cấp phát bộ nhớ để lưu đa thức mới
- Index is out of bound	: Đa thức muốn tính vượt quá số đa thức nhập vào hoặc nhỏ hơn 1 (ví dụ P0 hoặc P5 trong khi chỉ nhập 4 đa thức)
- Error operator	: Phép tính không hợp lệ (khác 5 phép tính sau: add \ sub \ mul \ div \ cal)