#include <iostream>
#include "HashTable.h"
#include <chrono>

void test32();
void test64();
void test128();


int main()
{
    HashTable tbl(1000);
    tbl.add(135, "Andreev Vladimir Afanasievich");
    tbl.add(3054, "Andtonov Anton Antonovich");
    tbl.add(3200, "Andtonov Anton Antonovich");
    tbl.add(54, "Andtonov Anton Antonovich");
    tbl.add(1024, "Andtonov Anton Antonovich");
    tbl.add(1113, "Andtonov Anton Antonovich");
    tbl.add(1121, "Andtonov Anton Antonovich");
    tbl.add(1131, "Andtonov Anton Antonovich");
    tbl.add(3313, "Andtonov Anton Antonovich");
    tbl.add(1133, "Andtonov Anton Antonovich");
    std::cout << tbl.get(1135428).fio << std::endl;
    std::cout << tbl.get(3200).key << std::endl;
    std::cout << tbl.get(54).key << std::endl;
    tbl.remove(1113);
    std::cout << tbl.get(1113).key << std::endl;
    tbl.update(3313, "UPDATED");
    std::cout << tbl.get(3313).fio.c_str() << std::endl;



    tbl.print();

    std::cout << "--------------------\n";

    test32();

    std::cout << "-------------------------\n";

    test64();

    std::cout << "----------------------------\n";

    test128();

}

void test32()
{
    std::string fioBase = "FIO";
    HashTable tbl(32);
    for (int i = 0; i < 64; i++)
    {
        tbl.add(i + 20000, fioBase + std::to_string(i));
    }
    auto start = std::chrono::steady_clock::now();
    auto element = tbl.get(20016);
    auto stop = std::chrono::steady_clock::now();
    std::cout << element.key << ": " << element.fio.c_str() << std::endl;
    std::cout << "took: " << std::chrono::duration<double>(stop - start).count() << std::endl;
}

void test64()
{
    std::string fioBase = "FIO";
    HashTable tbl(64);
    for (int i = 0; i < 64; i++)
    {
        tbl.add(i + 352, fioBase + std::to_string(i));
    }
    auto start = std::chrono::steady_clock::now();
    auto element = tbl.get(381);
    auto stop = std::chrono::steady_clock::now();
    std::cout << element.key << ": " << element.fio.c_str() << std::endl;
    std::cout << "took: " << std::chrono::duration<double>(stop - start).count() << std::endl;

}

void test128()
{
    std::string fioBase = "FIO";
    HashTable tbl(128);
    for (int i = 0; i < 150; i++)
    {
        tbl.add(i + 1564, fioBase + std::to_string(i));
    }
    auto start = std::chrono::steady_clock::now();
    auto element = tbl.get(1600);
    auto stop = std::chrono::steady_clock::now();
    std::cout << element.key << ": " << element.fio.c_str() << std::endl;
    std::cout << "took: " << std::chrono::duration<double>(stop - start).count() << std::endl;
}