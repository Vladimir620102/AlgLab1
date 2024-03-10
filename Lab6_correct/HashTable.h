#pragma once
#include <array>
#include <list>
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
	static const int size = 10;
	std::array<std::list<Element>, size> data;

	int hashFunction(int value);
public:
	void add(int key, int value);
	Element get(int key);
	void remove(int key);
	Element update(int key, int value);
};