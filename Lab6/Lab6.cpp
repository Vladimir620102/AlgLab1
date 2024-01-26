//1) хеш - функция для сопоставления ключей со значениями.
//2) Структура данных хеш - таблицы, поддерживающая операции вставки, поиска и удаления.
//3) Структура данных для учета конфликтов ключей

//#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <string>

#include "Hash_Twin_Chain.h"


using namespace std;

#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = (char*)"";
	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
void add_hash_data(hashTC::Object* H, int key, char* str) {
	AAA* a = new AAA;
	a->key = key;
	a->mas = str;
	H->insert(a);
}

//-------------------------------
int main()
//int _tmain(int argc, char* argv[])
{
	//init_data(htable);
//htable[11111] = "Иванов С.Р.";
//htable[11112] = "Семенов А.Ф.";
//htable[11113] = "Николаев Б.Х.";
//htable[11114] = "Петров П.П.";
//htable[11115] = "Сидоров Г.Р.";

//cout << htable[11114] << endl;

	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Ведите размер хэш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object* H = hashTC::create(current_size, hf);
	add_hash_data(H, 1, (char*)"Иванов Ф.В.");
	add_hash_data(H, 2, (char*)"Петров Ф.В.");
	add_hash_data(H, 3, (char*)"Сидоров Ф.В.");
	add_hash_data(H, 4, (char*)"Кузнецов Ф.В.");
	add_hash_data(H, 5, (char*)"Доронина Ф.В.");
	add_hash_data(H, 6, (char*)"Никулин Ф.В.");

	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хэш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;
			cin >> k;
			a->key = k;
			cout << "введите строку" << endl;
			cin >> str;
			a->mas = str;
			H->insert(a);
		}
			  break;
		case 1: H->Scan();
			break;
		case 3: {
			AAA* b = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			b->key = k;
			H->deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "введите ключ" << endl;
			cin >> k;
			c->key = k;
			if (H->search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Первый элемент с данным ключом" << endl;
				AAA_print(H->search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}

