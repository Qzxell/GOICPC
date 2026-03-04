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
        vector<vi> T(n);
        forn(i,n-1){
                int a,b;
                cin >> a >> b;
                a--;b--;
                T[a].push_back(b);
                T[b].push_back(a);
        }
        vl dp(n,0);
        vi pes(n,1);
        auto dfs1 = [&](auto && self, int nod, int pat)-> void{
                for(auto x : T[nod])if(x != pat){
                        self(self,x,nod);
                }
                for(auto x : T[nod])if(x != pat){
                        pes[nod] += pes[x];
                        dp[nod] += dp[x] + pes[x];
                }
        };
        dfs1(dfs1,0,-1);
        vl ans(n);
        auto dfs = [&](auto && self, int nod, int pat)-> void{
                ans[nod] = dp[nod];
                for(auto x : T[nod])if(x != pat){
                        ll ga = dp[x];
                        ll uwu = pes[x];
                        dp[x] += dp[nod] - dp[x] - pes[x] + (pes[nod] - pes[x]);
                        pes[x] = n;
                        self(self,x,nod);
                        dp[x] = ga;
                        pes[x] = uwu;
                }
        };
        dfs(dfs,0,0);
        forn(i,n)cout << ans[i] << ' ';
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
