#include "BSTree.h"
#include <iostream>
using namespace std;

int main()
{
    const int size = 40;
    int numbers[size];

    srand(time(nullptr));

    bool isDup;

    for (int i = 0; i < size; ++i)
    {
        do
        {
            isDup = false;
            numbers[i] = rand() % 100;

            for (int j = 0; j < i; j++)
            {
                if (numbers[i] == numbers[j])
                {
                    isDup = true;
                    break;
                }
            }
        } while (isDup);
    }

    cout << "Generated numbers with original order:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    BSTree T;

    for (int i = 0; i < size; i++)
    {
        BSTree::TreeNode *newNode = new BSTree::TreeNode;
        newNode->value = numbers[i];
        newNode->left = nullptr;
        newNode->right = nullptr;
        T.insertNode(T.root, newNode);
    }

    cout << "BST (Pre-order): " << endl;
    T.displayPreOrder(T.root);
    cout << endl;

    cout << "BST (Post-order): " << endl;
    T.displayPostOrder(T.root);
    cout << endl;

    int deleteNum;
    cout << "Enter the value to delete from the tree: " << endl;
    cin >> deleteNum;

    cout << "Deleting value: " << deleteNum << endl;
    T.deleteNode(deleteNum, T.root);

    cout << "BST (In-order): " << endl;
    T.displayInOrder(T.root);
    cout << endl;

    int minVal, maxVal;
    T.findMin(T.root, minVal);
    if (minVal != -1)
    {
        cout << "Minimum value: " << minVal << endl;
    }
    else
    {
        cout << "Minimum value not found." << endl;
    }

    T.findMax(T.root, maxVal);
    if (maxVal != -1)
    {
        cout << "Maximum value: " << maxVal << endl;
    }
    else
    {
        cout << "Maximum value not found." << endl;
    }

    return 0;
}
