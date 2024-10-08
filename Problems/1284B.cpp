#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(){
    int n;
    cin >> n;
    vii v;
    int c = 0;
    for (int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        ii cur = {0,0};
        bool yes = 0;
        for (int j = 0 ; j < x ; j++){
            int p;
            cin >> p;
            if (j == 0) {
                cur.fi =  p;
                cur.se =p;
                continue;
            } 
            if (p > cur.se) {
                yes = 1;
            }
            cur.fi = max(p,cur.fi);
            cur.se = min(p,cur.se);
        }
        if (yes) {
            c++; 
        }else v.pb(cur);
    }
    sort(all(v));
    ll ans = c*1ll*(2*n-1);
    int le = sz(v);
    for (int i = 0 ; i < le ; i++){
        int lo, f , mid;
        lo = 0;
        f = le-1;
        int cur = v[i].se;
        while(lo < f){
            mid = (lo+f)/2;
            if (v[mid].fi <= cur) {
                lo = mid+1; 
            }else f = mid;
        }
        cout << v[i].fi << ' ' << cur << " -> ";
        cout << v[lo].fi << ' ' << v[lo].se << ' ';
        if (v[lo].fi <= cur) {
            cout << 0 << ln;
        }else {
            ans += le - lo;
            cout << le -lo << ln;
        }
    }
    cout << ans ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
