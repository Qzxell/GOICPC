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
    int x ,y ,z ;
    ll k;
    int p;
    ll ans =0 ;
    cin >> x >> y >> z >> k;
    for (int i = 1 ; i <= x ; i++){
        for (int j = 1 ; j <= y ; j++){
            if (k%(i*j) == 0 and k/(i*j) <= z) {
                p = k/(i*j);
                ll conf = (z-p+1)*1ll*(y-j+1)*(x-i+1);
                ans = max(ans,conf);
            } 
        }
    }
    cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--){
        so();
    }
    return 0;
}
