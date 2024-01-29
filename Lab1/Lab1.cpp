// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>

using namespace std;

unsigned long long fibonacci_cycle(int n);
unsigned long long fibonacci_recursion(int n);

int main()
{

    setlocale(LC_CTYPE, "Russian");

    int n;
    cout << "Введите число N (N > 0): ";
    cin >> n;

    const auto start{ std::chrono::steady_clock::now() };

    cout << fibonacci_cycle(n-1) << endl;

    const auto stop1{ std::chrono::steady_clock::now() };

    cout << fibonacci_recursion(n-1) << endl;

    const auto stop2{ std::chrono::steady_clock::now() };

    const std::chrono::duration<double> d1{ stop1 - start };
    const std::chrono::duration<double> d2{ stop2 - stop1 };
    std::cout << "cycle: " << d1.count() << "\n";
    std::cout << "recursion: " << d2.count() << "\n";

 
}



unsigned long long fibonacci_cycle(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    unsigned long long f0 = 0;
    unsigned long long f1 = 1;
    unsigned long long fibonacci = 0;
    
    for (int i = 1; i < n; i++) 
    {
        fibonacci = f0 + f1;
        f0 = f1;
        f1= fibonacci;
   
    }
    return fibonacci;
}

unsigned long long fibonacci_recursion(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci_recursion(n - 2) + fibonacci_recursion(n - 1);
}

