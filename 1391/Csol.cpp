#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1LL<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1LL<<(i))))
#define setbit1(n,i) ((n)|(1LL<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define DBG(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define EN cout<<"\n"
#define fi first
#define se second
#define PI (acos(-1))
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 200005
template<class T,class V> ostream& operator<<(ostream &s,pair<T,V> a)
{
    s<<a.fi<<' '<<a.se;
    return s;
}

int main()
{
    fastread;
    int T=1;
//    cin>>T;
    for(int qq=1; qq<=T; qq++)
    {
        int n;
        cin>>n;
        vi f(n+1),p(n+1);
        f[0]=p[0]=1;
        for(int i=1;i<=n;i++)f[i]=f[i-1]*i%mod,p[i]=p[i-1]*2%mod;
        ll ans=0;
        for(int i=n;i>=3;i--){
            ans=(ans+f[i-1]*(i-2)%mod*p[n-i]%mod)%mod;
        }
        cout<<ans<<endl;
    }
}
