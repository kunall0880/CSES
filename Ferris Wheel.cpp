#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,wt;cin>>n>>wt;
	vector<int>nums(n,0);
	for(auto & it: nums){
		cin>>it;
	}
	sort(nums.begin(),nums.end());
	int i=0,j=n-1;
	int count=0;
	while(i<=j){
		if((nums[i]+nums[j])<=wt){
			count++;
			i++;
			j--;
			continue;
		}
		if(nums[j]<=wt){
			count++;
			j--;
			continue;
		}
		count++;
		i++;
	}
	cout<<count<<endl;
	return 0;
}