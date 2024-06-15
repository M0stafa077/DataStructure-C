/**
 * @file hashTable_Quadratic.h
 * @author Mostafa Asaad (https://github.com/M0stafa077)
 * @brief Header file for implementing hash_quad-table
 * data-structure that uses Quadratic probing technique 
 * for handling data collision.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* ------------------------ Defines ------------------------ */
#define HASH_TABLE_ENTRY_OCCUPIED       true
#define HASH_TABLE_ENTRY_FREE           false
#define HASH_TABLE_VALUE_NOT_FOUND      false
/* ------------------------ Data-Types ------------------------ */
typedef struct 
{
    unsigned int value;
    bool is_occupied;
} HashTable_Node_t;

typedef struct
{
    HashTable_Node_t* table;
    unsigned int table_size;
} Hash_Table_t;

/* ------------------------ Software APIs ------------------------ */

/**
 * @brief A software interface initializes a hashTable
 * 
 * @param table_size The size of the table.
 * @return Hash_Table_t* A pointer to the hashTable just
 * created.
 */
Hash_Table_t* HashTable_Quad_Init(unsigned int table_size);
/**
 * @brief A software interface inserts a value into
 * a hashTable
 * @param table A pointer to the hash_quad table. 
 * @param value The value to be inserted.
 * @return true  If the value is successfully inserted.
 * @return false Error happened.
 */
bool HashTable_Quad_Insert(Hash_Table_t* table,unsigned int value);
/**
 * @brief A software interface Searches for a value
 * in a hashTable
 * @param table A pointer to the hash_quad table. 
 * @param value The value wanted
 * @return true The value is in the table
 * @return false The value is NOT in the table
 */
bool HashTable_Quad_Search(Hash_Table_t* table, unsigned int value);
/**
 * @brief A software interface prints the content of
 * a hashTable
 * @param table A pointer to the hash_quad table.
 */
void HashTable_Quad_PrintTable(Hash_Table_t* table);
/**
 * @brief A software interface removes a value
 * from a hashTable
 * @param table A pointer to the hash_quad table.
 * @param value The value to be removed
 * @return true If the value is successfully removed from the table.
 * @return false If the value is not already in the table.
 */
bool HashTable_Quad_Remove(Hash_Table_t* table, const unsigned int value);
/**
 * @brief A software interface frees a hashTable.
 * @param table A pointer to the hash_quad table.
 */
void HashTable_Quad_Free(Hash_Table_t** table);
