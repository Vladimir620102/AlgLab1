﻿/*
1.	В разработанное приложение(на стеках) необходимо ввести символьную строку, которая может содержать цифры, буквы, 
знаки математических операций(+, -, *, / ) и три вида скобок : (), [] и{}.
Определить, верно ли расставлены скобки(символы между скобками не учитывать).
Например, в строках()[{}] и[{}([])] скобки расставлены верно, а в строках([)] и ]]](((-неверно.
В качестве ответа вывести текст «скобки расставлены верно» или «скобки расставлены не верно».
*/

#include <iostream>

using namespace std;

const int MAX_STACK = 1000;

struct stack {
    char* A = new char[MAX_STACK];;
    int head = -1;   //Индекс крайнего элемента.

    void push(char x)
    {
        head++;
        if (head >= MAX_STACK)
            cout << "Ошибка: переполнение стека." << endl;
        else
            *(A + head) = x;
    }

    char pop()
    {
        if (head != -1)
        {
            head--;
            return *(A + head + 1);
        }
        cout << "Ошибка: попытка извлечь элемент из пустого стека." << endl;
        return '\0';
    }

    bool is_empty() 
    {
        return head == -1;
    }

    void free()
    {
        delete[] A;
    }
};
 

int main()
{
    setlocale(LC_CTYPE, "Russian");
    
    stack steck;

    string source;
    cout << "Введите символьную строку, которая может содержать цифры, буквы, " <<
        "знаки математических операций(+, -, *, / ) и три вида скобок : (), [] и{}." << endl;
    cin >> source;
   
    bool flag_success = true;

    for (int i = 0; i < source.length(); i++)
    {
        char c = source[i];
        // Если текущий символ строки — открывающая скобка, то кладём его в стек
        if (c == '(' || c == '[' || c == '{') 
        {
            steck.push(c); 
            continue;
        }
        // если закрывающая скобка
        if (c == ')' || c == ']' || c == '}') {
            // проверяем, что стек не пуст
            if (steck.is_empty()) 
            {
                flag_success = false;
                break;
            }
            // извлекаем символ из стека
            char c2 = steck.pop();
            // и проверяем, что это скобка того же типа, что и текущая
            if (!( c2 == '(' && c == ')'
                || c2 == '[' && c == ']'
                || c2 == '{' && c == '}'))
            {
                
                flag_success = false;
                break;
            }
        }
    }   
    
    if(flag_success && steck.is_empty())
        cout << "скобки расставлены верно" << endl;
    else
        cout << "скобки расставлены неверно" << endl;

    steck.free();
}


