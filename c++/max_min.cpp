#include <iostream>
using namespace std;

int main (){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maximum = arr[0];
    int minimum = arr[0];
    int max_count = 0;
    int min_count = 0;
    for(int i=0;i<n;i++){
       if(maximum < arr[i]){
            maximum = arr[i];
            max_count++;
       }
       if(minimum > arr[i]){
            minimum = arr[i];
            min_count++;
       }
    }
        cout<<"Maximum "<<maximum<<" Index "<<max_count<<endl;
        cout<<"Minimum "<<minimum<<" Index "<<min_count<<endl;


    return 0;
}
