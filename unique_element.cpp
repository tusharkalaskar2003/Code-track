#include <iostream>
using namespace std;
int uniqe(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}


int main() {
    // Write C++ code here
    
    int arr[] = {2,3,1,6,3,6,2,1,5};
    int n = sizeof(arr) / sizeof(int);
    int res = uniqe(arr, n);
    cout<<"Unique element is array : "<<res<<endl;
    
    return 0;
}

// Output:
// Unique element is array : 5