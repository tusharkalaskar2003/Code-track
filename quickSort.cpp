#include<iostream>
#include<algorithm>
using namespace std;

int partition(int* arr, int s, int e){
    int pivote = arr[s];
    int cnt =0;
    for(int i=s+1; i <= e; i++){
        if(pivote >= arr[i]){
            cnt++;
        }
    }

    ///place piovte at right place
    int pivoteInd = s+cnt;
    swap(arr[pivoteInd], arr[s]);

    int i=0;
    int j =e;
    while(i < pivoteInd && j > pivoteInd){
        while(arr[i] <= pivote){
            i++;
        }
        while(arr[j] > pivote){
            j--;
        }
        if(i < pivoteInd && j > pivoteInd){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }

    }
    return pivote;
}

void quickSort(int* arr, int s, int e){
    if(s >= e){
        return ;
    }
    // make the partition
    int p = partition(arr, s, e);
    //apply the reccuurance in partitioned array
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int arr[] = {5,4,9,2,7,1,3};
    int n = 7;
    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}