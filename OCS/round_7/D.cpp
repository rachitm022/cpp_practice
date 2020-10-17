#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define f first
#define s second

void solve(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vi fact;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			fact.push_back(i);
			fact.push_back(n/i);
		}
	}
	fact.push_back(1);
	for(int i=0;i<(int)fact.size();i++){
		for(int j=0;j<fact[i];j++){
			bool f = (n/fact[i]>2);
			for(int k=j;k<n;k+=fact[i]){
				if(a[k]==0){
					f = false;
					break;
				}
			}
			if(f){
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
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