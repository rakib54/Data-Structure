#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a, vector<int>b){
    return a[1] < b[1];
}

int main(){
    vector<vector<int>> intervals={{1,2},{2,3}, {3,4},{1,3}};
    int cnt = 0;
    sort(intervals.begin(), intervals.end(),cmp);

    int val = intervals[0][1];
        for(int i=0;i<intervals.size()-1;i++){
            if(val > intervals[i+1][0]){
                cnt++;
            }
            else val = intervals[i+1][1];
        }


      cout<<cnt;

    return 0;
}
