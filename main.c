#include <stdio.h>
// #include "Hash-Table/Linear-Probing/hash_table.h"
#include "Hash-Table/Quadratic-Probing/hashTable_Quadratic.h"

#define HASH_TABLE_SIZE    10

int main()
{
    Hash_Table_t* table = HashTable_Quad_Init(HASH_TABLE_SIZE);
    HashTable_Quad_Insert(table, 10);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 20);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 30);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 40);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 50);
    HashTable_Quad_PrintTable(table);

    HashTable_Quad_Insert(table, 60);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 70);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 80);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 90);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 100);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Insert(table, 110);
    HashTable_Quad_PrintTable(table);
    HashTable_Quad_Remove(table, 5);
    HashTable_Quad_Remove(table, 1000);
    HashTable_Quad_PrintTable(table);
    
    HashTable_Quad_Free(&table);
    HashTable_Quad_PrintTable(table);

    return 0;
}

