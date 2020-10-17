#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
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
const int MAXN = 1e6;
vi t[4*MAXN];
// int s[4*MAXN];
int a[MAXN];
int n;
void build(int v,int tl,int tr){
	if(tl==tr){
		// cout<<a[tl]<<endl;
		t[v].push_back(a[tl]);
	}
	else{
		int tm = (tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		int x = sz(t[2*v]),y = sz(t[2*v+1]);
		int i=0,j=0;
		while(i<x&&j<y){
			if(t[2*v][i]<=t[2*v+1][j]){
				t[v].push_back(t[2*v][i++]);
			}
			else{
				t[v].push_back(t[2*v+1][j++]);
			}
		}
		while(i<x){
			t[v].push_back(t[2*v][i++]);
		}
		while(j<y){
			t[v].push_back(t[2*v+1][j++]);
		}
		// cout<<t[v].size()<<endl;
	}
} 

int calc1(int val,int l,int r,int v=1,int tl=0,int tr=n-1){
	if(l>tr||r<tl){
		return 0;
	}
	if(tl>=l&&tr<=r){
		int pos = lower_bound(all(t[v]),val) - t[v].begin();
		return pos;
	}

	int tm = (tl+tr)/2;
	return calc1(val,l,r,2*v,tl,tm)+calc1(val,l,r,2*v+1,tm+1,tr);
}

int calc2(int val,int l,int r,int v=1,int tl=0,int tr=n-1){
	if(l>tr||r<tl){
		return 0;
	}
	if(tl>=l&&tr<=r){
		int pos = lower_bound(all(t[v]),val) - t[v].begin();
		return t[v].size() - pos;
		// return pos;
	}

	int tm = (tl+tr)/2;
	return calc2(val,l,r,2*v,tl,tm)+calc2(val,l,r,2*v+1,tm+1,tr);
}
void solve(){
	cin>>n;
	fl(i,0,n){
		cin>>a[i];
	}
	build(1,0,n-1);
	ll ans = 0;
	fl(i,0,n){
		ll x = calc2(a[i],0,i-1);
		ll y = calc1(a[i],i+1,n-1);
		// cout<<x<<" "<<y<<endl;
		ans+=(x*y);
	}
	cout<<ans<<endl;
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
/*
	“I’m not gonna run away, I never go back on my word! That’s my nindo: my ninja way.” Naruto
═══════════░▓
══════════░▓▓
════════░▓░░▓
═══════▓▓░░░▓
▓════░▓░░░░░▓══════════░▓▓░
▓═══▒▓░░░░░░▓░══════░▓▓░░▓░
▓══▓▒═░░░░░░░▓════░▓▓░░░░▓
░▓▓░═░░░░░░░░▓══░▒▓░░░░░▒▓
░░░░░░░░░░░░░▒▓▓▓░░░░░░═▓═════░▓▓▓▓▓
░░░░░░░░░░░░░░░░░░░░░░░░▓═░▓▓▓▓░░▒▓
░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓░░░═░▒▓░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░═░▓▓▒
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▓▓▒
░░░░░░░░░░░░░░░░░══░░░░░░░░░▒▓▓▓▓▓▓▓▓▓▓▓
░══════════░░════░▒▒░░░═░░░░▒░░░░░░░░░▓▓
▒░══░▒▒▓▓██▓══░▒█▓░════▒▓░░░═░░░═░░▒▓▓▒
▓█████████▓░▒▓███═══░▒██▒═░░░░░░░▒▓▓▒
▓█▓▓▓▓▓▓▓█▓█████══░▓████═══▒▒═░░░░░▓▓
▓▓▓▓▓▓▓▓▓██▓▓▓█▒░▓█████▒══▒▓▒═░░░░══▓▓▓▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓█░═▒▒█▓═░░░░░░▒▒▓
▓▓▓▓▓▓▓▓▓▓▓▓▓████▓▓▓▓▓▓═▒▓██▓═░░░═░▓▓▓
▓█▓▓▓▓▓▓▓▓▓▓▓██▓▓▓▓▓▓█▒▒████▓═░░░░▓
▒▒▓████████████████▓▓▓▓██▓▓█▓═░░═▓█
▒▒░░▒░░░░░░▒░▒▒▒▓▓██████▓▓▓█▓═░═▒▓█▓
▒██▒░░══════░▓░═░░░▒▒▓████▓▓█══░█══▓
▒▒▒▒░▒═░░░═░▓░░░░░░░░░░▒▓████══▓▒══▓
▒▒▓▓░▓═░░░═▒▓░░░░░░░░░░░░░▓██═▓▓══░▓
▒▓▓▒░▓═░░═▒▓░░░░░░░░░░░░░══▒▒▒██▒══▓
▓▒░░▒▓═══░▓░░░░░░░░░░░░░░▓▓▓▒░▓██▓═▓
▓▓░░▒▓═░░▒▒░░░░░░░░░░░░░░▓═▒█░░▓██▓▓
▓█▒░▒▓═▓▓▒░░░░░░░░░░░░░░░▓══██▒▒▓██
░░░░▒▓▒█▓░░░░░░░░░░░░░░░░▓═▒█▓▓▒██░
░░░░▒█▓▒░░░░▒░░░░░░░░░░░░░▓▓▓▒▒▒▒
▒░░░▒█▒░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░▒▓▒░▓░
█▒░░▒▓░░░░░░░░░░░░▒▒▒▒▒░░░░░░░▓
▓▓░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░▓
▒▓░░░░░░░▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░▓
▒▓░░░░░░░░░░░░░░░░░▒░░░░░░░░░░░▒▓
▒▓░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░▓▒
▒▓░░░░░░░▒▒▒▒▒▒▒▒▒░░░░░░░░░░▒▓▓▒▒█░
▒▓▒░░░░░░▒▒░░░░░░░░░░░░░░░░░▒▓██▓▒
▒▓▓░░░░░░░░░░░░░░░░░░▒▒▒▒░░░░▓░
░▒▓▓░░░░░░░░░░░░░░░░▒▒▒▒▓▓▓░▓
░▒▓▓▓▒░░░░░░░░░░░░░░░░░░░▒▓█▓
░░█▒▒▓▓▒░░░░░░░░░░░░░░░░▒▒▓▒
░░▓▓▒▒▒▓▓▒░░░░░░░░░░░░░░░▒▓
░░▒█▒▒▒▒▒▓▓▒▒░░░░░░░░░░░░▓
░░░▓▓▒▒▒▒▒▒▓▓▓▒░░░░░░░░░░▓
░░░▒▓▒▒▒▒▒▒▒▒▒▓▓▓▒░░░░░░░▓
░░░░▓▒▒▒▒▒▒▒▒▒▒▓▓▓▒▒░░░░▓░
░░░░▓▓▒▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓░
░░░░░▓▒▒▒▒▒▓░
▓▓██▓▓▓██▓▓██▒
▓▓██▓▓▓██▓▓██▒
▓▓██▓▓▓██▓▓██▒
▓▓██▓▓▓██▓▓██▒
*/