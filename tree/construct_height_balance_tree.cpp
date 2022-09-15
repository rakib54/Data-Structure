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

Node* height_balance_tree(int l,int r,int arr[])
{
    if(l > r) return NULL;
    int mid = l + (r - l)/2;
    Node *newNode = new Node(arr[mid]);
    newNode->left = height_balance_tree(l,mid-1,arr);
    newNode->right = height_balance_tree(mid+1,r,arr);

    return newNode;
}

void level_order(Node *root)
{
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* parent = q.front();
        q.pop();
        cout<<parent->val<<" ";
        if(parent->left!=NULL) q.push(parent->left);
        if(parent->right!=NULL) q.push(parent->right);
    }
}

int main ()
{
    int n;
    cin>>n;
    int arr[n];
    Node *root = NULL;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    root = height_balance_tree(0,n-1,arr);
    level_order(root);


    return 0;
}

