//
// Created by HuaJuan on 2022/12/3.
//

#ifndef DS2022_LAB09_TA_BSTNODE_H
#define DS2022_LAB09_TA_BSTNODE_H

class BSTNode {
public:
    int element;
    BSTNode *left{};
    BSTNode *right{};

    explicit BSTNode(int element) : element(element) {}
};

#endif //DS2022_LAB09_TA_BSTNODE_H
