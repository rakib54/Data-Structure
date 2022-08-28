#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int value;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int val)
    {
        value = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"   ";
    }
}

void printTree(treeNode *root, int level)
{
    if(root == NULL) // when tree is empty
    {
        return;
    }
    // case 1: leftChild/rightChild is not a root
    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        cout<<root->value<<endl;
    }
    // case 2: left/right is root
    else
    {
        cout<<endl;
        spacePrint(level);
        cout<<"Root: "<<root->value<<endl;
    }

    if(root->leftChild !=NULL)
    {
        spacePrint(level);
        cout<<"Left: ";
        printTree(root->leftChild, level+1);
    }

    if(root->rightChild !=NULL)
    {
        spacePrint(level);
        cout<<"Right: ";
        printTree(root->rightChild, level+1);
    }
}



int main ()
{
    int n;
    cin>>n;
    treeNode *allNodes[n];

    for(int i=0; i<n; i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for(int i=0; i<n; i++)
    {
        int val,left,right;
        cin>>val>>left>>right;
        allNodes[i]->value = val;

        if(left!=-1)
        {
            allNodes[i]->leftChild = allNodes[left];
        }
        if(right!=-1)
        {
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    printTree(allNodes[0],0);


    return 0;
}

/*
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
*/
