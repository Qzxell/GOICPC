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
        vi frec(103,0);
        f(i,0,n){
                int x ;cin >> x;
                v[i] = x;
                frec[x]++;
        }
        if(frec[0] > 0){
                cout << n - frec[0] << ln;
                return;
        }
        f(i,0,101){
                if(frec[i] > 1){
                        cout << n << ln;
                        return;
                }
        }
        cout << n+1 << ln;

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



