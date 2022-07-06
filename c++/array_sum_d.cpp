#include <iostream>
using namespace std;

int main () {
    int n;
    cin>>n;
    int counts = 0;
    for(int i=1;i<=n;i++){
        counts = counts+i;
    }
    cout<<counts<<endl;

    return 0;
}
