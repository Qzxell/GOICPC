#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second

const int mod = 1e9 + 7;

int ad(ll a, ll b){
        return (a+b)%mod;
}

int mul(ll a, ll b){
        return (a%mod * b%mod)%mod;
}
int fp(int b,int e){
        ll ret = 1;
        while(e){
                if(e&1){
                        ret = mul(ret,b);
                }
                b = mul(b,b);
                e >>= 1;
        }
        return ret;
}

void so(int test){
        int n;
        cin >> n;
        vl v(n);
        forn(i,n)cin >> v[i];
        ll ans = 0;
        forn(j,62) {
                ll on,of;
                on = of = 0;
                forn(i,n){
                        if((v[i]>>j)&1){
                                ans = ad(ans, mul(of,(1ll<<j)%mod));
                                on++;
                        }else{
                                ans = ad(ans, mul(on,(1ll<<j)%mod));
                                of++;
                        }
                }
        }
        cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


