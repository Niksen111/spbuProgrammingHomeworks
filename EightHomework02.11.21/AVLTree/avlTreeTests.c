#include "avlTreeTests.h"
#include "avlTree.h"
#include <string.h>

bool testCreateAVLTreeRoot()
{
    AVLTreeRoot* root = createAVLTreeRoot();
    bool result = root != NULL;
    deleteTree(&root);

    return result;
}

bool testDeleteTree()
{
    AVLTreeRoot* root = createAVLTreeRoot();
    char s1[10] = "Abcdef";
    char s2[15] = "SearchTreeeee";
    char s3[5] = "Elle";
    addTreeNode(&root, 2, s2);
    addTreeNode(&root, 1, s1);
    addTreeNode(&root, 3, s3);
    deleteTree(&root);

    return root == NULL;
}

bool testAddTreeNode()
{
    AVLTreeRoot* root = createAVLTreeRoot();
    char s1[10] = "Abcdef";
    char s2[15] = "SearchTreeeee";
    char s3[5] = "Elle";
    char s4[5] = "Mrs";
    addTreeNode(&root, 2, s2);
    addTreeNode(&root, 1, s1);
    bool result = findValue(root, 2) != NULL
            && findValue(root, 4) == NULL;
    addTreeNode(&root, 4, s3);
    addTreeNode(&root, 1, s4);
    result = result && findValue(root, 4) != NULL
            && strcmp(findValue(root, 1), s4) == 0;
    deleteTree(&root);

    return result;
}

bool testFindValue()
{
    AVLTreeRoot* root = createAVLTreeRoot();
    char s1[10] = "Abcdef";
    char s2[15] = "SearchTreeeee";
    char s3[5] = "Elle";
    addTreeNode(&root, 2, s2);
    addTreeNode(&root, 1, s1);
    addTreeNode(&root, 3, s3);
    bool result = strcmp(findValue(root, 3), s3) == 0
            && findValue(root, 4) == NULL;
    deleteTree(&root);

    return result;
}

bool testIsKeyInTree()
{
    AVLTreeRoot* root = createAVLTreeRoot();
    char s1[10] = "Abcdef";
    char s2[15] = "SearchTreeeee";
    char s3[5] = "Elle";
    addTreeNode(&root, 2, s2);
    addTreeNode(&root, 1, s1);
    addTreeNode(&root, 3, s3);
    bool result = isKeyInTree(root, 2)
            && !isKeyInTree(root, 5)
            && isKeyInTree(root, 3);
    deleteTree(&root);

    return result;
}

bool testRemoveTheKey()
{
    AVLTreeRoot* root = createAVLTreeRoot();
    char s1[10] = "Kate";
    char s2[15] = "Jess";
    char s3[5] = "Elle";
    char s4[5] = "Mary";
    char s5[5] = "Eva";
    addTreeNode(&root, 2, s2);
    addTreeNode(&root, 1, s1);
    addTreeNode(&root, 4, s3);
    addTreeNode(&root, 3, s4);
    addTreeNode(&root, 5, s5);
    bool result = isKeyInTree(root, 3);
    removeEntry(&root, 3);
    result = result && !isKeyInTree(root, 3);
    deleteTree(&root);

    return result;
}

bool testAVLTree()
{
    return testCreateAVLTreeRoot() && testDeleteTree()
            && testAddTreeNode() && testFindValue()
            && testIsKeyInTree() && testRemoveTheKey();
} 