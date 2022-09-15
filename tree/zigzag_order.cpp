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


void zigzag_order(tree* root) {
    if (root == NULL){
        return;
    }

    stack<tree*> currentlevel;
    stack<tree*> nextlevel;

    currentlevel.push(root);

    bool lefttoright = true;
    while (!currentlevel.empty()) {

        tree* temp = currentlevel.top();
        currentlevel.pop();

        if (temp) {

            cout << temp->value << " ";
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}


void invert(tree *root){
    if(root == NULL) {
        return;
    }

    tree *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invert(root->left);
    invert(root->right);
}

int main ()
{
    tree *root = new tree(3);
    tree *a = new tree(9);
    tree *b = new tree(20);
    tree *c = new tree(15);
    tree *d = new tree(7);
    tree *e = new tree(10);
    tree *f = new tree(12);

    root->left = a;
    root->right = b;
    a->left = e;
    a->right = f;
    b->left = c;
    b->right = d;

//    invert(root);
    zigzag_order(root);

}
