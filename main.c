#include <stdio.h>
#include "Hash-Table/Linear-Probing/hash_table.h"


int main()
{
    Hash_Table_t* table = HashTable_Init(10);
    HashTable_Insert(table, 5);
    HashTable_Insert(table, 6);
    HashTable_Insert(table, 7);
    HashTable_Insert(table, 8);
    HashTable_Insert(table, 1000);
    // printf("%d\n", HashTable_Search(table, 1000));
    HashTable_PrintTable(table);
    HashTable_Remove(table, 5);
    HashTable_Remove(table, 1000);
    HashTable_PrintTable(table);
    
    return 0;
}

