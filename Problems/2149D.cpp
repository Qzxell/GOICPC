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
        int n,k,l,r;
        cin >> n >> k >> l >> r;
        vi v(n);
        f(i,0,n)cin >> v[i];

        vi d;
        d = v;
        sort(all(d));
        d.erase(unique(all(d)), d.end());
        f(i,0,n) v[i] = lower_bound(all(d), v[i]) - d.begin();
        int c = d.size(); // cantidad de distintos

        vector<int> pr1(c, 0);
        vector<int> pr2(c, 0);
        // map<int,int> pr1;
        // map<int,int> pr2;

        int punt1 = 0;
        int punt2 = 0;

        int gru1 = 0;
        int gru2 = 0;

        ll ans = 0;
        f(i,0,n){
                while(gru1 < k and punt1 < n){
                        if(pr1[v[punt1]] == 0){
                                gru1++;
                        }
                        pr1[v[punt1]]++;
                        punt1++;
                }
                while(gru2 < k and punt2 < n){
                        if(pr2[v[punt2]] == 0){
                                gru2++;
                        }
                        pr2[v[punt2]]++;
                        punt2++;
                }
                while(punt2 < n){
                        if(pr2[v[punt2]] > 0){
                                pr2[v[punt2]]++;
                                punt2++;
                        }else{
                                break;
                        }
                }
                if(gru1 == k and gru2 == k){
                        //cout << i+1 << ' ' << punt1 << ' ' << punt2 << ln;
                        //cout << punt2 - punt1  << ln;
                        int dis1 = punt1 - i ;
                        int dis2 = punt2 - i ;
                        int inf_mi = max(dis1,l);
                        int inf_ma = min(dis2,r);
                        if(inf_mi <= inf_ma)ans += inf_ma - inf_mi +1;
                }
                if(pr1[v[i]] == 1){
                        gru1--;
                }
                if(pr2[v[i]] == 1){
                        gru2--;
                }
                pr1[v[i]]--;
                pr2[v[i]]--;
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


