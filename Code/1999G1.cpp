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

int query(int a, int b){
        cout << '?' << ' ' << a << ' ' << b << ln;
        int ret;
        cin >> ret;
        return ret;
}
void so(int test){
        int lo = 1;
        int lf = 999;

        f(i,0,6){
                int third = (lf - lo + 1) / 3;
                int mi = lo + third;
                int mi2 = lf - third;
                int qu = query(mi,mi2);
                if(qu == mi*mi2){
                        lo = mi2 + 1;
                        continue;
                }
                if(qu == mi*(mi2+1)){
                        lo = mi+1;
                        lf = mi2;
                        continue;
                }
                if(qu == (mi+1)*(mi2+1)){
                        lf = mi-1;
                }
        }
        cout << '!' << ' ' << lo << ln;
}

int main() {

        int tt = 1;
        cin >> tt;
        int test = 1;
        while (tt--){
                so(test++);
        }
        return 0;
}



