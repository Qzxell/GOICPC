#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define point complex<long long>
#define re real()
#define im imag()

void so(int test){
        int n; int u,v;
        cin >> n;
        vector<vi> G(n+1);
        map<ii,int> fun;//edge -> idx
        map<ii,bool> colored;//edge -> idx
        vi ans(n+1);//idx -> color
        vi deg(n+1,0);
        f(i,0,n-1){
                cin >> u >> v;
                if(u > v)swap(u,v);
                fun[{u,v}] = i;
                G[u].pb(v);
                G[v].pb(u);
                deg[u]++;
                deg[v]++;
        }
        queue<int> qu;
        f(i,1,n+1){
                if(deg[i] == 1)qu.push(i);
        }
        int co = 0;
        vector<bool> vis(n+1,0);
        while(!qu.empty()){
                int fr = qu.front();qu.pop();
                vis[fr] = 1;
                for(auto x : G[fr]){
                        if(!vis[x])qu.push(x);
                        u = fr;v = x;
                        if(u > v)swap(u,v);
                        if(colored[{u,v}])continue;
                        ans[fun[{u,v}]] = co++;
                        colored[{u,v}] = 1;
                        vis[x] = 1;
                }
        }
        f(i,0,n-1){
                cout << ans[i] << ln;
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}



