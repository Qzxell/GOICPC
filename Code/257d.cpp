#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define fi first
#define se second

void so(int test){
        int n;
        cin >> n;
        vii v(n);
        vi p(n);
        vector<vi> ma(n,vi(n));

        forn(i,n){
                auto &[a,b] = v[i];
                cin >> a >> b >> p[i];
        }

        ll mx = 0;
        forn(i,n) forn(j,n)if(i !=j)
        {
                ll dis = abs(v[i].se - v[j].se) + abs(v[i].fi - v[j].fi) ; 
                ma[i][j] = (dis+p[i]-1)/p[i];
                mx = max(mx,ma[i][j]);
        }
        auto f = [&](ll s)->bool{
                auto bfs = [&](int nod)->bool{
                        queue<int> qu;
                        qu.push(nod);
                        vector<bool> vis(n,0);
                        vis[nod] = 1;
                        int co = 1;
                        while(!qu.empty()){
                                int fr = qu.front();qu.pop();
                                forn(i,n)if(i != fr and !vis[i] and ma[fr][i] <= s){
                                        qu.push(i);
                                        co++;
                                        vis[i] = 1;
                                }
                        }
                        return co == n;
                };
                forn(i,n)if(bfs(i))return true;
                return false;
        };

        ll lo =0 , lf = mx + 1,mid;
        while(lo < lf){
                mid = (lo+lf)/2;
                if(f(mid)){
                        lf = mid;
                }else{
                        lo = mid+1;
                }
        }
        cout << lo << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


