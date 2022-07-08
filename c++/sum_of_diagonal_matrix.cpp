#include <iostream>
using namespace std;

int main () {
    int row = 3;
    int col = 3;
    int a[row][col];
    int sum =0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==j){
                sum = sum + a[i][j];
            }
        }
    }

    cout<<sum;

    return 0;
}
