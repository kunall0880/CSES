#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
void BFS(vector<vector<bool>>&visit,vector<vector<char>>&graph,int a,int b){
    int m=graph.size(),n=graph[0].size();
	queue<pair<int,int>>que;
	que.push({a,b});
	while(!que.empty()){
		int i=que.front().first;
		int j=que.front().second;
		que.pop();
		for(auto & it : dir){
			int i_=i+it[0];
			int j_=j+it[1];
			if( i_ < m && i_ >= 0 && j_ < n && j_ >= 0 && visit[i_][j_] == false && graph[i_][j_]=='.'){
				visit[i_][j_]=true;
				que.push({i_,j_});
			}
		}
	}
}
int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<char>>graph(m,vector<char>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	vector<vector<bool>>visit(m,vector<bool>(n,false));
	int count=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!visit[i][j]&&graph[i][j]=='.'){
				BFS(visit,graph,i,j);
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}