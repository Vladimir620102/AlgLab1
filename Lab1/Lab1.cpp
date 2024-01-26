// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int fibonacci_cycle(int n);
int fibonacci_recursion(int n);

int main()
{

    setlocale(LC_CTYPE, "Russian");

    int n;
    cout << "Введите число N (N > 0): ";
    cin >> n;

    cout << fibonacci_cycle(n-1) << endl;
    cout << fibonacci_recursion(n-1) << endl;

 
}



int fibonacci_cycle(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int f0 = 0;
    int f1 = 1;
    int fibonacci = 0;
    
    for (int i = 1; i < n; i++) 
    {
        fibonacci = f0 + f1;
        f0 = f1;
        f1= fibonacci;
   
    }
    return fibonacci;
}

int fibonacci_recursion(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci_recursion(n - 2) + fibonacci_recursion(n - 1);
}

