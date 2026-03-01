#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

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
        int n, k;
        cin >> n >> k;
        int tot = n * k;
        
        vii app(tot);
        forn(i, tot){
                cin >> app[i].fi >> app[i].se;
        }
        
        sort(rall(app));
        priority_queue<int, vi, greater<int>> pq;
        ll ans = 0;
        
        forn(i, tot){
                pq.push(app[i].se);
                ans += app[i].se;
                
                if (sz(pq) > (i + 1) / n) {
                        ans -= pq.top();
                        pq.pop();
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
