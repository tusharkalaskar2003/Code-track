class Solution {
public:
    bool isFound(vector<int>& arr, int k , int h){
        long long hr = 0;
        for(int bananas : arr){
            hr += ceil((bananas*1.0)/k);
        }
        if(hr <= h){
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = 1e9;
        long long ans;
        while(low <  high){
            long long mid = low + (high -low)/2;

            if(isFound(piles, mid, h)){
                ans = mid;
                high =mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
