#include <iostream>
using namespace std;
void printarray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int swap_alternate(int arr[], int n){
    
    for(int i=0; i<n; i+=2){
        if(arr[i+1] < n){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }    
    }
}
int main() {
    // Write C++ code here
    
    int array[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(array) / sizeof(int);
    cout<<"the original array is :"<<endl;
    printarray(array, n);
    cout<<"the alternate swap array is :"<<endl;
    swap_alternate(array, n);
    printarray(array, n);

    return 0;
}

// Output:
// the original array is :
// 1 2 3 4 5 6 7 8 9 
// the alternate swap array is :
// 2 1 4 3 6 5 8 7 9 