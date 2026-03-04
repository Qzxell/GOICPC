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


int f(vi &v){
    int x = 0;
    for (int i = 0 ; i < sz(v) ; i++){
        if (v[i]) {
            x++; 
        } 
    }
    return x;
}
void so(){
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0 ; i < n ; i++){
        cin >> v[i] ;
    }
    int c = 0;

    while(f(v) >= 2){
        sort(all(v));
        reverse(all(v));
        v[0]--;
        v[1]--;
        c++;
    }
    cout << c;
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
