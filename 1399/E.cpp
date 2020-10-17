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
const int MAXN = 2e5+1;
ll cur;
ll n;
ll num[MAXN];
class Compare
{
	public:
	    bool operator() (pair<ll,int> x, pair<ll,int> y)
	    {
	        return (x.s*1LL*(x.f-(x.f/2)))<(y.s*1LL*(y.f-(y.f/2)));
    	}
};

void dfs(int node,ll sum,vector<vector<pii>>& adj,int par=-1){
	// cout<<node<<endl;
	if(adj[node].size()==1&&node!=1){
		num[node] = 1;
		cur+=sum;
		return;
	}
	for(auto p:adj[node]){
		if(p.f==par) continue;
		dfs(p.f,sum+p.s,adj,node);
		num[node]+=num[p.f];
	}
}
void solve(){
	ll s;
	cin>>n>>s;
	ll ans = 0;
	cur = 0;
	memset(num,0,sizeof(num));
	vector<vector<pii>> adj(n+1);
	vector<vector<ll>> inp;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,Compare> c1;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,Compare> c2;
	stack<ll> lastOne,lastTwo;
	fl(i,0,n-1){
		ll u,v,w,c;
		cin>>v>>u>>w>>c;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
		inp.push_back({u,v,w,c});
	}
	dfs(1,0LL,adj);
	fl(i,0,n-1){
		if(inp[i][3]==1){
			c1.push({inp[i][2],min(num[inp[i][1]],num[inp[i][0]])});	
		}
		else{
			c2.push({inp[i][2],min(num[inp[i][1]],num[inp[i][0]])});
		}
	}
	while(cur>s){
		// cout<<cur<<" "<<ans<<endl;
		if(c1.empty()){
			auto cost2 = c2.top();
			c2.pop();
			ll rem2 = cost2.s*(cost2.f-(cost2.f/2LL));
			c2.push({cost2.f/2LL,cost2.s});
			cur-=rem2;
			lastTwo.push(rem2);
			ans+=2;
			// cout<<"here1"<<endl;
		}
		else if(c2.empty()){
			auto cost1 = c1.top();
			c1.pop();
			ll rem1 = cost1.s*(cost1.f-(cost1.f/2LL));
			c1.push({cost1.f/2LL,cost1.s});
			cur-=rem1;
			ans+=1;
			lastOne.push(rem1);
			// cout<<"here2"<<endl;
		}
		else{
			auto cost1 = c1.top();
			c1.pop();
			auto cost2 = c2.top();
			c2.pop();
			ll rem2 = cost2.s*(cost2.f-(cost2.f/2LL));
			ll rem1 = cost1.s*(cost1.f-(cost1.f/2LL));
			// cout<<rem1<<endl;
			if(cur-rem1<=s){
				ans++;
				cur-=rem1;
				lastOne.push(rem1);
				break;
			}
			else if(rem1>=rem2){
				c2.push(cost2);
				c1.push({cost1.f/2LL,cost1.s});
				cur-=rem1;
				lastOne.push(rem1);
				ans++;
			}
			else{
				// c1.push({cost1.f/2LL,cost1.s});
				ll rem3 = -1;
				pair<ll,int> cost3;
				if(!c1.empty()){
					cost3 = c1.top();
					c1.pop();
					rem3 = cost3.s*(cost3.f-(cost3.f/2LL));
				}
				ll rem4 = cost1.s*((cost1.f/2LL)-((ll)(cost1.f/2LL)/2LL));
				ll rem5 = max(rem3,rem4);
				// cout<<rem5<<endl;
				if(rem1+rem3>rem2){
					c1.push({cost1.f/2LL,cost1.s});
					if(rem5==rem3) c1.push({cost3.f/2LL,cost3.s});
					else if(rem5==rem4) c1.push({((ll)(cost1.f/2LL)/2LL),cost1.s});
					else assert(0);
					c2.push(cost2);
					cur-=(rem1+rem5);
					lastOne.push(rem1);
					lastOne.push(rem5);
					// cout<<"here3"<<endl;
				}
				else{
					if(rem5==rem3) c1.push(cost3);
					c1.push(cost1);
					c2.push({cost2.f/2LL,cost2.s});
					cur-=rem2;
					lastTwo.push(rem2);
					// cout<<"here4"<<endl;
				}
				ans+=2;
				/*c1.push(cost1);
				c2.push({cost2.f/2LL,cost2.s});
				cur-=rem2;
				lastOne=rem1;
				ans+=2;*/		 
			}
		}
	}
	// cout<<cur<<" "<<ans<<endl;
	// cout<<lastOne.front()<<endl;
	while((!lastOne.empty()||!lastTwo.empty())&&cur+min((lastOne.empty()?s-cur+1:lastOne.top()),(lastTwo.empty()?s-cur+1:lastTwo.top()))<=s){
		if(!lastTwo.empty()&&cur+lastTwo.top()<=s){
			ans-=2;
			cur+=lastTwo.top();
			lastTwo.pop();
		}

		if(!lastOne.empty()&&cur+lastOne.top()<=s){
			ans-=1;
			cur+=lastOne.top();
			lastOne.pop();
		}
	}
	// cout<<cur<<endl;
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