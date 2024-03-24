#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

bool isFound(vector<int> &stalls, int N, int mid, int k ){

    int diff =0;
    int cowCnt = 1;
    int cowBind = stalls[0];
    for(int i=1; i< N; i++){
        diff = stalls[i] - cowBind;
        if(diff >= mid ){
            cowCnt++;
            if(cowCnt == k){
                return 1;
            }
            cowBind = stalls[i];
        }
    }
    return 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int N = stalls.size();
    int low = 0;
    int maxi = -1;
    
    for(int i =0; i<N; i++){
        maxi = max(maxi, stalls[i]);
    }
    sort(stalls.begin(), stalls.end());
    int high = maxi;
    int ans = -1;
    while(low <= high){

        int mid = low + (high - low)/2;
        if(isFound(stalls, N, mid, k)){
            ans = mid;
            low = mid +1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int>stalls = {0,3, 4, 7, 10, 9};
    int k = 4;
    int result = aggressiveCows(stalls, k);
    cout<<result<<endl;
     
    return 0;
}


