#include <bits/stdc++.h> 
// #include<iostream>
// #include<vector>
// #include<algorithm>


bool isSafe(vector<vector<int>>& arr, vector<vector<int>> visited, int n, int x, int y){
    if((x >=0 && x <n) && (y >=0 && y <n) && (visited[x][y] ==0 ) && (arr[x][y] == 1)){
        return true;
    }else{
        return false;
    }
}

void solveIt(vector<vector<int>>& arr, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return ;
    }
    visited[x][y] = 1;

     //choise D L R U
     //1.D
    int newx = x +1;
    int newy = y;
    if(isSafe(arr, visited, n, newx, newy)){
        path.push_back('D');
        solveIt(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //2.L
    newx = x;
    newy = y-1;
    if(isSafe(arr, visited, n, newx, newy)){
        path.push_back('L');
        solveIt(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //3.R
    newx = x;
    newy = y+1;
    if(isSafe(arr, visited, n, newx, newy)){
        path.push_back('R');
        solveIt(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //4.U
    newx = x-1;
    newy = y;
    if(isSafe(arr, visited, n, newx, newy)){
        path.push_back('U');
        solveIt(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;

}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.

    vector<string>ans;
    string path = "";
    vector<vector<int>>visited = arr;

    if(arr[0][0]==0){
        return ans;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] =0;
        }
    }

    int srcx = 0;
    int srcy = 0;

    solveIt(arr, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

/*
sample input
1 0 0 0
1 1 0 0
1 1 0 0
0 1 1 1 
*/