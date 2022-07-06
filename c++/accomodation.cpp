#include <iostream>
using namespace std;

int main () {
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    int first_k_night;

    if(n<k){
       first_k_night = x * n;
       cout<<first_k_night<<endl;
       return 0;
    }
    else {
        first_k_night = x * k;
    }
    int rem = n - k;
    int rest_of_the_night = rem * y;

    int total_accomodation_fee = first_k_night + rest_of_the_night;
    cout<<total_accomodation_fee<<endl;

    return 0;
}
