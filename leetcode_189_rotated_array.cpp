#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector<int>nums = {1,2,3,4,5,6,7};
    int n =nums.size();
    int k=3;
    vector<int>arr(n);
    for(int i=0; i<n;i++){
        arr[(i+k)%n] = nums[i];
    }
    //coping the acc to nums
    nums.clear();
    for(int i=0; i<arr.size(); i++){
        nums.push_back(arr[i]);
    }
    //printing the rotated array
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}
