/**
 * @file hash_table.c
 * @author Mostafa Asaad (https://github.com/M0stafa077)
 * @brief Source file for implementing hash-table
 * data-structure that uses linear probing technique 
 * forr handling data collision.
 */
#include "hash_table.h"

/**
 * @brief A static software function hashes the value 
 *  to an index
 * @param table A pointer to the hash table.  
 * @param value An unsigned int value.
 * @return unsigned int The index to which the value is hashed.
 */
static unsigned int hash(Hash_Table_t* table, unsigned int value)
{
    return (unsigned int)value % (table -> table_size);
}

/**
 * @brief A software interface initializes a hashTable
 * 
 * @param table_size The size of the table.
 * @return Hash_Table_t* A pointer to the hashTable just
 * created.
 */
Hash_Table_t* HashTable_Init(unsigned int table_size)
{
    /* Let's first declare our table */
    Hash_Table_t* table = NULL;
    table = (Hash_Table_t *) malloc(sizeof(Hash_Table_t));
    if(NULL == table)
        { printf("Error allocating memory, please debug\n"); }
    table -> table_size = table_size;

    /* Now after we have declared the table, we define the table */
    table->table = calloc((table->table_size), sizeof(HashTable_Node_t));
    if(NULL == (table->table))
        { printf("Error allocating memory, please debug"); }
    
    return table;
}

/**
 * @brief A software interface inserts a value into
 * a hashTable
 * @param table A pointer to the hash table. 
 * @param value The value to be inserted.
 * @return true  If the value is successfully inserted.
 * @return false Error happened.
 */
bool HashTable_Insert(Hash_Table_t* table,unsigned int value)
{
    if(NULL == table)
    {
        printf("Invalid parameteres\n");
        return false;
    }
    else
    {
        /* Hash the value */
        unsigned int index = hash(table, value);
        
        /* Handle collision if exists */
        if(HASH_TABLE_ENTRY_OCCUPIED == table->table[index].is_occupied)
        { 
            if(table->table[index].value == value) // The value is already there
            {
                return true;
            }
            unsigned int counter = 0;
            while((HASH_TABLE_ENTRY_OCCUPIED == table->table[index].is_occupied))
            {
                if(counter > table->table_size)
                { 
                    printf("Unable to insert value [%d] into the hashTable\n", value);
                    return false; 
                }
                ++counter;
                index = (index + 1) % (table -> table_size); 
            }
        }
        
        /* Assign the data to the new inserted node */
        table->table[index].is_occupied = HASH_TABLE_ENTRY_OCCUPIED;
        table->table[index].value = value;
    }
    return true;
}

/**
 * @brief A software interface Searches for a value
 * in a hashTable
 * @param table A pointer to the hash table. 
 * @param value The value wanted
 * @return true The value is in the table
 * @return false The value is NOT in the table
 */
bool HashTable_Search(Hash_Table_t* table, unsigned int value)
{
    if(NULL == table)
    {
        printf("Invalid parameteres\n");
        return false;
    }
    else
    {
        unsigned int index = hash(table, value);
        unsigned int start_index = index; /* A variable to keep track of the starting index */
        while (HASH_TABLE_ENTRY_OCCUPIED == (table->table[index]).is_occupied)
        {
            /* Return the value if exists */
            if(table->table[index].value == value)
                { return true; }

            /* Keep searching for the value */
            index = (index + 1) % (table->table_size);
            if(index == start_index)
            {
                printf("Value not in the table\n");
                return false;
            }
        }
    }
}

/**
 * @brief A software interface prints the content of
 * a hashTable
 * @param table A pointer to the hash table.
 */
void HashTable_PrintTable(Hash_Table_t* table)
{
    if(NULL == table)
    {
        printf("Invalid parameteres\n");
        return;
    }
    else
    {
        unsigned int i = 0;
        printf("Table: [");
        for(i = 0; i < table->table_size; ++i)
        {
            if(HASH_TABLE_ENTRY_OCCUPIED == table->table[i].is_occupied)
                printf("%d, ", table->table[i].value);
            else
                printf("-, ");
        }
        printf("\b\b]\n");
    }
}

/**
 * @brief A software interface removes a value
 * from a hashTable
 * @param table A pointer to the hash table.
 * @param value The value to be removed
 * @return true If the value is successfully removed from the table.
 * @return false If the value is not already in the table.
 */
bool HashTable_Remove(Hash_Table_t* table, const unsigned int value)
{
    if(NULL == table)
    {
        printf("Invalid parameteres\n");
        return false;
    }
    else
    {
        unsigned int index = hash(table, value);
        unsigned int start_index = index; /* A variable to keep track of the starting index */
        while (HASH_TABLE_ENTRY_OCCUPIED == (table->table[index]).is_occupied)
        {
            if(table->table[index].value == value)
            {
                table->table[index].value = 0;
                table->table[index].is_occupied = HASH_TABLE_ENTRY_FREE;
                return true;
            }

            /* Keep searching for the value */
            index = (index + 1) % (table->table_size);
            if(index == start_index)
            {
                printf("Value not in the table\n");
                return false;
            }
        }
    }
}

/**
 * @brief A software interface frees a hashTable.
 * @param table A pointer to the hash table.
 */
void HashTable_Free(Hash_Table_t** table)
{
    if(NULL == table)
    {
        printf("Invalid parameteres\n");
        return;
    }
    else
    {
        free((*(table))->table);
        free(*table);
        (*(table))->table = NULL;
        (*table) = NULL;
    }
}