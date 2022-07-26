#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int num;
    cin>>num;
    bool found = false;
    for(int i=0;i<n;i++){
        if(arr[i] == num){
            found = true;
            cout<<"Found at: "<<i<<endl;
        }
    }
    if(!found) cout<<"Not Found!!"<<endl;

    return 0;
}
