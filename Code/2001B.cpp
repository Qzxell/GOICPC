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
    if (n%2 == 0) {
        cout << -1 << ln;
        return;
    }
    vi ans(n,0);
    for (int i = n/2 ; i < n ; i++){
        ans[i] = i - n/2 + 1;     
    }
    for (int i = n/2-1 ; i >= 0; i--){
        ans[i] = n - i  ;
    }
    for (int i = 0 ; i < n ; i++){
        cout << ans[i] << ' ';   
    }
    cout << ln;

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
