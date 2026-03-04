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

const int N = 8;
int n,m;
int G[N][N];

vector<vi> formas;

vi bac;
void su(int n){
        if(n == 0){
                formas.pb(bac);
                return;
        }
        if(n < 3)return;
        f(i,3,n+1){
                bac.pb(i);
                su(n-i);
                bac.pop_back();
        }
        return;
}

void so(int test){
        cin >> n >> m;
        vi deg(n+1,0);
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                u--;v--;
                G[u][v] = 1;
                G[v][u] = 1;
                deg[u]++;
                deg[v]++;
        }
        vi nod(n);
        f(i,0,n)nod[i] = i;
        su(n);
        int ans = INT_MAX;
        do{
                for (auto sums :formas) {
                        vector<vi> aux(n,vi(n,0));
                        int cur = 0;
                        for (auto lon :sums) {
                                vi uwu;
                                for(int i = 0; i < lon; i++,cur++){
                                        uwu.pb(nod[cur]);
                                }
                                f(i,0,sz(uwu)){
                                        int cur = uwu[i];
                                        int nex = uwu[(i+1)%lon];
                                        aux[cur][nex] = 1;
                                        aux[nex][cur] = 1;
                                }
                        }
                        int punt = 0;
                        f(i,0,n){
                                f(j,0,n){
                                        punt += (aux[i][j] != G[i][j]);
                                }
                        }
                        punt /= 2;
                        ans = min(ans,punt);
                }
        }while(next_permutation(all(nod)));
        cout << ans << ln;
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



