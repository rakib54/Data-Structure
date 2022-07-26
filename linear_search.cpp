#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,flag=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    char c;
    cout<<"Do You want to search(Y/N)";
    cin>>c;

    while(toupper(c) == 'Y'){
        int num;
        cout<<"Your Searching number:";
        cin>>num;
        for(int i=0;i<n;i++){
            if(arr[i] == num){
                cout<<"Found at "<<i<<" th index"<<endl;
                flag = 1;
            }
        }
        if(flag == 0){
            cout<<"Not found"<<endl;
        }
        cout<<"Do You Still want to search(Y/N)";
        cin>>c;
    }


    return 0;
}
