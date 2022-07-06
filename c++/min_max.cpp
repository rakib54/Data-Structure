#include <bits/stdc++.h>
using namespace std;

int main () {
    int arr[5] = {10,2,4,5,3};
    int mn = arr[0];

    for(int i=1;i<5;i++){
        mn = min(arr[i],mn);
    }

    cout<<mn;

    return 0;
}
