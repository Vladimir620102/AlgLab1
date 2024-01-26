/*
Разработать приложение реализующие сортировки массивов числовых данных.
1.	Пользователь вводит число N (может быть достаточно большое).
2.	Приложение генерирует N числовых значений массива А.
3.	Вывести исходный массив А на экран.
4.	Скопировать массив А в массивы B, C, D, Е.
5.	Замерив время выполнения отсортировать массив B пузырьковской сортировкой. Вывести отсортированный массив и затраченное время на экран.
6.	Замерив время выполнения отсортировать массив С сортировкой вставкой (или методом Шелла). Вывести отсортированный массив и затраченное время на экран.
7.	Замерив время выполнения отсортировать массив D сортировкой выбора. Вывести отсортированный массив и затраченное время на экран.
8.	Замерив время выполнения отсортировать массив Е быстрой сортировкой. Вывести отсортированный массив и затраченное время на экран.
*/

#include <iostream>
using namespace std;

void bubble_sort(int* array_values, int count);
void sort_shell(int* array_values, int count);
void sort_selection(int* array_values, int count);
void quick_sort(int* array_values, int left, int right);
int main()
{
//  1.	Пользователь вводит число N(может быть достаточно большое).

    setlocale(LC_CTYPE, "Russian");

    int n;
    cout << "Введите число N: ";
    cin >> n;
//  2.	Приложение генерирует N числовых значений массива А.
//  3.	Вывести исходный массив А на экран.
    int* A = new int[n];
    time_t seconds = time(NULL);

    srand(seconds);
    for (int i = 0; i < n; i++)
    {
        *(A + i) = rand() % 10000;
        cout << *(A + i) << " ";
    }

//  4.	Скопировать массив А в массивы B, C, D, Е.
    int* B = new int[n];
    int* C = new int[n];
    int* D = new int[n];
    int* E = new int[n];
    for (int i = 0; i < n; i++) {
        *(B + i) = *(A + i);
        *(C + i) = *(A + i);
        *(D + i) = *(A + i);
        *(E + i) = *(A + i);
    }

  
  //  5.	Замерив время выполнения отсортировать массив B пузырьковской сортировкой.Вывести отсортированный массив и затраченное время на экран.

    cout << endl;
    cout << endl;
    cout << "bubble sort:" << endl;
    bubble_sort(B, n);
    for (int i = 0; i < n; i++)
    {
        cout << *(B + i) << " ";
    }

    //  6.	Замерив время выполнения отсортировать массив С сортировкой вставкой(или методом Шелла).Вывести отсортированный массив и затраченное время на экран.
        
    cout << endl;
    cout << "sort Shell:" << endl;
    sort_shell(C, n);
    for (int i = 0; i < n; i++)
    {
        cout << *(C + i) << " ";
    }

//  7.	Замерив время выполнения отсортировать массив D сортировкой выбора.Вывести отсортированный массив и затраченное время на экран.
    cout << endl;
    cout << "sort section:" << endl;
    sort_selection(D, n);
    for (int i = 0; i < n; i++)
    {
        cout << *(D + i) << " ";
    }

//  8.	Замерив время выполнения отсортировать массив Е быстрой сортировкой.Вывести отсортированный массив и затраченное время на экран.
    cout << endl;
    cout << "quick sort:" << endl;
    quick_sort(E, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << *(E + i) << " ";
    }

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;
}

void bubble_sort(int* array_values, int count)
{
    int j;
    //  int temp;
    for (int i = 0; i < count; i++)
    {
        //  temp = *(array_values + i);
        for (int j = i + 1; j < count; j++)
        {
            if (*(array_values + i) > *(array_values + j))
            {
                swap(*(array_values + i), *(array_values + j));
             
                //temp = array_values[i];
                //*(array_values + i) = *(array_values + j);
                //*(array_values + j) = temp;
            }
        }
    }
}


void sort_shell(int* array_values, int count) {
    for (int interval = count / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < count; i += 1) {
            int temp = array_values[i];
            int j;
            for (j = i; j >= interval && array_values[j - interval] > temp; j -= interval) {
                array_values[j] = array_values[j - interval];
            }
            array_values[j] = temp;
        }
    }
}

void sort_selection(int* array_values, int count)
{
    int left = 0;
    while (left < count)
    {
        int min_index = left;
        for (int i = left + 1; i < count; i++)
        {
            if (*(array_values +i) < *(array_values +min_index))
            {
                min_index = i;
            }
        }
        swap(*(array_values + left), *(array_values +min_index));
        left++;
    }
}
void quick_sort(int* array_values, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int middle = array_values[(left + right) / 2];

    while (i <= j) {
        while (*(array_values + i) < middle)
            i++;
        while (*(array_values +j) > middle)
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


