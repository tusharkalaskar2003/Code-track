#include<iostream>
#include<algorithm>
using namespace std;

/*
//using extra space.
string reverse(string s, int size, int j){ 
    if(j < 0){
        return "";
    }
    string SS = s[j] + reverse(s,size, j-1);
    return SS;
}
*/

// void swap(string s, int i, int j){
//     char temp = s[i];
//     s[i] = s[j];
//     s[j] = temp;
// }

//in place solution
void reverse(string& s, int i, int j){
    if(i > j){
        return ;
    }
    swap(s[i], s[j]);
    reverse(s,i+1,j-1);
}

bool checkPalindrom(string s, int i, int j){
    if(i > j){
        return true;
    }
    if(s[i] != s[j]){
        return false;
    }
    else{
       bool checkFurther = checkPalindrom(s,i+1,j-1);
       return checkFurther;
    }
}
    

int main(){
    string s = "ABBA";
    int size = s.size();
    bool ans = checkPalindrom(s, 0, size-1);
    if(ans){
        cout<<"string is palindrom"<<endl;
    }else{
        cout<<"string is not palindrom"<<endl; 
    }
    reverse(s,0, size-1);
    cout<<"the reversed string is "<<s<<endl;
    return 0;
}