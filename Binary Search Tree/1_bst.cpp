// @author Soumya
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// insert node in BST
Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// search in BST
Node *searchBST(Node *root, int k)
{
    if (root == NULL)
        return NULL;

    if (root->data == k)
        return root;

    if (root->data > k)
        return searchBST(root->left, k);

    return searchBST(root->right, k);
}

// inorder traversal (left-node-right)
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// leftmost (smallest) node of a subtree, used to find the inorder successor
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

// delete a node from BST
Node *deleteBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (val < root->data)
        root->left = deleteBST(root->left, val);
    else if (val > root->data)
        root->right = deleteBST(root->right, val);
    else
    {
        // node found: handle 0, 1 and 2 children cases
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // two children: replace value with inorder successor, then delete the successor
        Node *successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteBST(root->right, successor->data);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    /*
            5
           / \
          1   7
           \
            3
           / \
          2   4
    */

    inorder(root);
    cout << endl;
    // inorder of BST is always sorted

    root = deleteBST(root, 2); // leaf node
    /*
            5
           / \
          1   7
           \
            3
             \
              4
    */
    inorder(root);
    cout << endl;

    root = deleteBST(root, 3); // node with a single child (4)
    /*
            5
           / \
          1   7
           \
            4
    */
    inorder(root);
    cout << endl;

    root = deleteBST(root, 5); // node with two children, replaced by inorder successor (7)
    /*
            7
           /
          1
           \
            4
    */
    inorder(root);
    cout << endl;

    return 0;
}
