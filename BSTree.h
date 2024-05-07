#ifndef BSTree_H
#define BSTree_H

class BSTree
{
public:
    struct TreeNode
    {
        int value;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;

public:
    BSTree();
    ~BSTree();
    void insertNode(TreeNode *&, TreeNode *);
    int searchNode(int);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void display(TreeNode *) const;
    void findMin(TreeNode *, int &);
    void findMax(TreeNode *, int &);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
};

#endif 
