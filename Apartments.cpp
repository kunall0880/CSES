#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>arr(n),arr2(m);
	for(auto &i:arr){
		cin>>i;	
	}
	for(auto &i:arr2){
		cin>>i;
	}
	sort(arr.begin(),arr.end());
	sort(arr2.begin(),arr2.end());
	int count=0;
	for(int i=0;i<n;i++){
		int ll=arr[i]-k;
		int ub=arr[i]+k;
		auto it = lower_bound(arr2.begin(),arr2.end(),ll);
		if(*it<=ub&&*it>=ll){
			count++;
			*it=-1;
		}
	}
	cout<<count;
	return 0;
}