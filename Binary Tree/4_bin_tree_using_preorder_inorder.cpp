// @author Soumya
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// search function
// Time: O(n) | Space: O(1)
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == curr)
            return i;

    return -1;
}

// build a tree using preorder & inorder
// Time: O(n^2) worst case (linear search() called once per node; would be O(n)
// with a value->index hashmap instead) | Space: O(n) tree + O(h) recursion stack
Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;

    if (start > end)
        return NULL;

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);

    if (start == end)
        return node;

    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

// print inorder for verification
// Time: O(n) | Space: O(h) recursion stack
void inorderPrint(Node *root)
{
    if (root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    /* tree built from the arrays above:
         1
        / \
       2   3
      /   /
     4   5
    */

    Node *node = buildTree(preorder, inorder, 0, 4);

    inorderPrint(node);

    return 0;
}
