#pragma once
#include <array>
#include <list>
#include <vector>
class Element
{
public:
	int key;
	int data;
	Element()
	{
		key = 0; data = 0;
	}
	Element(int key, int data)
	{
		this->key = key;
		this->data = data;
	}
	bool operator == (const Element& element) const
	{
		return (this->key == element.key && this->data == element.data);
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
	void add(int key, int value);
	Element get(int key);
	void remove(int key);
	Element update(int key, int value);
	void print();
};