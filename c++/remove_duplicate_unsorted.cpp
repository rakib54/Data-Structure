#include <iostream>
using namespace std;

int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
                for(int k=j;k<n;k++){
                    arr[k] = arr[k+1];
                }
                n--; // decreament n for decrease size of the array
                j--;// decreament j for decrease value of j
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
