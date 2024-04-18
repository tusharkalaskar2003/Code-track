#include<iostream>
#include<algorithm>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s +(e-s)/2;
    int l1 = mid - s +1;
    int l2= e-mid;
    int* first = new int[l1];
    int* second = new int[l2];

    // copy value from arr to new array first and second
    int index =s;
    for(int i=0; i< l1; i++){
        first[i] = arr[index++];
    }
    index = mid +1;
    for(int i=0; i< l2; i++){
        second[i] = arr[index++];
    }

    // comaparing the two array and merging into sorted array
    int i=0;
    int j=0;
    index = s;
    while(i < l1 && j < l2){
        if(first[i] < second[j]){
            arr[index++] = first[i++];
        }
        if(first[i] >= second[j]){
            arr[index++] = second[j++];
        }
    }
    while(i < l1){
        arr[index++] = first[i++];
    }
    while(j < l2){
        arr[index++] = second[j++];
    }
    delete []first;
    delete []second;
}

void mergSort(int * arr, int s, int e){

    if(s >= e){
        return ;
    }
    int mid = s +(e-s)/2;
    //left part
    mergSort(arr, s, mid);
    //right part
    mergSort(arr, mid+1, e);

    merge(arr, s, e);

}

int main(){
    int arr[] = {5,4,9,2,7,1,3};
    int s =0;
    int e = 6;
    int n =7;
    mergSort(arr, s, e);

    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";

    }cout<<endl;
    return 0;
}