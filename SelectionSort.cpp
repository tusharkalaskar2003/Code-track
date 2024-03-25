#include<iostream>
#include<vector>
using namespace std;

vector<int> selectionSort(vector<int>& array, int N){
    
    for(int i=0; i<N-1; i++){
        int min = i;
        for(int j =i+1; j<N; j++){
            if(array[min] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;    
}

int main(){

    vector<int> array = {6,2,8,4,10};
    int N = array.size();
    selectionSort(array, N);
    for(int i=0; i<N; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
