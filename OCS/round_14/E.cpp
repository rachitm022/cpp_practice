#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second
#define all(c) c.begin(),c.end()
#define ll long long
#define pcc pair<char,char>
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
	string a,b;
	cin>>a>>b;
	int ans = 0;
	if(n%2) ans+=(a[(n)/2]!=b[(n)/2]);
	fl(i,0,n/2){
		// cout<<ans<<endl;
		pcc temp = {a[i],b[i]};
		pcc temp1 = {a[n-1-i],b[n-1-i]};
		pcc temp2 = {b[n-1-i],a[n-i-1]};
		if(temp==temp1||temp==temp2||(a[i]==b[i]&&a[n-1-i]==b[n-1-i])){
			continue;
		}
		else if(a[i]==b[i]||a[n-i-1]==b[n-i-1]||a[i]==b[n-i-1]||a[n-i-1]==b[i]||b[i]==b[n-1-i]){
			ans++;
		}
		else{ans+=2;}
		// cout<<ans<<endl;
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