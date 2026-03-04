#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,ll>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()


void so(int test){
        int n,m,l,s,t;
        cin >> n >> m >> l >> s >> t;
        vector<vii> T(n+1);
        forn(i,m){
                ll u,v,c;
                cin >> u >> v >> c;
                T[u].push_back({v,c});
        }
        vii v;
        v.push_back({1,0});
        forn(i,l){
                vii uwu;
                for(auto [nod,cur_cos] : v){
                        for(auto [x,c] : T[nod]){
                                uwu.push_back({x,c + cur_cos});
                        }
                }
                swap(uwu,v);
        }
        set<int> ans;
        for(auto [nod,c] : v){
                if(s <= c and c <= t){
                        ans.insert(nod);
                }
        }
        for(auto x: ans){
                cout << x << ' ';
        }
        cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
