#include <bits/stdc++.h>
using namespace std;
class Solution{
  private:
    vector<int> topoSort(int v, vector<int> adj[], int n){
      int indegree[V]={0};
      for(int i=0; i<V; i++){
        for(auto it:adj[i]){
          indegree[it]++;
        }
      }

      queue<int>q;
      for(int i=0; i<n; i++){
        if(indegree[i]==0){
          q.push(i);
        }
      }
      vector<int> topo;
      while(!q.empty()){
        int node=q.front;
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
          indegree[it]--;
          if(indegree[it]==0) q.push(it);
        }
      }
      return topo;
    }
  public:
    string findOrder(string dict[], int N, int K){
      vector<int> adj[K];
      for(int i=0; i<N; i++){
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(), s2.size());
        for(int ptr=0; ptr<len; ptr++){
          if(s1[ptr]!=s2[ptr]){
            adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
            break;
          }
        }
      }

      vector<int> topo=topoSort(K, adj, N);
      string ans="";
      for(auto it: topo){
        ans+=char(it + 'a');
      }
      return ans;
    }
};


int main(){
  int N=5, K=4;
  string dict[]={"baa", "abcd", "abca", "cab", "cad"};
  Solution obj;
  string ans=obj.findOrder(dict, N, K);
  for(auto ch: ans){
    cout<<ch<<' ';
  }
  cout<<end;
  return 0;
}