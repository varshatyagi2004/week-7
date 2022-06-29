#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
class Solution {
public:
    int shortestPath(vector<vector<int>>& places, int n, int k,int AkshayLoc) {
        int shortdist=0;
        vector<int>dist(n,INT_MAX);
        dist[k]=0;
        vector<pii>g[n];
        for(auto& i:places) {
            g[i[0]].push_back({i[2],i[1]});
            g[i[1]].push_back({i[2],i[0]});
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,k});
        pii u;
        vector<int>path;
        while(!pq.empty()){
            u=pq.top();
            pq.pop();
            path.push_back(u.second);
            if(u.second==AkshayLoc)break;
            for(auto& v:g[u.second]){
                if(dist[u.second]+v.first<dist[v.second]){
                    dist[v.second]=dist[u.second]+v.first;
                    pq.push({dist[v.second],v.second});
                }
            }
          }
     shortdist=dist[AkshayLoc];
     if(shortdist==INT_MAX)return -1;
     cout<<"path covering distance from his friends location to his house is :"<<endl;
     for(int &i:path)cout<<i<<" ";
     cout<<endl;
     return shortdist;
    }
};
int main(){
  int n,v,s,d,w,friendLoc,AkshayLoc;
  cout<<"input the number of edges connected by different places :";
  cin>>n;
  cout<<"input the number of places in the graph :";
  cin>>v;
  printf("input %d path edges such that for each, path exist between two places  and there respective distance:\n ",n);
  vector<vector<int>>places;
  for(int i=0;i<n;i++){
      printf("path edge  %d and distance between them  : ", i+1);
      cin>>s>>d>>w;
      places.push_back({s,d,w});
   }
   cout<<"input the starting location of the akshay's friends  :";
   cin>>friendLoc;
   cout<<"input the Akshay's position :";
   cin>>AkshayLoc;
   cout<<endl;
   Solution *sol= new Solution ();
   int distance=sol->shortestPath(places,v,friendLoc,AkshayLoc);
   if(distance==-1){
       cout<<"Path does not exist";
   }
   else {
       cout<<"path exist with shortest distance : "<<distance;
   }
}