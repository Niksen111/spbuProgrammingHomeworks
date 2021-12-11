#pragma once
#include <stdbool.h>

// root of tree
typedef struct Dictionary Dictionary;

// create empty Dictionary
Dictionary* createDictionary();

// removes the entire Tree
void deleteDictionary(Dictionary** dictionary);

// adds a new node to the tree or replaces the value
// if a node with this key exists
void addTreeNode(AVLTreeRoot** root, int key, char* value);

// finds a value for a given key in the dictionary
char* findValue(AVLTreeRoot* root, int key);

// checks if the given key is in the dictionary
bool isKeyInTree(AVLTreeRoot* root, int key);

// Deletes the given key and its associated value from the dictionary
void removeEntry(AVLTreeRoot** root, int key);