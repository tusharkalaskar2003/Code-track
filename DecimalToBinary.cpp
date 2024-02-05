#include<iostream>
using namespace std;
#include<cmath>
int main(){

    int n;
    cin>>n;
    int ans=0;
    int i=0;
    while(n!=0){
        int bit = n & 1;
        ans = static_cast<int>(bit * pow(10, i)) + ans;
        i++;
        n = n>>1;
    }
    cout<<ans<<endl;

    return 0;
}