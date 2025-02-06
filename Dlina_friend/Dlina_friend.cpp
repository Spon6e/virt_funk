#include <conio.h>
#include <iostream>
#include <locale.h>
using namespace std;

class ENGL {
private:
    int D;
    float S;
public:
    ENGL() : D(0), S(0.0) {}
    ENGL(int k, float m) : D(k), S(m) {}
    ENGL(float G) {
        D = static_cast<int>(G);
        S = (G - D) * 12;
    }
    void vivod() {
        cout << "F" << D << " D " << S;
    }
    friend float QDR(ENGL);
};

float QDR(ENGL c) {
    float k = c.D + c.S / 12;
    float U = k * k;
    return(U);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ENGL m(3, 10);
    float n = QDR(m);
    cout << n << endl;
    m.vivod();
}
