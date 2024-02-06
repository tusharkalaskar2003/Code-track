#include <iostream>
using namespace std;

int find_set_bit(int a){
    int count =0;
    while(a != 0){
        if(a & 1){
            count++;
        }
        a = a>>1;
    }
    return count;
}

int main() {
    int a,b;
    cin>>a >>b;
    int a_set_bit = find_set_bit(a);
    int b_set_bit = find_set_bit(b);
    cout<<"Sum of set bit : "<<(a_set_bit + b_set_bit)<<endl;
    return 0;
}
