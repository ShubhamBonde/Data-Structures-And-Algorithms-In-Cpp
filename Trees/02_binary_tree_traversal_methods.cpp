#include <iostream>
using namespace std;

struct BinaryTreeNode
{   
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

BinaryTreeNode* createNode(int data) 
{
    BinaryTreeNode * newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode)); 
    // Starting (BinaryTreeNode*) is just casting the void pointer returned by malloc into its ponter type.
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(BinaryTreeNode* root) 
{
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode* root)
{
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(BinaryTreeNode* root)
{
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    BinaryTreeNode *root = new BinaryTreeNode();
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left=createNode(6);
    root->right->right = createNode(7);
    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << "\n";
    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << "\n";
    cout << "Inorder Traversal: ";
    inOrder(root);
}

/*
Output:
Preorder Traversal: 1 2 4 5 3 6 7
Postorder Traversal: 4 5 2 6 7 3 1
Inorder Traversal: 4 2 5 1 6 3 7
*/