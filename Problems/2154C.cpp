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

const int N = 2e5 + 5;
vector<vi> fact(N);
vector<int> comp(N,0);
vi exi(N,0);

void so(int test){ int n; cin >> n; vi a(n),b(n);
        f(i,0,n){
                cin >> a[i];
        }
        f(i,0,n){
                for(auto x : fact[a[i]]){
                        exi[x] = 0;
                }
                for(auto x : fact[a[i]+1]){
                        exi[x] = 0;
                }
        }
        f(i,0,n)cin >> b[i];
        f(i,0,n){
                for(auto x : fact[a[i]]){
                        exi[x]++;
                        if(exi[x] > 1){
                                cout << 0 << ln;
                                return;
                        }
                }
        }
        f(i,0,n){
                for(auto x : fact[a[i]]){
                        exi[x]--;
                }
                for(auto x : fact[a[i]+1]){
                        if(exi[x]){
                                cout <<1 << ln;
                                return;
                        }
                }
                for(auto x : fact[a[i]]){
                        exi[x]++;
                }
        }
        cout << 2 << '\n';

}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int op = 0;
        f(i,2,N){
                if(comp[i])continue;
                for(int j = i; j < N ; j += i){
                        comp[j] = 1;
                        fact[j].pb(i);
                }
        }
        int tt = 1;
        cin >> tt;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}



