// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

    vector<vector<int>> ThreeSum(vector<int>&nums){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0; i<n-2;++i){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int left = i+1;
            int right = n-1;
            if(right>left){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    result.push_back({nums[i],nums[left],nums[right]});
                    
                    while(left < right && nums[left] == nums[left+1]){
                        left++;}
                    while(left < right && nums[right] == nums[right-1]){
                        right--;}
                        
                    left++;
                    right--;
                }
                else-if(target>sum){
                    left++;
                }
                else{
                    right--;
                }
               
            }
        }
        return result;
    }

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};    
    vector<vector<int>> triplates = ThreeSum(nums);
    

    for(const auto& triplate: triplates ){
        cout<<"[";
        for(int num : triplate){
            cout<<num<<" ";
        }
        cout<<"}"endl;
    }
    return 0;
}