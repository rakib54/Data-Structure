#include <iostream>
using namespace std;

void print(int **x){
    **x = 100;
}
int main () {
    int a = 10;
    int *ptr = &a;
    int **q = &ptr;
    print(q);
    cout<<a<<endl;
    return 0;
}
