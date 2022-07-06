#include <iostream>
using namespace std;

int main () {
    int *ptr = new int[10]{1,2,3,4};

    for(int i=0;i<10;i++){
        cout<<ptr[i]<<endl;
    }


    return 0;
}
