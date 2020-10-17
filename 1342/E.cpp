#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define f first
#define s second
#define ll long long
#define pb push_back

void solve(){
	int n,m,a,b,c;
	cin>>n>>m>>a>>b>>c;
	ll price[m];
	ll pre[m];
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		cin>>price[i];
	}
	sort(price,price+m);
	for(int i=0;i<m;i++){
		pre[i] = (i?pre[i-1]:0) + price[i];
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vll ca(n+1,LLONG_MAX);
	vll cb(n+1,LLONG_MAX);
	vll cc(n+1,LLONG_MAX);
	//bool visited[n+1] = {0};
	auto bfs = [&](int x,vll& dist){
		queue<int> q;
		q.push(x);
		dist[x] = 0;
		while(!q.empty()){
			auto tp = q.front();
			q.pop();
			for(auto node:adj[tp]){
				if(dist[node]==LLONG_MAX){
					dist[node] = dist[tp] + 1;
					q.push(node);
				}
			}
		}
	};
	bfs(a,ca);
	bfs(b,cb);
	bfs(c,cc);
	// for(int x:ca)cout<<x<<" ";
	// cout<<endl;
	// for(int x:cb)cout<<x<<" ";
	// cout<<endl;
	// for(int x:cc)cout<<x<<" ";
	// cout<<endl;
	
	ll ans = LLONG_MAX;
	for(int i=1;i<=n;i++){
		ll temp = ca[i]+cb[i]+cc[i];
		if(temp>m) continue;
		else{
			ans = min(ans,(cb[i]?pre[cb[i]-1]:0)+(ca[i]+cb[i]+cc[i]?pre[ca[i]+cb[i]+cc[i]-1]:0));
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