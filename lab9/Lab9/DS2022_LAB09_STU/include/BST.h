//
// Created by HuaJuan on 2022/12/3.
//

#ifndef DS2022_LAB09_TA_BST_H
#define DS2022_LAB09_TA_BST_H

#include "BSTNode.h"

class BST
{
public:
    void insert(int n);

    bool exist(int n);

    void remove(int n);

    [[nodiscard]] int size() const;

    int floor(int n);

    BST();

    ~BST();

    void recurDel(BSTNode *next);

    int findMax(BSTNode*node);

    int findMin(BSTNode*node);

    int recurFloor(int n,BSTNode*node);

private:
    int num;
    BSTNode *root;
};

#endif // DS2022_LAB09_TA_BST_H
