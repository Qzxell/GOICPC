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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
        int n;
        cin >> n;
        vii v(n);
        forn(i,n){
                auto &[a,b] = v[i];
                cin >> a >> b;
        }
        auto pen = [&](ii a, ii b)->ii{
                int nu = b.se - a.se;
                int de = b.fi - a.fi;
                int gc = gcd(nu,de);
                if(gc){
                        nu /= gc;
                        de /= gc;
                }
                return {nu,de};
        };
        ll ans = 0;
        forn(i,n)
        forsn(j,i+1,n)
        forsn(k,j+1,n){
                int ok = 1;
                if(pen(v[i],v[j]) == pen(v[i],v[k]) or
                pen(v[j],v[i]) == pen(v[j],v[k])){
                        ok = 0;
                }
                ans += ok;
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
