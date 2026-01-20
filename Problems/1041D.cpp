#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
        int n,h;
        cin >> n >> h;
        vii v(n);
        vi dif(n-1),seg(n) ;
        vl ps(n,0),ps_seg(n+1,0);
        forn(i,n){
                auto &[a,b] = v[i];
                cin >> a >> b;
                seg[i] = b-a;
        }

        forn(i,n-1) dif[i] = v[i+1].first - v[i].second;
        forsn(i,1,n) ps[i] = ps[i-1] + dif[i-1];
        forsn(i,1,n+1) ps_seg[i] = ps_seg[i-1] + seg[i-1];

        ll ans = 0;
        forn(i,n){
                int lo = i, lf = n,mid;
                while(lf - lo > 1){
                        mid = lo + (lf-lo)/2;
                        ll val = ps[mid] - ps[i];
                        if(val < h){
                                lo = mid;
                        }else{
                                lf = mid;
                        }
                }
                ans = max(ans, h + ps_seg[lo+1] - ps_seg[i]  );
        }
        cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


