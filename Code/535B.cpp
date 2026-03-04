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
    string s;
    cin >> s;
    vi v(10,0);
    for (int i = 1 ; i < 10 ; i++){
        v[i] = (1<<i) ;
    }
    int ans = 1;
    int le = sz(s);
    for (int i = 0 ; i < sz(s) ; i++){
        if (s[i] == '7') {
            ans += (1<<(le-1)) ;
        } 
        le--;
    }
    for(int i = 1 ; i < sz(s) ;i++  )ans += v[i];
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
