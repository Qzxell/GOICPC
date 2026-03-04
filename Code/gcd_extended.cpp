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

ll gcd_ext(ll a, ll b, ll &x, ll &y){
        if(b == 0){
                x = 1;
                y = 0;
                return a;
        }
        ll x1,y1;
        ll g = gcd_ext(b,a%b,x1,y1);
        x = y1;
        y = x1 - (a/b)*y1;
        return g;
}
void so(int test){
        ll a,b,c,x,y;
        cin >> a >> b >> c;
        ll g = gcd_ext(a,b,x,y);
        if((x*-c)%g or (y*-c)%g){
                cout << -1 << ln;
                return;
        }
        cout << (x*-c)/g << ' ' <<  (y*-c)/g << ln;
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



