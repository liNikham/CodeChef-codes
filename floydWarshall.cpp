#include<bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>>&matrix){
    int n=matrix.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][k]!=1e9&&matrix[k][j]!=1e9)
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

}
int main(){
    int n,m;
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n,1e9));
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    cout<<"Enter the edges and their weight"<<endl;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        matrix[u][v]=w;
        matrix[v][u]=w;

    }
    for(int i=0;i<n;i++){
        matrix[i][i]=0;
    }
    floydWarshall(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}