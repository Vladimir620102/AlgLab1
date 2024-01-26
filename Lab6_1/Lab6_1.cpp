// Lab6_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "hash.h"

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "Russian");

    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, (char*)"1", (char*)"First address");
    ht_insert(ht, (char*)"2", (char*)"Second address");
    ht_insert(ht, (char*)"Hel", (char*)"Third address");
    ht_insert(ht, (char*)"Cau", (char*)"Fourth address");
    print_search(ht, (char*)"1");
    print_search(ht, (char*)"2");
    print_search(ht, (char*)"3");
    print_search(ht, (char*)"Hel");
    print_search(ht, (char*)"Cau"); // Collision!
    print_table(ht);
    ht_delete(ht, (char*)"1");
    ht_delete(ht, (char*)"Cau");
    print_table(ht);
    free_table(ht);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
