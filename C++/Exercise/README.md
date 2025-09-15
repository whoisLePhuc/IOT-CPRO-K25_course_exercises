# Bài tập OOP C++: Kế thừa và Đa hình

Dưới đây là các bài tập thực hành về **kế thừa (inheritance)** và **đa hình (polymorphism)** trong C++.

---

## 📝 Bài tập 1: Kế thừa đơn giản
**Yêu cầu:**  
- Tạo class `Person` có các thuộc tính: `name`, `age`.  
- Có method `showInfo()`.  
- Tạo class `Student` kế thừa từ `Person`, thêm `studentID`.  
- Override lại `showInfo()` để in cả `studentID`.  

👉 *Mục tiêu: Hiểu rõ kế thừa + ghi đè method.*

---

## 📝 Bài tập 2: Kế thừa nhiều tầng
**Yêu cầu:**  
- Tạo class `Vehicle` với thuộc tính `brand`.  
- Tạo class `Car` kế thừa từ `Vehicle`, thêm `model`.  
- Tạo class `ElectricCar` kế thừa từ `Car`, thêm `batteryLife`.  
- Override `showInfo()` ở mỗi lớp để hiển thị thông tin phù hợp.  

👉 *Mục tiêu: Thực hành kế thừa nhiều tầng (multi-level inheritance).*

---

## 📝 Bài tập 3: Đa hình động (runtime polymorphism)
**Yêu cầu:**  
- Tạo class `Shape` có hàm ảo `draw()`.  
- Tạo các class `Circle`, `Rectangle`, `Triangle` kế thừa từ `Shape`, override `draw()`.  
- Viết hàm `printShape(Shape* s)` gọi `s->draw()`.  
- Trong `main`, tạo danh sách `Shape*` chứa nhiều hình và duyệt để vẽ.  

👉 *Mục tiêu: Hiểu rõ virtual function + pointer đến base class.*

---

## 📝 Bài tập 4: Đa hình biên dịch (compile-time polymorphism)
**Yêu cầu:**  
- Viết class `Vector2D` có operator `+`, `-`, `*` (overload toán tử).  
- Tạo các vector và thử cộng/trừ/nhân.  
- So sánh kết quả với cách viết hàm `add()` thông thường.  

👉 *Mục tiêu: Hiểu rõ operator overloading.*

---

## 📝 Bài tập 5: Template + Kế thừa
**Yêu cầu:**  
- Viết class template `Box<T>` để chứa 1 giá trị.  
- Viết class `IntBox` kế thừa `Box<int>`, thêm hàm `isEven()` kiểm tra số chẵn/lẻ.  
- Viết class `StringBox` kế thừa `Box<string>`, thêm hàm `toUpperCase()`.  

👉 *Mục tiêu: Hiểu cách kết hợp template và kế thừa.*

---

## 📝 Bài tập 6: Mini Project – Quản lý nhân sự
**Yêu cầu:**  
- Tạo class `Employee` (tên, tuổi, lương cơ bản).  
- Tạo class `Developer` kế thừa `Employee`, thêm thuộc tính `bonus`.  
- Tạo class `Manager` kế thừa `Employee`, thêm thuộc tính `teamSize`.  
- Tất cả đều override hàm `calculateSalary()`.  
- Viết chương trình nhập danh sách nhân viên nhiều loại, in ra thông tin và lương cuối cùng.  

👉 *Mục tiêu: Vận dụng kế thừa + đa hình trong tình huống thực tế.*
