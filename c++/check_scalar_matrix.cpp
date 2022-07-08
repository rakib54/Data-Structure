#include <iostream>
using namespace std;

int main () {
    int row,col;
    cin>>row>>col;
    int matrix[row][col];
    if(row!=col){
        cout<<"No"<<endl;
        return 0;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }

    int first;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           first = matrix[0][0];
            if(first == 0){
                cout<<"No"<<endl;
                return 0;
            }
            if(i==j){
                if(matrix[i][j] != first){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            else if(i!=j){
                if(matrix[i][j] > 0){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    if(first == 1){
        cout<<"Both scalar and Identity matrix";
    }

    return 0;
}
