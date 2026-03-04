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
    vi v(n);
    for (int i = 0 ; i < n ; i++){
        cin >> v[i] ;
    }
    auto f = [&](ll &x,int &h){
        ll c = 0;
        while(x %3 != 0 and h > 0){
            x++;
            h--;
            c++;
        }
        if (h == 0) {
            return c;     
        }
        x += (h/5)*3;
        c += (h/5)*3;

        h %= 5;
        while(h > 0){
            if (x%3 == 0) {
                h -= 3; 
            }else h--;
            x++;
            c++;
        }
        return c;

    };
    ll k = 1;
    ll ans = 0;
    for (int i = 0 ; i < n ; i++){
        ll u = f(k,v[i]);
        ans += u ;
    }
    int j = 9;
    ll u = 2;
    ll x =  f(u, j) ;
    cout << ans;
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
