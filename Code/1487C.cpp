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
        if(n&1){
                f(i,1,n){
                        int co = 1;
                        f(j,i+1,n+1){
                                cout << (co <= n/2 ? 1 : -1) << ' ';
                                co++;
                        }
                }
                cout << ln;
                return;
        }
        if(n==2){
                cout << 0 << ln;
                return;
        }
        f(i,1,n){
                int co = 1;
                f(j,i+1,n+1){
                        if(co <= (n-1)/2)cout << 1 << ' ';
                        else if(co == (n+1)/2)cout << 0 << ' ';
                        else cout << -1 << ' ';
                        co++;
                }
        }
        cout << ln;
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



