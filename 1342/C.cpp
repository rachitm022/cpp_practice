//Done in O(N)
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second

void solve(){
	int n;
	cin>>n;
	int a[n];
	int cnt[n+1] = {0};
	int maxcnt = INT_MIN;
	int maxval;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]>maxcnt){
			maxcnt = cnt[a[i]];
			maxval = a[i];
		}
	}
	// cout<<maxcnt<<" "<<maxval<<endl;
	int len = 0;
	for(int i=0;i<=n;i++){
		if(cnt[i]){
			if(i==maxval) continue;
			len++;
			// cout<<i<<" "<<cnt[i]<<" "<<len<<endl;
			
		}
	}
	cout<<(len<maxcnt-1?len+1:(len==maxcnt-1?len:maxcnt))<<endl;
	return;
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