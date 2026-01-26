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
        Fenwick(const vector<int>& a) {
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

        ll query(int i) { 
                ll ans = 0;
                for (; i > 0; i -= i & -i) 
                ans += t[i];
                return ans;
        }

        ll query(int l, int r) { 
                return query(r) - query(l - 1);
        }
};

void so(int test){
        int n,q;
        cin >> n >> q;
        vector<vi> T(n);
        vi tin(n),tou(n),val(n);
        int TIM = 0;
        forn(i,n)cin >> val[i];
        forn(i,n-1){
                int a,b;
                cin >> a >> b;
                a--;
                b--;
                T[a].push_back(b);
                T[b].push_back(a);
        }
        auto dfs = [&](auto && self, int nod, int pat)-> void{
                tin[nod] = TIM++;
                for(auto x : T[nod])if(x != pat){
                        self(self,x,nod);
                }
                tou[nod] = TIM;
        };
        dfs(dfs,0,-1);
        Fenwick ft(n);
        forn(i,n){
                ft.add(tin[i]+1,val[i]);
                ft.add(tou[i]+1,-val[i]);
        }

        forn(i,q){
                int op,s,x;
                cin >> op;
                if(op == 1){
                        cin >> s >> x;
                        s--;
                        int cam = x - val[s];
                        ft.add(tin[s]+1,cam);
                        ft.add(tou[s]+1,-cam);
                        val[s] = x;
                }else{
                        cin >> s;
                        s--;
                        cout << ft.query(tin[s]+1) << '\n';
                }
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
