#include "BSTree.h"
#include <iostream>
using namespace std;

BSTree::BSTree()
{
    root = nullptr;
}

BSTree::~BSTree()
{
}

void BSTree::insertNode(TreeNode *&nodePtr, TreeNode *newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insertNode(nodePtr->left, newNode);
    else
        insertNode(nodePtr->right, newNode);
}

int BSTree::searchNode(int num)
{
    TreeNode *nodePtr = root;
    while (nodePtr)
    {
        if (nodePtr->value == num)
            return true;
        else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

void BSTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (nodePtr == nullptr)
    {
        cout << "Empty tree" << std::endl;
        return;
    }
    else if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

void BSTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
    {
        cout << "Empty tree" << endl;
        return;
    }

    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }

    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }

    else
    {

        tempNodePtr = nodePtr->right;

        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;

        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;

        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

void BSTree::display(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        display(nodePtr->left);
        cout << nodePtr->value << " ";
        display(nodePtr->right);
    }
}

void BSTree::findMin(TreeNode *nodePtr, int &minValue)
{
    if (nodePtr == nullptr)
    {
        cout << "Error";
    }

    while (nodePtr->left != nullptr)
    {
        nodePtr = nodePtr->left;
    }

    minValue = nodePtr->value;
}

void BSTree::findMax(TreeNode *nodePtr, int &maxValue)
{
    if (nodePtr == nullptr)
    {
        cout << "Error";
        return;
    }

    while (nodePtr->right != nullptr)
    {
        nodePtr = nodePtr->right;
    }

    maxValue = nodePtr->value;
}

void BSTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

void BSTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void BSTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}
