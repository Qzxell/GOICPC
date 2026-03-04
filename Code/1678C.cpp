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
        int n;
        cin >> n;
        vi v(n);
        f(i,0,n)cin >> v[i];

        vector<vi> men(n+2,vi(n+2,0));
        vector<vi> ps(n+2,vi(n+2,0));

        // men[i][j] := tamano del conjunto de indices  k que son mayores que j y que cumplen v[k] < v[i]
        f(i,0,n){
                for(int j = n-1 ; j >= i ; j--){
                        if(j == n-1){
                                continue;
                        }
                        men[i][j] = men[i][j+1] + (v[j+1] < v[i] ? 1 : 0);
                }
        }

        f(j,0,n){
                f(i,1,j+1){
                        ps[j][i] = ps[j][i-1] + men[i-1][j];
                }
        }
        ll ans = 0;
        f(i,0,n){
                f(j,i+1,n)if(v[i] < v[j]){
                        ans += ps[j][j] - ps[j][i+1];
                }
        }
        cout << ans << ln;
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



