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
        vi v(n+n),ps(n+n+1,0),suf(n+n+2,0);
        forn(i,n+n)cin >> v[i];
        forsn(i,1,n+n+1)ps[i] = ps[i-1] + (v[i-1] == 1 ? 1 : -1);
        for(int i = n + n ; i > n ; i--)suf[i] = suf[i+1] + (v[i-1] == 1 ? 1 : -1);
        map<int,int> m,m_;
        forsn(i,0,n+1)m[ps[i]] = i;
        for(int i = n + n + 1 ; i > n ; i--)m_[suf[i]] = i;
        int tot = 2*n;
        int ans = (1<<30);
        //cout << "===========\n";
        for(auto [x,ind] : m){
                if(m_.count(-x)){
                        //cout << x << ' ' << m_[-x] << ' ' << m[x] << '\n';
                        ans = min(ans,m_[-x]-m[x] - 1);
                }
        }
        //if(ans == (1<<30))ans = n+n;
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
