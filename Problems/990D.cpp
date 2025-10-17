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

void so(int test){
        int n,a,b;
        cin >> n >> a >> b;
        if(a > 1 and b > 1){
                cout << "NO" << ln;
                return;
        }
        vector<vi> adj(n+1,vi(n+1,0));
        if(b == 1){
                if(a == 1){
                        if(n == 2 or n == 3){
                                cout << "NO" << ln;
                                return;
                        }
                }
                f(i,a,n){
                        adj[i][i+1] = 1;
                        adj[i+1][i] = 1;
                }
                cout << "YES" << ln;
                f(i,1,n+1){
                        f(j,1,n+1){
                                cout << adj[i][j];
                        }
                        cout << ln;
                }
                return;
        }
        f(i,1,n+1)f(j,1,n+1)if(i!=j)adj[i][j] = 1;
        f(i,1,n-b+1){
                adj[i][i+1] = 0;
                adj[i+1][i] = 0;
        }
        cout << "YES" << ln;
        f(i,1,n+1){
                f(j,1,n+1){
                        cout << adj[i][j];
                }
                cout << ln;
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



