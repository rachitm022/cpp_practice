#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second
#define ll long long

int a[2000];
int pre[2000][27];
int dp[2000][2000];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];

	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=26;j++){
			pre[i][j] = (i>0?pre[i-1][j]:0);
			if(i==n-1) ans = max(ans,pre[i][j]);
		}
		pre[i][a[i]]++;
		if(i==n-1) ans = max(ans,pre[i][a[i]]);
	}
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			dp[l][r] = 0;
			for(int i=1;i<=26;i++){
				dp[l][r] = max(dp[l][r],pre[r][i]-(l?pre[l-1][i]:0));
			}
		}
	}
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			int cntIn = dp[l][r];
			for(int i=1;i<=26;i++){
				int cntOut = min(pre[l-1][i],(pre[n-1][i]-pre[r][i]));
				ans = max(ans,2*cntOut + cntIn);
			}
		}
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