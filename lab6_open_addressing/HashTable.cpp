#include "HashTable.h"

int HashTableOA::hashFunction(int value)
{
    std::hash<int> h;
    return h(value) % size;

}

void HashTableOA::add(int key, std::string value)
{
}

Element HashTableOA::get(int key)
{
    return Element();
}

void HashTableOA::remove(int key)
{
}

Element HashTableOA::update(int key, std::string value)
{
    return Element();
}
