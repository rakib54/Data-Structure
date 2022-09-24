#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Node(int val){
        this->value = val;
        left = NULL;
        right = NULL;
    }
};

// print every root to leaf Node
void root_to_leaf(Node *root, vector<vector<int>>&v,vector<int>path){
    if(!root) return;
    path.push_back(root->value);
    if(!root->left && !root->right){
        v.push_back(path);
        return;
    }
    root_to_leaf(root->left,v,path);
    root_to_leaf(root->right,v,path);
}

// checking palindrome
bool palindrome(vector<int>v,string s){
    string str = "";
    for(auto i:v){
        str+= s[i];
    }
    string rev = str;
    reverse(rev.begin(), rev.end());
    if(str == rev){
        return true;
    }
    return false;
}

int main () {
    string s;
    cin>>s;
    int n;
    cin>>n;
    Node *root = new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *current_root = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1 = NULL;
        Node *n2 = NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);

        current_root->left = n1;
        current_root->right = n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    vector<vector<int>>v;
    vector<int> curr_path;
    root_to_leaf(root,v,curr_path);

    int count = 0;
    for(vector<int> i:v){
        if (palindrome(i,s)){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}

/*
ABABDBACBBCDBAEBDBAA
0
1 3
4 8 2 7
14 -1 5 -1 -1 -1 11 9
-1 16 -1 6 10 -1 -1 19
17 15 -1 -1 -1 12 -1 -1
18 -1 -1 -1 13 -1
-1 -1 -1 -1

5
*/
