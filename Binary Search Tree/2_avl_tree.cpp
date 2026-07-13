// @author Soumya
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    int height;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int getBalance(Node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// insert a node and rebalance on the way back up
Node *insertAVL(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertAVL(root->left, val);
    else if (val > root->data)
        root->right = insertAVL(root->right, val);
    else
        return root; // no duplicates

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // left left
    if (balance > 1 && val < root->left->data)
        return rightRotate(root);

    // right right
    if (balance < -1 && val > root->right->data)
        return leftRotate(root);

    // left right
    if (balance > 1 && val > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right left
    if (balance < -1 && val < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// search (same as plain BST search, height doesn't affect lookup)
Node *searchAVL(Node *root, int k)
{
    if (root == NULL || root->data == k)
        return root;

    if (root->data > k)
        return searchAVL(root->left, k);

    return searchAVL(root->right, k);
}

// leftmost (smallest) node of a subtree, used to find the inorder successor
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

// delete a node and rebalance on the way back up
Node *deleteAVL(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (val < root->data)
        root->left = deleteAVL(root->left, val);
    else if (val > root->data)
        root->right = deleteAVL(root->right, val);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            Node *temp = root->left ? root->left : root->right;

            delete root;
            return temp;
        }

        // two children: replace value with inorder successor, then delete the successor
        Node *successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteAVL(root->right, successor->data);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // left left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // left right
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // right left
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// inorder traversal (left-node-right)
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    for (int val : {30, 20, 40, 10, 25, 35, 50, 5, 1})
        root = insertAVL(root, val); // rebalances after every insert, e.g. 10/20/30 alone triggers a left rotation
    /*
                30
              /    \
            20      40
           /  \    /  \
          5   25  35  50
         / \
        1  10
    */

    inorder(root);
    cout << endl;
    // AVL trees stay balanced, so inorder is still sorted just like a plain BST

    root = deleteAVL(root, 25); // removes 25, which triggers a left-left rotation at 20
    /*
              30
            /    \
           5      40
          / \    /  \
         1  20  35  50
           /
         10
    */

    inorder(root);
    cout << endl;

    return 0;
}
