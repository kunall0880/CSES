#include<bits/stdc++.h>
using namespace std;
vector<long long>tree;
void seg(vector<long long>&nums,long long idx,long long l,long long r){
	if(l==r){
		tree[idx]=nums[l];
		return;
	}
	long long mid=(l+r)/2;
	seg(nums,2*idx+1,l,mid);
	seg(nums,2*idx+2,mid+1,r);
	tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}
long long solve(long long left,long long right,long long idx,long long l,long long h){
	if(left>h||right<l){
		return 0;
	}
	if(l>=left&&h<=right){
		return tree[idx];
	}
	long long mid=l+(h-l)/2;
	return solve(left,right,2*idx+1,l,mid)+solve(left,right,2*idx+2,mid+1,h);
	
}
int main(){
	long long n,q;
	cin>>n>>q;
	vector<long long>arr(n);
	for(long long i=0;i<n;i++){
		cin>>arr[i];
	}
	tree.resize(4*n);
	seg(arr,0,0,n-1);
	while(q--){
		long long a,b;
		cin>>a>>b;
		cout<<solve(a-1,b-1,0,0,n-1)<<endl;
	}
	return 0;
}