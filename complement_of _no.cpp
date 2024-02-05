#include <iostream>
#include <cmath>

using namespace std;

class solution{
    public:
    int compliment(int n){
        
        int mask =0;
        
        int m = n;
    
        if (n==0){
            return 1;   
        }
        while(m!=0){
        
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
    
        int ans = (~n) & mask;
        return ans;
    }
};
int main() {
    int n;
    cin>>n;
    solution G;
    int result= G.compliment(n);
    cout<<"Compliment = "<<result<<endl;
    return 0;
}