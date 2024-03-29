#include "HashTable.h"

int HashTableOA::hashFunction(int value)
{
    std::hash<int> h;
    return h(value) % size;

}

void HashTableOA::add(int key, std::string value)
{
    // safety checks

    // 1. get hash code
    int hashcode = hashFunction(key);

    // 2. if NOT empty | deleted | same key
    //      then iterate element
    //    else 

    // 3. if same key then throw an error
    // 4. if empty or deleted  write an element into the
}

Element HashTableOA::get(int key)
{
    // iterate element untill we reach same key or went thru all array
    // if found return element
    return Element();
}

void HashTableOA::remove(int key)
{
    // iterate element untill we reach same key or went thru all array
    // if found delete element

}

Element HashTableOA::update(int key, std::string value)
{
    // iterate element untill we reach same key or went thru all array
    // if found update element
    return Element();
}
