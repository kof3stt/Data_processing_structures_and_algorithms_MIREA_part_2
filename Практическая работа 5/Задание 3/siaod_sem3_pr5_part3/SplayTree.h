#include "BinFile.h"


struct element
{
    string key;
    int position = INT_MIN;
    element() {}
    element(string key, int position) : key(key), position(position) {}
};

struct SplayTree
{
    element data;
    SplayTree* left = nullptr;
    SplayTree* right = nullptr;
    SplayTree(element elem) : data(elem) {}
    SplayTree() {};
};

SplayTree* LeftRotation(SplayTree* root);
SplayTree* RightRotation(SplayTree* root);
SplayTree* splay(SplayTree* root, string key);
SplayTree* insertToSplay(SplayTree* root, element elem);
int delFromSplayTree(SplayTree*& root, string key);
void print_tree(SplayTree* tree, int level);
int& find_element(SplayTree*& root, string key);
