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
        int n,k;
        cin >> n >> k;
        vi v(n+1);
        int fir = -1;
        int ul = -1;
        f(i,1,n+1){
                cin >> v[i];
                if(fir == -1 and v[i] == 0)fir = i;
                if(v[i] == 0) ul = i;
        }
        if(fir == -1){
                cout << 0 << ln;
                return;
        }
        int acu = 0;
        f(i,fir,ul)acu += v[i];
        int ans = ul - fir + 1 + acu;
        if(k < fir){
                ans += (fir - k - 1)*2;
        }else if( k > ul){
                ans += (k - ul)*2;
        }
        cout << ans << ln;
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



