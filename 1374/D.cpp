#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define f first
#define s second
#define all(c) c.begin(),c.end()
#define ll long long
#define pii pair<ll,ll>
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
ll n,k;
ll cal(pii& a){
	return k*(a.s - 1)+a.f+1;
}
bool cmp(pii& a,pii& b){
	return cal(a)<cal(b);
}
void solve(){
	cin>>n>>k;
	map<ll,ll> mp;
	fl(i,0,n){
		ll temp;
		cin>>temp;
		if(temp%k)
			mp[k-temp%k]++;
	}
	vector<pii> mp2;
	for(auto it = mp.begin();it!=mp.end();++it){
		mp2.emplace_back(it->f,it->s);
	}
	if(mp2.empty()){
		cout<<0<<endl;
		return;
	}
	sort(all(mp2),cmp);
	cout<<k*(mp2.rbegin()->s - 1)+mp2.rbegin()->f+1<<endl;
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