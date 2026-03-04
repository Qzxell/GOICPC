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
        int ans = 0;
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        f(i,0,n)if(s[i] == '1'){
                int un = 1;
                for(int j = max<ll>(i-k+1,0); j < i ; j++){
                        if(s[j] == '1'){
                                un = 0;
                                break;
                        }
                }
                ans += un;
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



