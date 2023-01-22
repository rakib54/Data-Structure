#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l,int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(arr[j] < pivot){ // if element are smaller than pivot
            i++;
            swap(arr[i],arr[j]); //swap them
        }
    }
    swap(arr[i+1],arr[r]);  // bring pivot into the right position
    return i+1;
}

void quick_sort(int arr[], int l,int r){
    if(l<r){
        int p = partition(arr,l,r);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,r);
    }
}

int main (){
    int arr[5] = {4,2,5,1,3};
    quick_sort(arr,0,4);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

/*
Time Complexity -> Best Case -> O(NlogN)  // if pivot is median
                -> worst Case -> O(N^2) // if the pivot is last element 
Space Complexity -> O(N)
*/
