#include <iostream>
using namespace std;

int main (){
    int n;
    cin>>n;
    int left = 0,right = n-1,mid;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;

    while(left<=right){
        mid = (left+right)/2;
        if(arr[mid] == x){
            cout<<"Found at "<<mid<<endl;
            return 0;
        }
        else if(arr[mid] < x){
            left = mid+1;
        }
        else if(arr[mid]> x){
            right = mid-1;
        }
    }
    cout<<"Not found!!"<<endl;

    return 0;
}

