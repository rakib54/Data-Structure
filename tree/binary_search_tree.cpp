#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// with reference
void insert_bst(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    if (val < root->val)
        insert_bst(root->left, val);
    else
        insert_bst(root->right, val);
}

// return Node
Node *insert_bst_(Node *root, int val)
{
    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    if (val < root->val)
        root->left = insert_bst_(root->left, val);
    else
        root->right = insert_bst_(root->right, val);
    return root;
}

void level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();
        cout << parent->val << " ";
        if (parent->left != NULL)
            q.push(parent->left);
        if (parent->right != NULL)
            q.push(parent->right);
    }
}

int main()
{
    int n;
    cin >> n;

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = insert_bst_(root, value);
    }
    level_order(root);

    return 0;
}
