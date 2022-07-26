#include <iostream>
using namespace std;

int binarySearch(int num,int arr[],int low,int high){
    int mid = (low + high)/2;

    if(low<=high){
        if(arr[mid] == num) {
            return mid;
        }
        else if(num < arr[mid]){
            binarySearch(num,arr,low,mid-1);
        }
        else {
            binarySearch(num,arr,mid+1,high);
        }
    }
    else {
        return -1;
    }

}
int main () {
    int n,num;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"What number you want to search: ";
    cin>>num;
    int index = binarySearch(num,arr,0,n-1);
    if(index != -1){
        cout<<"Found at "<<index<<endl;
    }
    else cout<<"Not Found!"<<endl;


    return 0;
}
