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

Node *rightRotate(Node *root)
{
    Node *newRoot = root->left;
    Node *T2 = newRoot->right;

    newRoot->right = root;
    root->left = T2;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

Node *leftRotate(Node *root)
{
    Node *newRoot = root->right;
    Node *T2 = newRoot->left;

    newRoot->left = root;
    root->right = T2;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

// fix the height and, if needed, rotate this node back into balance;
// used by both insertAVL and deleteAVL after they change a subtree
Node *rebalance(Node *root)
{
    root->height = 1 + max(height(root->left), height(root->right));

    if (height(root->left) - height(root->right) > 1) // left heavy
    {
        if (getBalance(root->left) >= 0) // left left
            return rightRotate(root);
        else // left right
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    else if (height(root->right) - height(root->left) > 1) // right heavy
    {
        if (getBalance(root->right) <= 0) // right right
            return leftRotate(root);
        else // right left
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
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

    return rebalance(root);
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

    return rebalance(root);
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
