#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int>nums = {1,2,3,4,5,6,7};
    int n =7;
    int k=3;
    vector<int>arr;
    
    int i = n-k;
    while( i<n){
        arr.push_back(nums[i]);
        i++;
    }
    int j =0;
    while( j < n-k){
        arr.push_back(nums[j]);
        j++;
    }
    for(auto it: arr){
        cout<<it<<" ";
    }

    return 0;
}
