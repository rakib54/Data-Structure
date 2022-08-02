#include <iostream>
using namespace std;

void printArray(int n,int arr[]){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        cout<<"iteration :"<<i<<endl;
        int flag = 0;
        for(int j=0;j<n-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
            printArray(n,arr);
            cout<<endl;
        }
        if(flag == 0) break;
    }

    cout<<"After sorting "<<endl;
    printArray(n,arr);


    return 0;
}