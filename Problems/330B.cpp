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
        int n,m;
        cin >> n >> m;
        vi v(n+1,0);
        f(i,0,m){
                int u,h;
                cin >> u >> h;
                v[u] = 1;
                v[h] = 1;
        }
        int rot = -1 ;
        f(i,1,n+1){
                if(!v[i]){
                        rot = i;
                        break;
                }
        }
        cout << n-1 << ln;
        f(i,1,n+1)if(i != rot){
                cout << rot << ' ' << i << ln;
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



