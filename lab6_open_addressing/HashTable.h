#pragma once
#include <array>
#include <list>
#include <string>
#include <vector>
class Element
{
public:
	int phone;
	std::string fio;
	static const int PHONE_MAX = 32767;
	Element()
	{
		phone = 0; fio = "";
	}
	Element(int phone, std::string fio)
	{
		this->phone = phone;
		this->fio = fio;
	}
	bool operator == (const Element& element) const
	{
		return (this->phone == element.phone && this->fio == element.fio);
	}
};

class HashTableOA
{
	static const int size = 10;
	std::array<Element, size> data;
	std::vector<Element> data1;

	int hashFunction(int value);
public:
	HashTableOA(int size)
	{
		data1 = std::vector<Element>(size);
	}
	void add(int key, std::string value);
	Element get(int key);
	void remove(int key);
	Element update(int key, std::string value);
};
