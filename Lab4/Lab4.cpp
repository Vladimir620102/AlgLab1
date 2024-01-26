/*
В сети магазинов "ФИТ-Аудио" проводится рекламная акция.Каждый второй товар – бесплатно.Естественно, кассирам дано указание пробивать товары в таком порядке, 
чтобы магазин потерял как можно меньше денег.
По списку товаров определите максимальную сумму в чеке.
Вход: натуральное число товаров(N < 10000) и далее N натуральных чисел – цены товаров.Цену товара сгенерировать(Например, от 1 до 100).
Выход : Порядок пробивания на кассе и число – максимальная сумма чека.
*/

#include <iostream>


void task1();
void task2();
void quick_sort(int* array_values, int left, int right);

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    task1();
    cout << endl;
    cout << endl;
    task2();
}

void task1() 
{
    int n;
    cout << "Введите натуральное число товаров(N < 10000): ";
    cin >> n;
    //  2.	Цену товара сгенерировать(Например, от 1 до 100) в массив А.
    int* A = new int[n];
    int* B = new int[n];

    time_t seconds = time(NULL);
    srand(seconds);

    for (int i = 0; i < n; i++)
    {
        *(A + i) = rand() % 100;
        cout << *(A + i) << " ";
        *(B + i) = *(A + i);
    }

    quick_sort(B, 0, n - 1); // сортировка по возрастанию

    int middle = n / 2 + n % 2;

    int sum = 0;
    for (int i = 0; i < middle; i++)
        sum = sum + *(B + n - i - 1);   //идем с конца
    cout << endl;
    cout << "Наибольшая сумма чека:" << sum << endl;
}

void task2() 
{
    int n;
    cout << "Введите натуральное число участников (N < 10000): ";
    cin >> n;
    //  сгенерировать результаты участников (Например, от 1 до 100) в массив А.
    int* A = new int[n];
    int* B = new int[n];

    time_t seconds = time(NULL);
    srand(seconds);
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        *(A + i) = rand() % 8;
        cout << *(A + i) << " ";
        if (*(A + i) > 4) p++;  // призеры - это те, кто набрали 5,6 или 7 баллов
    }
    cout << endl;

    cout << "число призеров: " << p << endl;
}

void quick_sort(int* array_values, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int middle = array_values[(left + right) / 2];

    while (i <= j) {
        while (*(array_values + i) < middle)
            i++;
        while (*(array_values + j) > middle)
            j--;
        if (i <= j) {
            tmp = *(array_values + i);
            *(array_values + i) = *(array_values + j);
            *(array_values + j) = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quick_sort(array_values, left, j);
    if (i < right)
        quick_sort(array_values, i, right);
}