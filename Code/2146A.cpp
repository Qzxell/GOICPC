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

void so(int test){
        int n,m;
        cin >> n >> m;
        vi frec(m+1,0);
        vector<vi> v;
        f(i,0,n){
                int lon ;
                cin >> lon;
                vi ga;
                f(j,0,lon){
                        int x ;
                        cin >> x;
                        frec[x]++;
                        ga.pb(x);
                }
                v.pb(ga);
        }
        f(i,1,m+1){
                if(frec[i] == 0){
                        cout << "NO" << ln;
                        return;
                }
        }
        int way = 1;
        f(i,0,n){
                bool ok = 1;
                f(j,0,sz(v[i])){
                        if(frec[v[i][j]] == 1){
                                ok = 0;
                                break;
                        }
                }
                if(ok)way++;
        }
        if(way >= 3){
                cout << "YES" << ln;
                return;
        }
        cout << "NO" << ln;
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



