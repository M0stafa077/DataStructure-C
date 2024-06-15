#include <stdio.h>
#include "Hash-Table/Linear-Probing/hash_table.h"

#define HASH_TABLE_SIZE    10

int main()
{
    Hash_Table_t* table = HashTable_Init(HASH_TABLE_SIZE);
    HashTable_Insert(table, 10);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 20);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 30);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 40);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 50);
    HashTable_PrintTable(table);

    HashTable_Insert(table, 60);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 70);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 80);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 90);
    HashTable_PrintTable(table);
    HashTable_Insert(table, 100);
    HashTable_PrintTable(table);
        HashTable_Insert(table, 110);
    HashTable_PrintTable(table);
    // HashTable_PrintTable(table);
    // HashTable_Remove(table, 5);
    // HashTable_Remove(table, 1000);
    // HashTable_PrintTable(table);
    
    // HashTable_Free(&table);
    // HashTable_PrintTable(table);

    return 0;
}

