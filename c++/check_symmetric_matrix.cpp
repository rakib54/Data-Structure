#include <iostream>
using namespace std;

int main(){
    int row,col;
    cin>>row>>col;
    int matrix[row][col];
    if(row !=col){
        cout<<"No";
        return 0;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j] != matrix[j][i]){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}
