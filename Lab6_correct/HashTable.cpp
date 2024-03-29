#include "HashTable.h"
int HashTable::hashFunction(int value)
{
	std::hash<int> h;
	return h(value) % size;
}
void HashTable::add(int key, int value)
{
	auto position = hashFunction(key);
	data[position].push_back(Element(key, value));
}
Element HashTable::get(int key)
{
	auto position = hashFunction(key);
	for (auto elem : data[position])
	{
		if (elem.key == key)
		{
			return elem;
		}
	}
}
void HashTable::remove(int key)
{
	auto position = hashFunction(key);
	auto it = data[position].begin();
	while (true)
	{
		if ((*it).key == key)
		{
			it = data[position].erase(it);
		}
		if (it == data[position].end())
			break;
	}
}
Element HashTable::update(int key, int value)
{
	auto position = hashFunction(key);
	for (auto elem : data[position])
	{
		if (elem.key == key)
		{
			elem.data = value;
			return elem;
		}
	}
}

void HashTable::print()
{
	for (int i = 0; i < this->size; i++)
	{
		for (auto it = this->data[i].begin(); it != this->data[i].end(); it++)
		{
			printf("%d: %d\n",(*it).key, (*it).data);
		}
	}
}
