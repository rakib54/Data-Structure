#include <bits/stdc++.h>
using namespace std;

class tree
{
public:
    int value;
    tree *left;
    tree *right;

    tree(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

bool isMirror (tree *a, tree* b)
{
    if(a==NULL && b==NULL)
    {
        return true;
    }
    if(a==NULL || b==NULL)
    {
        return false;
    }
    return a->value == b->value && isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);

}

bool isSymmetric(tree *root)
{
    return isMirror(root, root);
}


// average_level of tree
void average_level(tree* root)
{
    queue<tree*> q;
    q.push(root);

    while (!q.empty())
    {
        int sum = 0, count = 0;
        queue<tree*> temp;
        while (!q.empty())
        {
            tree* n = q.front();
            q.pop();
            sum += n->value;
            count++;
            if (n->left != NULL)
                temp.push(n->left);
            if (n->right != NULL)
                temp.push(n->right);
        }
        q = temp;
        cout <<(sum * 1.0 / count)<<" ";
    }
}

// unival tree
bool is_unival(tree* root)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->left && root->left->value != root->value)
    {
        return false;
    }
    if(root->right && root->right->value != root->value)
    {
        return false;
    }
    return is_unival(root->left) && is_unival(root->right);
}

// find second minimum

int findSecondMinimumValue(Node* root)
{
    queue<Node*>q;
    q.push(root);
    vector<int> v;
    while(!q.empty())
    {
        v.push_back(q.front()->value);
        if(q.front()->left)
        {
            q.push(q.front()->left);
        }
        if(q.front()->right)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
    sort(v.begin(),v.end());
    int result=-1;
    for(int i=1; i<v.size(); i++)
    {
        if(v[i]!=v[0])
        {
            return v[i];
        }
    }
    return result;
}


int main ()
{
    tree *root = new tree(3);
    tree *a = new tree(9);
    tree *b = new tree(20);
    tree *c = new tree(15);
    tree *d = new tree(7);

    root->left = a;
    root->right = b;
    b->left = c;
    b->right = d;

    if(isSymmetric(root))
    {
        cout<<"Symmetric"<<endl;
    }
    else cout<<"Not Symmetric"<<endl;

    average_level(root);
    cout<<endl;
    cout<<findSecondMinimumValue(root);

}
