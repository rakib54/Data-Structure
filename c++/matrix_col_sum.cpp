#include <iostream>
using namespace std;

int main () {
    int row,col;
    cin>>row>>col;
    int a[row][col];
    int sum = 0;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
    int req_cell;
    cin>>req_cell;

    for(int i=0;i<row;i++){
        sum = sum + a[i][req_cell];
        cout<<a[i][req_cell]<<endl;
    }
    cout<<"sum is "<<sum<<endl;


    return 0;
}
