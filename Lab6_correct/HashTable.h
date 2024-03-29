#pragma once
#include <array>
#include <list>
#include <vector>
#include <string>
class Element
{
public:
	int key;
	static const int PHONE_MAX = 32767;
	std::string fio;
	Element()
	{
		key = 0; fio = "";
	}
	Element(int key, std::string fio)
	{
		if (key >= PHONE_MAX)
		{
			this->key = 0, this->fio = "";
		}
		else
		{
			this->key = key;
			this->fio = fio;
		}
	}
	bool operator == (const Element& element) const
	{
		return (this->key == element.key && this->fio == element.fio);
	}
};

class HashTable
{
	int size = 10;
	std::vector<std::list<Element>> data;

	int hashFunction(int value);
public:
	HashTable(int size)
	{
		this->size = size;
		data = std::vector<std::list<Element>>(size);
	}
	void add(int key, std::string value);
	Element get(int key);
	void remove(int key);
	Element update(int key, std::string value);
	void print();
};