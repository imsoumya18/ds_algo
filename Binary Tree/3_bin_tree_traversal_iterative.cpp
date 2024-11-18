// @author Soumya
#include <iostream>
#include <stack>
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

// iterative preoreder traversal (node-left-right)
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();

        cout << node->data << " ";

        if (node->right)
            st.push(node->right);

        if (node->left)
            st.push(node->left);
    }
}

// iterative inorder traversal (left-node-right)
void inorder(struct Node *root)
{
    stack<Node *> st;
    Node *node = root;

    while (true)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;

            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}

// iterative postorder traversal (left-right-node)
void postorder(struct Node *root)
{
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left)
            st1.push(root->left);

        if (root->right)
            st1.push(root->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    /*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
    */

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
}
