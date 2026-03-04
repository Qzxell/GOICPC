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
    vii a(n),b(n),c(n);
    for (int i = 0 ; i < n ; i++){
        cin >> a[i].fi; 
        a[i].se = i+1;
    }
    for (int i = 0 ; i < n ; i++){
        cin >> b[i].fi; 
        b[i].se = i+1;
    }
    for (int i = 0 ; i < n ; i++){
        cin >> c[i].fi; 
        c[i].se = i+1;
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    int ans = 0;
    for (int i = max(0,n-4) ; i < n ; i++){
        for (int j = max(0,n-4) ; j < n ; j++){
            for (int k = max(0,n-4) ; k < n ; k++){
                if (a[i].se == b[j].se or a[i].se == c[k].se or c[k].se ==b[j].se ) {
                    continue ;
                }      
                ans = max(ans, a[i].fi + b[j].fi + c[k].fi);
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
