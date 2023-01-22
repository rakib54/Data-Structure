#include <bits/stdc++.h>
using namespace std;

// remove duplicate from vector
// void remove_duplicate(std::vector<int> &v){
//     auto end = v.end();
//     for (auto it = v.begin(); it != end; ++it) {
//         end = std::remove(it + 1, end, *it);
//     }
//     v.erase(end, v.end());
// }


int main (){
    vector<int>nums1{1,2,3};
    vector<int>nums2{2,4};

    int i=0,j=0;
    int ans = -1;
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i] == nums2[j]){
            ans = nums1[i];
            break;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else if(nums1[i] > nums2[j]){
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

