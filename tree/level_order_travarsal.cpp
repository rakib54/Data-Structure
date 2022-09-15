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

void spacePrint(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"  ";
    }
}

void print(tree *root, int level)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->value<<endl;
    }

    else
    {
        cout<<endl;
        spacePrint(level);
        cout<<"Root: "<<root->value<<endl;
    }

    if(root->left !=NULL)
    {
        spacePrint(level);
        cout<<"Left: ";
        print(root->left, level+1);
    }

    if(root->right !=NULL)
    {
        spacePrint(level);
        cout<<"Right: ";
        print(root->right, level+1);
    }
}

void level_order(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    queue <tree*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        tree *chkNode = q.front();
        q.pop();

        if(chkNode!=NULL)
        {
            cout<<chkNode->value<<" ";
            if(chkNode->left != NULL)
            {
                q.push(chkNode->left);
            }
            if(chkNode->right != NULL)
            {
                q.push(chkNode->right);
            }
        }
        else
        {
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

void level_order_reverse(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    queue <tree*> q;
    stack <tree*> st;

    q.push(root);

    while(!q.empty())
    {
        tree *chkNode = q.front();
        q.pop();
        st.push(chkNode);
        if(chkNode!=NULL)
        {
            if(chkNode->right!=NULL)
            {
                q.push(chkNode->right);
            }
            if(chkNode->left!=NULL)
            {
                q.push(chkNode->left);
            }
        }

    }

    while(!st.empty())
    {
        tree * chkNode = st.top();
        cout<<chkNode->value<<" ";
        st.pop();
    }
}

//bool isSame(Node* root1, Node* root2)
//{
//    if(root1==NULL && root2==NULL)
//    {
//        return true;
//    }
//    if(root1==NULL || root2==NULL)
//    {
//        return false;
//    }
//    if(root1->val != root2->val) return false;
//
//    return isSame(root1->left && root2->left) && isSame(root1->right && root2->right);
//
//}

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

// swap left right child
tree* invert_tree(tree *root)
{
    if(root == NULL)
    {
        return root;
    }

    tree *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invert_tree(root->left);
    invert_tree(root->right);
    return root;
}

// sum of tilt
int Tilt(tree* root, int &result){
    if(root == NULL)
    {
        return 0;
    }
    int left = Tilt(root->left,result);
    int right = Tilt(root->right,result);
    result += abs(left - right);

    return  (left + right + root->value);
}



int findTilt(tree *root) {
    int result =0;
    Tilt(root,result);
    return result;
}


void average_level(tree* root){
    queue<tree*> q;
    q.push(root);

    while (!q.empty()) {

        int sum = 0, count = 0;
        queue<tree*> temp;
        while (!q.empty()) {
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
        cout << (sum * 1.0 / count) << " ";
    }
}

int main ()
{
    int n;
    cin>>n;
    tree *allNodes[n];
    for(int i=0; i<n; i++)
    {
        allNodes[i] = new tree(-1);
    }

    for(int i=0; i<n; i++)
    {
        int val,left,right;
        cin>>val>>left>>right;
        allNodes[i]->value = val;

        if(left!=-1)
        {
            allNodes[i]->left = allNodes[left];
        }

        if(right!=-1)
        {
            allNodes[i]->right = allNodes[right];
        }
    }
    invert_tree(allNodes[0]);

    print(allNodes[0],0);
    level_order(allNodes[0]);
    cout<<endl;
    level_order_reverse(allNodes[0]);
    if(isSymmetric(allNodes[0]))
    {
        cout<<endl<<"Tree is symmetric!"<<endl;
    }
    else cout<<"NOT symmetric!"<<endl;

    cout<<findTilt(allNodes[0])<<endl;
    average_level(allNodes[0]);



}

/*
5
3 9 20
9 -1 -1
20 15 7
15 -1 -1
7 -1 -1

9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1





7
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 -1 -1
6 -1 -1

*/
