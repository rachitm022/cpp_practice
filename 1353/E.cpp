#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second

void solve(){
	int n,k;
	string a;
	cin>>n>>k>>a;
	vector<string> s(k);
	int ans = INT_MAX;
	int tot = count(a.begin(),a.end(),'1');
	auto solve = [&](const string& t){
		int pre = 0;
		int x = t.size();
		int res[x];
		int ones = count(t.begin(),t.end(),'1');
		int temp = ones;
		for(int i=0;i<x;i++){
			int cur = (t[i]=='1');
			pre += cur;
			res[i] = 1 - cur;
			if(i) res[i] += min(res[i-1],pre - cur);
			temp = min(temp,res[i]+ones-pre);
		}
		return temp;
	};
	for(int i=0;i<n;i++){
		s[i%k]+=a[i];
	}
	for(int i=0;i<k;i++){
		ans = min(ans,solve(s[i])+tot - count(s[i].begin(), s[i].end(),'1'));
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
		solve();

	return 0;
}