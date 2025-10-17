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

string dir = "LRUD";
vi dx = {0,0,1,-1};
vi dy = {1,-1,0,0,};

void so(int test){
        int n,m;
        cin >> n >> m;
        vector<string> ma(n);
        vector<string> ans(n,string(m,'.'));
        vector<vi> color(n,vi(m,-1));

        f(i,0,n)cin >> ma[i];
        f(i,0,n){
                int co = 0;
                int tot = 0;
                int un,cero;
                un = cero = 0;
                vi aux;
                f(j,0,m){
                        if(ma[i][j] == 'U'){
                                aux.pb(j);
                                tot++;
                        }
                        if(ma[i][j] == 'D'){
                                tot++;
                                un += (color[i][j] == 1);
                                cero += (color[i][j] == 0);
                        }
                }
                if(tot == 0)continue;
                if(tot&1){
                        cout << -1 << ln;
                        return;
                }
                if(tot - cero < cero or tot - un < un){
                        cout << -1 << ln;
                        return;
                }
                int mi = tot/2;
                f(j,0,mi - un){
                        color[i][aux[j]] = 1;
                        color[i+1][aux[j]] = 0;
                }
                f(j,mi-un,sz(aux)){
                        color[i][aux[j]] = 0;
                        color[i+1][aux[j]] = 1;
                }
        }
        f(i,0,m){
                int co = 0;
                int tot = 0;
                int un,cero;
                un = cero = 0;
                vi aux;
                f(j,0,n){
                        if(ma[j][i] == 'L'){
                                aux.pb(j);
                                tot++;
                        }
                        if(ma[j][i] == 'R'){
                                tot++;
                                un += (color[j][i] == 1);
                                cero += (color[j][i] == 0);
                        }
                }
                if(tot == 0)continue;
                if(tot&1){
                        cout << -1 << ln;
                        return;
                }
                int mi = tot/2;
                if(tot - cero < cero or tot - un < un){
                        cout << -1 << ln;
                        return;
                }
                f(j,0,mi - un){
                        color[aux[j]][i] = 1;
                        color[aux[j]][i+1] = 0;
                }
                f(j,mi-un,sz(aux)){
                        color[aux[j]][i] = 0;
                        color[aux[j]][i+1] = 1;
                }
        }
        f(i,0,n){
                f(j,0,m){
                        if(color[i][j] == -1)cout << '.';
                        else cout << (color[i][j] == 1 ? 'W' : 'B') ;
                }
                cout << ln;
        }


}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;
        cin >> tt;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}



