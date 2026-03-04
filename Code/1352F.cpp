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
        int n0,n1,n2;
        cin >> n0 >> n1 >> n2;
        if(n1 == 0){
                f(i,0,max(n0,n2)+1){
                        cout << (n0 == 0 ? 1 : 0) ;
                }
                cout << ln;
                return;
        }
        int gru = n1 + 1;
        string ans;
        f(i,0,n0+1){
                ans += '0';
        }
        f(i,0,n2+1){
                ans += '1';
        }
        gru-= 2;
        f(i,0,gru){
                if(i&1){
                        ans += '1';
                }else ans += '0';
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



