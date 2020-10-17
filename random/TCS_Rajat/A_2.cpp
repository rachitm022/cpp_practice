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
 
void solve(){
	int n;
	cin>>n;
	int a[n];
	ll ans=0;
	int mi = 0;
	fl(i,0,n){
		cin>>a[i];
		if(a[i]<a[mi]) mi = i;
	}
	ans+=1;
	int cur = 1;
	fl(i,mi+1,n){
		if(a[i]<a[i-1]){
			ans+= cur-1;
			cur--;
		}
		else if(a[i]>a[i-1]){
			ans+= cur+1;
			cur++;
		}
		else{
			ans+= cur;
		}
	}

	cur = 1;
	fb(i,mi,0){
		if(a[i]<a[i+1]){
			ans+=(--cur);
		}
		else if(a[i]>a[i+1]) ans+=(++cur);
		else ans+= cur;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--)
		solve();

	return 0;
}