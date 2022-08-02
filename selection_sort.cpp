#include <iostream>
using namespace std;

int main (){
    int n,cnt=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        int index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[index]){
                index =j;
            }
        }
        if(i !=index){
            swap(arr[i],arr[index]);
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Total swap "<<cnt<<endl;

    return 0;
}

