#include <fstream>
#include <iostream>
#include "Num.h"
#include "Node.h"
#include "List.h"
#include "Matrix.h"
using namespace std;

int main()
{
    try {
        if (AutoTest()) {
            setlocale(LC_ALL, "Russian");
            cout << "AutoTest passed" << "\n\n";
            ifstream input("data.txt");
            Matrix m(input);
            input.close();
            cout << "Исходная матрица:" << "\n";
            m.Print();
            cout << "\nЭлемент [1][3]:";
            cout << m[1][3] << "\n\n";
            m[2][3] = 5;
            cout << "Изменили элемент [2][3]: " << "\n";
            m.Print();
            cout << "\n";
            m.Change(0, 2);
            cout << "Поменяли строки 0 и 2 местами: " << "\n";
            m.Print();
            m.Mult(1, 2);
            cout << "\n";
            cout << "Умножили 1 строку на 2: " << "\n";
            m.Print();
            cout << "\n";
            List* l = new List;
            l = m.Comb(0, 2, 3, 5);
            cout << "0 строка*3 + 2 строка*5: " << "\n";
            (*l).Print();
            (*l).clear();
            cout << "\n";
            double* s = m.Str(3);
            cout << "3 строка: " << "\n";
            for (int i = 0; i < sizeof(s) + 1; i++) { cout << s[i] << " "; }
            cout << "\n\n";
            cout << "4 столбец: " << "\n";
            double* c = m.Col(4);
            for (int i = 0; i < sizeof(c); i++) { cout << c[i] << "\n"; }
            cout << "\nМатрица в итоге: " << "\n";
            m.Print();
            cout << endl;
            delete l;
            delete[] s;
            delete[] c;
        }
        else {
            cout << "AutoTest faled" << endl;
        }
    }
    catch (int err) { printf("error=%d\n", err); }
    return 0;
}
