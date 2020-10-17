#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

string maxString(string A,string B){
	int n = A.length();
	int m = B.length();
	if(n==0) return B;
	if(m==0) return A;
	for(int i=0;i<min(n,m);i++){
		if(A[i]>B[i]) return A;
		else if(A[i]<B[i]) return B;
	}
	return n>m?A:B;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		//cout<<n<<k<<endl;
		string A;
		cin>>A;
		sort(A.begin(),A.end());
		if(A[0]!=A[k-1]){
			cout<<A[k-1]<<endl;
			continue;
		}
		cout<<A[0];
		if(A[k]!=A[n-1]){
			cout<<A.substr(k)<<endl;
			continue;
		}
		else{
			for(int i=k;i<n;i+=k)
				cout<<A[i];

			cout<<endl;
		}
	}
	return 0;
}