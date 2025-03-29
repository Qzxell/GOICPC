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

void so(int test){
        int n;
        cin>> n;
        vi v(n);
        vi dis(n);
        vi vis(n,0);
        f(i,0,n)cin >> v[i];
        sort(all(v));
        f(i,0,n)dis[i] = i;
        auto bs = [&](int ind){
                int lo = 0;
                int lf = ind;
                int mid;
                while(lo < lf){
                        mid = (1+lo+lf)/2;
                        int wa = 1;
                        f(i,0,mid + 1)
                                if(v[i] > v[n-mid-1 + i]/2){
                                        wa=0;break;
                                }

                        if(wa)lo = mid;
                        else lf = mid-1;
                }
                int wa = 1;
                f(i,0,lo + 1)
                        if(v[i] > v[n-lo-1 + i]/2){
                                wa=0;break;
                        }
                if(!wa)return -1;
                return lo;
        };
        int ans = bs((n)/2 - 1);
        cout << ans + 1 ;
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

