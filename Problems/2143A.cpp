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
#define x real()
#define y imag()

void so(int test){
        int n;
        cin >> n;
        vi v(n);
        int l,r;
        f(i,0,n){
                cin >> v[i];
                if(v[i] == n)l = r = i;
        }
        int bu = n-1;
        while(l >= 0 and r < n){
                if(l - 1 >= 0 and v[l-1] == bu){
                        l--;
                        bu--;
                }else if( r + 1 < n and v[r+1] == bu){
                        r++;
                        bu--;
                }else {
                        break;
                }
        }
        cout << (bu == 0 ? "YES" : "NO" ) << ln;
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



