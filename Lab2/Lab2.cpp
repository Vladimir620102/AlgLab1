﻿#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    int n;
    int step=1;
    cout << "Задумайте число < N" << endl;
    cout << "Введите число N: ";
    cin >> n;

    bool flag = false;
    int bottom = 0; 
    int top = n; 
    int mid;

    while ((bottom <= top) && (flag != true)) 
    {
        mid = (bottom + top) / 2; // середина

        cout << endl;
        cout << mid << ": это число?" << endl;
        int choice;
        cout << "0 - угадал " << endl;
        cout << "-1 - мало" << endl;
        cout << "1 - много" << endl;
        cout << "Сделайте выбор: ";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        else if (choice == -1)
        {
            bottom = mid;
        }
        else if (choice == 1)
        {
            top = mid;
        }
        else
            continue;
        step++;
    }

        cout << "Максимальное количество шагов = " << step;

    return 0;

}

/*
Разработать приложение реализующие игру «Угадайка!» на основе бинарного поиска.
1.	Пользователь вводит число N (может быть достаточно большое).
2.	Программа выводит на экран число Х  (1 ≤ Х ≤ N) .
3.	У пользователя есть выбор одного из ответов «мало», «много», «угадал».
4.	В случае «мало» или «много» программа должна повторять п. 2-4.
5.	В случае «угадал» программа должна вывести на экран максимальное количество шагов при бинарном поиске от числа N и все шаги бинарного поиска. (Например, N=100, вывести
Максимальное количество шагов = 7
100
50
25
13
7
4
2
1)

Бинарный поиск основан на идее деления данных на половины и последующем поиске в одной из них с последующим делением

*/