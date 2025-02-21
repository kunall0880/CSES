#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
bool BFS(vector<vector<bool>>&visit,vector<vector<char>>&graph,int & a,int & b,int &count,string &str,vector<vector<char>>&dira){
    int m=graph.size(),n=graph[0].size();
	queue<pair<int,int>>que;
	que.push({a,b});
	visit[a][b]=true;
	while(!que.empty()){
		int i=que.front().first;
		int j=que.front().second;
		que.pop();
		count++;
		for(auto & it : dir){
			int i_=i+it[0];
			int j_=j+it[1];
			if( i_ < m && i_ >= 0 && j_ < n && j_ >= 0 && (graph[i_][j_]=='.'||graph[i_][j_]=='B')&&visit[i_][j_]==false){
				if(it[0]==0&&it[1]==1){
					dira[i_][j_]='R';
				}
				if(it[0]==0&&it[1]==-1){
					dira[i_][j_]='L';
				}
				if(it[0]==1&&it[1]==0){
					dira[i_][j_]='D';
				}
				if(it[0]==-1&&it[1]==0){
					dira[i_][j_]='U';
				}
				visit[i_][j_]=true;
				que.push({i_,j_});
				
				if(graph[i_][j_]=='B'){
					a=i_;
					b=j_;
					return true;
				}
			}
		}
	}
	return false;
}


string solve(vector<vector<char>> dira,int pai,int paj,int pbi,int pbj,int n){
	string ans="";
	int ai=pai,aj=paj,bi=pbi,bj=pbj;
	while(1){
		ans.push_back(dira[bi][bj]);
		if(ans.back()=='L'){
			bj++;
		}
		if(ans.back()=='R'){
			bj--;
		}
		if(ans.back()=='U'){
			bi++;
		}
		if(ans.back()=='D'){
			bi--;
		}
		if(ai==bi&&aj==bj){
			break;
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}


int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<char>>graph(m,vector<char>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	vector<vector<bool>>visit(m,vector<bool>(n,false));
	vector<vector<char>>dira(m,vector<char>(n,'a'));
	int aj=-1,ai=-1,bi=-1,bj=-1;
	string str="";
	
	int f=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(graph[i][j]=='A'){
				ai=i,aj=j;
				bi=i,bj=j;
				if(visit[i][j]==false){
					if(BFS(visit,graph,bi,bj,f,str,dira)){
						cout<<"YES"<<endl;
						string ans=solve(dira,ai,aj,bi,bj,f);
						cout<<ans.length()<<endl;
						cout<<ans<<endl;
						break;
					}else{
					cout<<"NO"<<endl;
					}
				}
			}
		}
	}
	return 0;
}