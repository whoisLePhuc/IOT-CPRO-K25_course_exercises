#include<iostream>
#include<string>
using namespace std;

template <typename T>
class Box {
    protected:
        T value;
    public:
        Box(T v) : value(v) {}
        ~Box() {}
};

class IntBox : public Box<int>{
    public:
        IntBox(int v) : Box<int>(v) {}
        void isEven() {
            if (value % 2 == 0) {
                cout << value << " is even." << endl;
            } else {
                cout << value << " is odd." << endl;
            }
        }
        ~IntBox() {}
};

class StringBox : public Box<string>{
    public:
        StringBox(string v) : Box<string>(v) {}
        void toUpperCase() {
            for (char &c : value) {
                c = toupper(c);
            }
            cout << "Uppercase: " << value << endl;
        }
        ~StringBox() {}
};

int main() {
    IntBox intBox(10);
    intBox.isEven();

    StringBox strBox("hello");
    strBox.toUpperCase();

    return 0;
}