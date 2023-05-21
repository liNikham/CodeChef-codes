#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>adjList;
vector<int> dijkstras(int source){
   vector<int>distance(adjList.size(),1e9);
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   distance[source]=0;
   pq.push(make_pair(0,source));
   while(!pq.empty()){
         int u=pq.top().second;
         pq.pop();
         for(auto it:adjList[u]){
            int weight=it.second;
            int dest=it.first;
            if(distance[dest]>distance[u]+weight){
                distance[dest]=distance[u]+weight;
                pq.push(make_pair(distance[dest],dest));
            }
         }
   }
   return distance;
}
int main(){
cout<<"Enter the number of vertices"<<endl;
int n;
cin>>n;
adjList.resize(n);
cout<<"Enter the number of edges"<<endl;
int m;
cin>>m;
cout<<"Enter the edges and their weights"<<endl;
for(int i=0;i<m;i++){
    int u,v,w;
    cout<<"Enter the edges"<<endl;
    cin>>u>>v;
    cout<<"Enter the weight"<<endl;
    cin>>w;
    adjList[u].push_back(make_pair(v,w));
    adjList[v].push_back(make_pair(u,w));

}
int source;
cout<<"Enter the source"<<endl;
cin>>source;
vector<int>dist=dijkstras(source);
cout<<"the Shortest distance from "<<source<<" are"<<endl;
for(int i=0;i<dist.size();i++){
    cout<<"vertex "<<i+1<<" : "<<dist[i]<<endl;
}
    return 0;
}