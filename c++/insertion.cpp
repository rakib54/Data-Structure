#include<iostream>
using namespace std;

int main(){
    int arr[20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos,value;
    cin>>pos>>value;
    if(pos < 0 || pos>n){
        cout<<"Invalid position"<<endl;
    }
    else {
//        for(int i=n-1;i>=pos;i--){
//            arr[i+1] = arr[i];
//        }
        arr[n] = arr[pos];
        arr[pos] = value;


    }
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
