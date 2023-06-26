
#include<iostream> 
#include<unordered_map>
#include<list>
#include<vector>
#include<map>
#include<queue>
using namespace std;


class listgraph{
    public:
    map<int,list<int>>adj;

    void insert(int u,int v,bool direction){

        //if dir. is 0 , i.e undirected
        //if dir. is 1 , i.e directed

        adj[u].push_back(v);
        if(direction== 0){
           adj[v].push_back(u); 
        }
    }

    void printgraph(){
        for(auto i:adj){
            cout<<i.first<<"--> ";
            for(auto j:i.second){
                cout<<j<<"_";
            }
            cout<<endl;
        }
    }

    void BFS(int root){
        map<int,bool>visited;
        queue<int>q;

        q.push(root);
        visited[root]=true;

        while(!q.empty()){
            int node=q.front();
            cout<< node <<" ";
            q.pop();
            // int nbr;
            for(int nbr : adj[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }

        }
    }

    void DSF_helper(int root, map<int,bool>&visited){
        cout<<root<<" ",
        visited[root]=true;
        for(int nbr : adj[root]){
            if(!visited[nbr]){
                DSF_helper(nbr,visited);
            }
        }
    }

    void DFS(int root){
        map<int,bool>visited;

        for(int p : adj){
            int node =p.first;

            visited[node]=false;
        }
        DSF_helper(root,visited);
    }

};

// class Graph{
//     public:
//     const int max = 100;
//     int adj[max][max];
//     int N,M;

//     void insert2(int u,int v,bool direction){
//         adj[u][v]=1;
//         if(direction==0){
//             adj[v][u]=1;
//         }
//     }
//     void print(){
//         for(int i=0; i<N; i++){
//             for(int j=0; j<N; j++){
//                 cout<<adj[i][j]<<",";
//             }
//         }
//     }
// };

int main(){
    int N;
    cout<<"Enter the number of Nodes:"<<" ";
    cin>>N;

    int M;
    cout<<"Enter the number of Edges:"<<" ",
    cin>>M;

   
    listgraph g;
    // Graph G;
    for(int i=0;i<M;i++){
        int u,v;
        cin>> u >> v;
        // G.insert2(u,v,0);
        g.insert(u,v,0);
    }
    cout<<"Link List representation of graph is : "<<" ";
    g.printgraph();
    cout<<"BFS of given graph is : "<<" "; 
    g.BFS(1);
    g.DFS(1);

    return 0;
}
