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
        vi v(n);
        forn(i,n)cin >> v[i];
        if(is_sorted(all(v))){
                cout << -1 << '\n';
                return;
        }
        vi ga = v;
        sort(all(ga));
        int mi,ma,ok = 0;
        forn(i,n) if(ga[i] != v[i]){
                if(!ok){
                        mi = ma = v[i];
                        ok = 1;
                        continue;
                }
                mi = min(mi,v[i]);
                ma = max(ma,v[i]);
        }
        int ans = (1<<30);
        forn(i,n) if(ga[i] != v[i]){
                ans = min(ans,max(abs(v[i] - mi),abs(ma - v[i])));
        }
        cout << ans << '\n';
}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >>  tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
