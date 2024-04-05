#include "binary_tree.h"
/* ------- Section : Helper functions Declaration ---------*/

/**
 * @brief A static helper function prints some
 * indentation 
 * @param tabNumbers The number of tabs for indentation
 */
static void indent(int tabNumbers);

/* -------- Section : Functions Definitions -------- */

/**
 * @brief A software interface creates a new tree node.
 * @param value The value held in the node.
 * @return treeNode_t* A pointer to the created node.
 */
treeNode_t* tree_CreateNode(int value)
{
    treeNode_t* node;
    node = (treeNode_t *) malloc(sizeof(treeNode_t));

    if(NULL != node)
    {
        /* Set the value */
        node->vlaue = value;
        /* Set the right node to be null */
        node->rightNode = NULL;
        /* Set the left node to be null */
        node->leftNode = NULL;
    }
    return node;
}
/**
 * @brief A software interface sets the right node 
 * of the passed root.
 * @param root The root which right node needs to be set.
 * @param value The value held in the right node.
 */
void tree_SetRightNode(treeNode_t** root, int value)
{
    /* Create new Node */
    treeNode_t* righrNode = tree_CreateNode(value);
    /* Set the right node of the root */
    (*root)->rightNode = righrNode;
}
/**
 * @brief A software interface sets the left node 
 * of the passed root.
 * @param root The root which left node needs to be set.
 * @param value The value held in the left node.
 */
void tree_SetLeftNode(treeNode_t** root, int value)
{
    /* Create new Node */
    treeNode_t* leftNode = tree_CreateNode(value);
    /* Set the left node of the root */
    (*root)->leftNode = leftNode;
}
/**
 * @brief A software interface prints the 
 * tree in pre order.
 * @param root The root of the binary tree.
 * @param level The level of the root.
 */
void tree_print(treeNode_t* root, int level)
{
    if(NULL == root)
    {
        indent(level);
        printf("<empty>\n");
        return;
    }
    /* Print the root */
    indent(level);
    printf("Value: %d\n", root->vlaue);

    /* Print the left node of the root */
    indent(level);
    printf("Left: \n");
    tree_print(root->leftNode, level + 1);

    /* Print the right node of the root */
    indent(level);
    printf("Right: \n");
    tree_print(root->rightNode, level + 1);
}
/**
 * @brief A software interface deletes the right node 
 * of the passed root 
 * @param root A pointer to the root's pointer.
 */
void tree_deleteRightNode(treeNode_t** root)
{
    /* To be continued '/ */
    /*
     * **************************** * 
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
    */
}
/**
 * @brief A software interface deletes the left node 
 * of the passed root 
 * @param root A pointer to the root's pointer.
 */
void tree_deleteLeftNode(treeNode_t** root)
{
    /* To be continued '/ */
    /*
     * **************************** * 
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
     * **************************** *
    */
}
/* ------- Section : Helper functions Definitions ---------*/

/**
 * @brief A static helper function prints some
 * indentation 
 * @param tabNumbers The number of tabs for indentation
 */
static void indent(int tabNumbers)
{
    for(int i = 0; i < tabNumbers; ++i)
    {
        printf("\t");
    }
}