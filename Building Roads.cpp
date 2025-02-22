#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int,vector<int>> & adj,vector<bool> & visit,int curr){
	visit[curr]=true;
	for(auto it :adj[curr]){
		if(!visit[it]){
			DFS(adj,visit,it);
		}
	}
	return;
}

int main(){
	unordered_map<int,vector<int>>adj;
	int m,n;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int count=0;
	vector<bool>visit(n+1,false);
	set<pair<int,int>>path;
	int curr=1,next=-1;
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			DFS(adj,visit,i);
			count++;
			next=curr;
			curr=i;
		}
		if(next!=curr){
			path.insert({next,curr});
		}
	}
	cout<<count-1<<endl;
	for(auto it : path){
		cout<<it.first<<" "<<it.second<<endl;
	}
}