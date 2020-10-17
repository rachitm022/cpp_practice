#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define f first
#define s second
#define all(c) c.begin(),c.end()
#define ll long long
#define sz(x) ((int)(x).size())
#define fl(i,a,b) for(int i=a; i<b; i++)
#define fb(i,a,b) for(int i=a-1; i>=b; i--)
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
const int MOD = 1e9+7;
ll add(ll& a,ll& b){
	ll ans;
	ans = a%MOD + (b%MOD);
	if(ans>=MOD) ans-=MOD;
	return ans;
}
ll multiply(ll& a,ll& b){
	ll ans;
	ans = ((a%MOD)*(b%MOD))%MOD;
	return ans;
}
int lo,hi,k;
ll ans = 0;

void solve(){
	// int lo,hi;
	cin>>lo>>hi;
	// int k;
	
	cin>>k;
	int n = hi-lo+1;
	ll dp[2];
	ll e,o;
	memset(dp,0,sizeof(dp));
	if(n==1&&lo==0){
		cout<<0;
		return;
	}
	if(k==0){
		cout<<0;
	}
	if(n%2==0){
		dp[0] = e =((n)/2); //even
		dp[1] = o =((n)/2); //odd
	}
	else{
		dp[0] = e =((n-1)/2)+(lo%2==0);
		dp[1] = o =((n-1)/2)+(lo%2);
	}

	fl(i,2,k+1){
		ll temp1 = multiply(dp[0],e);
		ll temp2 = multiply(dp[1],o);
		ll temp3 = multiply(dp[1],e);
		ll temp4 = multiply(dp[0],o);
		dp[0] = add(temp1,temp2);
		dp[1] = add(temp3,temp4);
		// cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<dp[0];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	// cin>>T;
	while(T--)
		solve();

	return 0;
}