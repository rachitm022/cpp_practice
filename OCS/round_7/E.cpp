#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second
bool mycmp(const pair<int,pii> a, const pair<int,pii> b){
	if(a.f==b.f){
		return a.s.s>b.s.s;
	}
	return a.f<b.f;
}
void solve(){
	int n;
	cin>>n;
	vector<pair<int,pii>> pts;
	vector<bool> done(n,false);
	vi ans;
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		pts.push_back({min(l,r),{i,1}});
		pts.push_back({max(l,r),{i,0}});
	}
	sort(pts.begin(), pts.end(),mycmp);
	stack<int> st;
	for(int i=0;i<pts.size();i++){
		//cout<<pts[i].s.f<<endl;
		if(!pts[i].s.s&&!done[pts[i].s.f]){
			ans.push_back(pts[i].f);
			while(!st.empty()){
				auto tp = st.top();
				st.pop();
				done[tp] = true;
				//cout<<tp<<endl;
			}
		}
		st.push(pts[i].s.f);
	}
	cout<<ans.size()<<endl;
	for(int val:ans) cout<<val<<" ";
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T=1;
	// cin>>T;
	while(T--)
		solve();

	return 0;
}