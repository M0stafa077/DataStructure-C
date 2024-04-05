/*
 * @file binary_tree.h
 * @author Mostafa Asaad (https://github.com/M0stafa077)
 * @brief A module implementing binary tree data structure in C language.
 * @version 0.1
 * @date 2024-04-05
 */

/* --------------- Section : Includes --------------- */
#include <stdio.h>
#include <stdlib.h>
/* --------------- Section: Macro Declarations --------------- */

/* --------------- Section: Macro Functions Declarations --------------- */

/* --------------- Section: Data Type Declarations --------------- */
typedef struct node
{
    /**
     * @brief The value held in the tree node.
     */
    int vlaue;
    /**
     * @brief A pointer to the right node of the current node.
     */
    struct node* rightNode;
    /**
     * @brief A pointer to the left node of the current node.
     */
    struct node* leftNode;
} treeNode_t;

/*---------------  Section: Function Declarations --------------- */

/**
 * @brief A software interface creates a new tree node.
 * @param value The value held in the node.
 * @return treeNode_t* A pointer to the created node.
 */
treeNode_t* tree_CreateNode(int value);
/**
 * @brief A software interface sets the right node 
 * of the passed root.
 * @param root The root which right node needs to be set.
 * @param value The value held in the right node.
 */
void tree_SetRightNode(treeNode_t** root, int value);
/**
 * @brief A software interface sets the left node 
 * of the passed root.
 * @param root The root which left node needs to be set.
 * @param value The value held in the left node.
 */
void tree_SetLeftNode(treeNode_t** root, int value);
/**
 * @brief A software interface deletes the right node 
 * of the passed root 
 * @param root A pointer to the root's pointer.
 */
void tree_deleteRightNode(treeNode_t** root);
/**
 * @brief A software interface deletes the left node 
 * of the passed root 
 * @param root A pointer to the root's pointer.
 */
void tree_deleteLeftNode(treeNode_t** root);
/**
 * @brief A software interface prints the 
 * tree in pre order.
 * @param root The root of the binary tree.
 * @param level The level of the root.
 */
void tree_print(treeNode_t* root, int level);