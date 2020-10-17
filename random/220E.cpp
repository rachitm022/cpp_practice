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
const int MAXN = 1e5+1;
int s[MAXN<<2];
int t[MAXN<<2];
int a[MAXN];
int n;

void build(int v,int tl,int tr){
	if(tl==tr){
		t[v]=0;
		s[v]=0;
	}
	else{
		int tm = (tl+tr)/2;
		build(v<<1,tl,tm);
		build((v<<1)|1,tm+1,tr);
		s[v] = s[v<<1]+s[(v<<1)|1];
		t[v] = t[v<<1]+t[(v<<1)|1];
	}
} 
ll queryS(int l,int r,int v=1,int tl=0,int tr=n-1){
	if(l>r){
		return 0;
	}
	if(tl==l&&tr==r){
		return s[v];
	}

	int tm = (tl+tr)/2;
	return queryS(l,min(r,tm),v<<1,tl,tm)+queryS(max(l,tm+1),r,(v<<1)|1,tm+1,tr);
}
ll queryT(int l,int r,int v=1,int tl=0,int tr=n-1){
	if(l>r){
		return 0;
	}
	if(tl==l&&tr==r){
		return t[v];
	}

	int tm = (tl+tr)/2;
	return queryT(l,min(r,tm),v<<1,tl,tm)+queryT(max(l,tm+1),r,(v<<1)|1,tm+1,tr);
}
void addS(int x,int val,int v=1,int tl=0,int tr=n-1){
	if(tl==tr){
		s[v]+=val;
		// cout<<s[]
	}
	else{
		int tm=(tl+tr)/2;
		if(x<=tm){
			addS(x,val,v<<1,tl,tm);
		}
		else{
			addS(x,val,(v<<1)|1,tm+1,tr);
		}
		s[v] = s[v<<1]+s[(v<<1)|1];
		// cout<<tl<<" "<<tr<<" "<<s[v]<<endl;
	}
}

void addT(int x,int val,int v=1,int tl=0,int tr=n-1){
	if(tl==tr){
		t[v]+=val;
	}
	else{
		int tm=(tl+tr)/2;
		if(x<=tm){
			addT(x,val,v<<1,tl,tm);
		}
		else{
			addT(x,val,v<<1|1,tm+1,tr);
		}
		t[v] = t[v<<1]+t[v<<1|1];

	}
}

void solve(){
	ll k;
	cin>>n>>k;
	fl(i,0,n){
		cin>>a[i];
	}
	map<int,int> ind;
	fl(i,0,n){
		ind[a[i]]=0;
	}
	int tmp = 0;
	for(auto &x:ind){
		x.s = tmp++;
	}
	// cout<<tmp<<endl;
	fl(i,0,n){
		// cout<<a[i]<<" "<<ind[a[i]]<<endl;
		a[i] = ind[a[i]];
	}
	build(1,0,tmp-1);
	ll inv = 0;
	fb(i,n,1){
		// cout<<a[i]<<" ";
		inv+=(1LL*queryS(0,a[i]-1));
		addS(a[i],1);
	}
	// cout<<endl;
	// cout<<inv<<endl;
	ll ans=0;
	int l=0,r=1;
	for(;l<n;l++){
		inv+=(1LL*queryT(a[l]+1,n-1));
		addT(a[l],1);
		inv+=(1LL*queryS(0,a[l]-1));

		while(r<n&&(inv>k||r<=l)){
			inv-=(1LL*queryS(0,a[r]-1));
			inv-=(1LL*queryT(a[r]+1,n-1));
			addS(a[r],-1);
			++r;
		}
		// cout<<l<<" "<<r<<endl;
		if(r<n) ans+=1LL*(n-r);
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