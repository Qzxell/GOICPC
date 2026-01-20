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

struct Fenwick {//1-indexed
        int n;
        vector<ll> t;

        Fenwick(int sz) {
                n = sz;
                t.assign(n + 1, 0);
        }
        Fenwick(const vector<ll>& a) {
                n = a.size();
                t.assign(n + 1, 0);

                for (int i = 0; i < n; i++) {
                        t[i + 1] = a[i];
                }

                for (int i = 1; i <= n; i++) {
                        int parent = i + (i & -i);
                        if (parent <= n) {
                                t[parent] += t[i];
                        }
                }
        }

        void add(int i, ll val) {
                for (; i <= n; i += i & -i) 
                        t[i] += val;
        }

        ll query(int i) { // Prefix sum [1, i]
                // i++; // Descomenta si usas indices base-0 en el main
                ll ans = 0;
                for (; i > 0; i -= i & -i) 
                ans += t[i];
                return ans;
        }

        ll query(int l, int r) { // Range sum [l, r]
                return query(r) - query(l - 1);
        }
};
void so(int test){
        int n;
        cin >> n;
        vi v(n);
        vi vis(n+1);
        forn(i,n)cin >> v[i];
        Fenwick ft(n +1);
        ll inv = 0;
        forn(i,n){
                int x = v[i];
                if(vis[x]){
                        cout << "YES\n";
                        return;
                }
                inv += ft.query(x+1,n);
                ft.add(x,1);
                vis[x] = 1;
        }
        cout << ( inv&1 ? "NO" : "YES") << '\n';

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


