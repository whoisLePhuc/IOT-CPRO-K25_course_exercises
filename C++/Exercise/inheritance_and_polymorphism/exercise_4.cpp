#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
    public:
        float x, y;
        Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

        Vector2D operator+ (const Vector2D& other){
            return(Vector2D(x + other.x, y + other.y));
        }

        Vector2D operator- (const Vector2D& other){
            return(Vector2D(x - other.x, y - other.y));
        }

        Vector2D operator* (const Vector2D& other){
            return(Vector2D(x * other.x, y * other.y));
        }
        ~Vector2D() {}
};

Vector2D add(const Vector2D& first, const Vector2D& second) {
    return Vector2D(first.x + second.x, first.y + second.y);
}


int main(){
    Vector2D v1(2.0f, 3.0f);
    Vector2D v2(4.0f, 5.0f);

    Vector2D v3 = v1 + v2;
    cout << "test v1 + v2 = (" << v3.x << ", " << v3.y << ")" << endl;

    Vector2D v4 = v1 - v2;
    cout << " test v1 - v2 = (" << v4.x << ", " << v4.y << ")" << endl;

    Vector2D v5 = v1 * v2;
    cout << "test v1 * v2 = (" << v5.x << ", " << v5.y << ")" << endl;

    Vector2D v6 = add(v1, v2);
    cout << "test add(v1, v2) = (" << v6.x << ", " << v6.y << ")" << endl;

    return 0;
}