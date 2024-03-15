//
// Created by HuaJuan on 2022/12/3.
//

#include "BST.h"
#include <climits>

BST::BST()
{
    root = nullptr;
    num = 0;
}

void BST::recurDel(BSTNode *next)
{
    if (next != nullptr)
    {
        if (next->left != nullptr)
        {
            recurDel(next->left);
        }
        if (next->right != nullptr)
        {
            recurDel(next->right);
        }
        delete next;
    }
}

BST::~BST()
{
    recurDel(root);
}

void BST::insert(int n)
{
    if (root == nullptr)
    {
        root = new BSTNode(n);
        num++;
    }
    else
    {
        BSTNode *temp = root;
        while (temp != nullptr)
        {
            if (temp->element == n)
            {
                return;
            }
            else if (n < temp->element)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new BSTNode(n);
                    num++;
                    return;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = new BSTNode(n);
                    num++;
                    return;
                }
                temp = temp->right;
            }
        }
    }
}

bool BST::exist(int n)
{
    BSTNode *temp = root;
    while (temp != nullptr)
    {
        if (temp->element == n)
        {
            return true;
        }
        else if (n < temp->element)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

void BST::remove(int n)
{
    BSTNode *temp = root;
    BSTNode *parNode = nullptr;
    int par = 0; //-1代表要删除的节点父节点在左侧，1代表要删除的节点父节点在右侧
    BSTNode *node = nullptr;
    while (temp != nullptr)
    {
        if (temp->element == n)
        {
            break;
        }
        else if (n < temp->element)
        {
            par = 1;
            parNode = temp;
            temp = temp->left;
        }
        else
        {
            par = -1;
            parNode = temp;
            temp = temp->right;
        }
    }
    if (temp == nullptr) //若没有找到节点
    {
        return;
    }
    else if (temp->left == nullptr && temp->right == nullptr) //节点无子节点
    {
        if (parNode == nullptr)
        {
            delete root;
            root = nullptr;
            num--;
        }
        else
        {
            if (par == 1)
            {
                delete temp;
                parNode->left = nullptr;
                num--;
            }
            else if (par == -1)
            {
                delete temp;
                parNode->right = nullptr;
                num--;
            }
        }
    }
    else if (temp->left != nullptr && temp->right != nullptr) //节点有两个子节点
    {
        if (parNode == nullptr)
        {
            node = root->left;
            BSTNode *parNode = root;
            while (node->right != nullptr)
            {
                parNode = node;
                node = node->right;
            }
            root->element = node->element;
            if (parNode == root)
            {
                root->left = node->left;
            }
            else
            {
                parNode->right = node->left;
            }
            delete node;
            num--;
        }
        else
        {
            if (par == 1)
            {
                node = temp->right;
                BSTNode *parNode = temp;
                while (node->left != nullptr)
                {
                    parNode = node;
                    node = node->left;
                }
                temp->element = node->element;
                if (parNode == temp)
                {
                    parNode->right = node->right;
                }
                else
                {
                    parNode->left = node->right;
                }
                delete node;
                num--;
            }
            else if (par == -1)
            {
                node = temp->left;
                BSTNode *parNode = temp;
                while (node->right != nullptr)
                {
                    parNode = node;
                    node = node->right;
                }
                temp->element = node->element;
                if (parNode == temp)
                {
                    parNode->left = node->left;
                }
                else
                {
                    parNode->right = node->left;
                }
                delete node;
                num--;
            }
        }
    }
    else if (temp->right == nullptr) //节点只有一个左子节点
    {
        if (parNode == nullptr)
        {
            root = temp->left;
            delete temp;
        }
        else
        {
            parNode->left = temp->left;
            delete temp;
            num--;
        }
    }
    else //节点只有一个右子节点
    {
        if (parNode == nullptr)
        {
            root = temp->right;
            delete temp;
        }
        else
        {
            parNode->right = temp->right;
            delete temp;
            num--;
        }
    }
    return;
}

int BST::findMin(BSTNode *node)
{
    int min = INT_MAX;
    BSTNode *temp = node;
    while (temp != nullptr)
    {
        min = temp->element;
        temp = temp->left;
    }
    return min;
}

int BST::findMax(BSTNode *node)
{
    int max = INT_MIN;
    BSTNode *temp = node;
    while (temp != nullptr)
    {
        max = temp->element;
        temp = temp->right;
    }
    return max;
}

int BST::recurFloor(int n, BSTNode *node)
{
    int result = INT_MIN;
    if (node != nullptr)
    {
        BSTNode *temp = node;
        while (temp != nullptr)
        {
            if (n == temp->element)
            {
                return n;
            }
            else if (n < temp->element)
            {
                break;
            }
            else
            {
                result = temp->element;
                temp = temp->right;
            }
        }
        if (temp != nullptr)
        {
            int compare = recurFloor(n, temp->left);
            if (result < compare && compare <= n)
            {
                result = compare;
            }
        }
    }
    return result;
}

int BST::floor(int n)
{
    int result = INT_MIN;
    result = recurFloor(n, root);
    return result;
}

int BST::size() const
{
    return num;
}