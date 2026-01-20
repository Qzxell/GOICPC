#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        int n,k;
        cin >> n>> k;
        int ga = 1e9;
        auto s = [&] (int nu)->ll{
                return (nu*1ll*(nu+1))/2;
        };
        auto qu = [&] (int l , int r)->ll{
                return s(r) - s(l-1);
        };

        auto f = [&](int mid)->ll{
                return qu(k,mid) - qu(mid+1,n+k-1);
        };

        int lo = k, lf = n + k - 1,mid;
        while(lo < lf){
                mid = (lo+1+lf)/2;
                if(f(mid) < 0){//11111110000
                        lo = mid;
                }else {
                        lf = mid-1;
                }
        }
        ll ans = min(f(lo+1),abs(f(lo)));
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


