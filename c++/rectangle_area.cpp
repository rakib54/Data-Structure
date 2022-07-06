#include <iostream>
using namespace std;

int main () {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int rec_1 = a * b;
    int rec_2 = c * d;

    if(rec_1 > rec_2){
        cout<<rec_1<<endl;
    }
    else cout<<rec_2<<endl;

    return 0;
}
