#include<iostream>
using namespace std;

float binary_Search(int n){
    int low =0;
    int high =n;
    int ans =-1;
    
    while(low <= high){

        long long int mid = low + (high-low)/2;
        long long int sqr = mid*mid;
        if(sqr == n) return mid;
        if(sqr < n ){
            low = mid +1;
            ans =mid;
        }
        else{
            high = mid -1;
        }
    }
    float value,value2;
    for(int i=1; i<10; i++){
        value = ans + 0.1 * i;
        float sqr2 = value*value;
        if(sqr2 == n) return value;
        if( sqr2 > n){
            break;
        }
    }
    for(int i=1; i<10; i++){
        value2 = value - 0.01 * i;
        float sqr3 = value2*value2;
        if(sqr3 == n) return value2;

        if( sqr3 < n){
            break;
        }
    }
    return value2+0.01;
}

int main(){
    int x =8;
    float result = binary_Search(x);
    cout<<result<<endl;
    cout<<"Creoos check = result x result => "<<result*result<<endl;
    return 0;
}