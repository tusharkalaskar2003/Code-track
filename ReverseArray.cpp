#include<iostream>
using namespace std;

void printarray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}


void reverse(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    
    int arr[] = {2,5,8,3,5,9,2,6,10,4};
    // int n = arr.size();
    int n = 10;
    cout<<"Intial array is : "<<"";
    printarray(arr,n);
    reverse(arr, n);
    cout<<"reverse array is : "<<"";
    printarray(arr, n);
    
    return 0;
    
}

// Output:
// Intial array is : 2 5 8 3 5 9 2 6 10 4 
// reverse array is : 4 10 6 2 9 5 3 8 5 2 

