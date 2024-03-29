#include <iostream>
#include "HashTable.h"

void test32();
void test64();
void test128();


int main()
{
    HashTable tbl(1000);
    tbl.add(5, 28);
    tbl.add(8, 34);
    tbl.add(10, 33);
    tbl.add(23, 465);
    tbl.add(24, 465);
    tbl.add(25, 465);
    tbl.add(26, 465);
    tbl.add(27, 465);
    tbl.add(28, 465);
    tbl.add(29, 465);
    std::cout << tbl.get(27).data << std::endl;

}

void test32()
{
    HashTable tbl(32);
    tbl.add(5, 28);
    tbl.add(8, 34);
    tbl.add(10, 33);
    tbl.add(23, 465);
    tbl.add(24, 465);
    tbl.add(25, 465);
    tbl.add(26, 465);
    tbl.add(27, 465);
    tbl.add(28, 465);
    tbl.add(29, 465);
    
}