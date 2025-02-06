#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <iostream>
#include <cstring>
using namespace std;

class strCount {
private:
    int count;                                                      //Для подсчета количества элементов которые ссылается на данный указатель
    char* str;                                                      //Сама строка на которую ссылаются
    friend class String;
    strCount(char* S) {
        int length = strlen(S);
        str = new char[length+1];
        strcpy(str, S);
        count = 1;
    }
    ~strCount() {
        delete[]str;
    }
};

class String {
private:
    strCount* ptp;
public:
    String() {
        char t[] = "NULL";
        ptp = new strCount(t);
    }
    String(char* s) {
        ptp = new strCount(s);
    }
    String(String& s) {
        ptp = s.ptp;
        ptp->count += 1;
    }
    void operator =(String& s) {
        if (ptp->count == 1)
            delete ptp;
        else 
            ptp->count -= 1;
        ptp = s.ptp;
        ptp->count += 1;
    }
    void display() {
        cout << ptp->str;
        cout << " addres: " << ptp << endl;
        cout << "kol: " << ptp->count << endl;
    }
    ~String() {
        if (ptp->count == 1)
            delete ptp;
        else
            ptp->count -= 1;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    char h[] = "Муха села на варенье, вот и все стихотворение";
    String s1 = h;
    s1.display();
    String s2(s1);
    s2.display();
    String s3;
    s3.display();
    s3 = s1;
    s3.display();
    char t[] = "НОоооооооооовый год к нам мчится";
    String s4(t);
    s3 = s4;
    s3.display();
    s1.display();
    _getch();
}
