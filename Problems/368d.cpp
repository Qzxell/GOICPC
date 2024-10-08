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
    int n,k;
    cin >> n >> k;
    vi tree[n+1];
    for (int i = 0 ; i < n-1 ; i++){
        int a,b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    vi ed(k);
    for (int i = 0 ; i < k ; i++){
        cin >> ed[i]; 
    }

    vi dis(n+1,-1);
    auto f = [&](int r){
        int rot = r;
        queue<int> q;
        q.push(rot);
        dis[rot] = 0;
        while(!q.empty()){
            int nod = q.front();
            q.pop();
            for(int x : tree[nod]){
                if (dis[x] != -1) {
                    continue; 
                }
                dis[x] = dis[nod] + 1;
                q.push(x);
            }
        }
    };
    f(ed[0]);
    int d = -1;
    int two = 0;
    for (int i = 0 ; i < n+1; i++){
        if (dis[i] == -1) {
            continue; 
        }
        if (dis[i] > d) {
            d = dis[i]; 
            two = i;
        }
    }
    for (int i = 0 ; i < n+1 ; i++){
        dis[i] = -1; 
    }
    f(two);
    cout << two;
    int ans = 0;
    for (int i = 0 ; i < n+1 ; i++){
        if (dis[i] == -1) {
            continue; 
        } 
        ans = max(dis[i], ans);
    }
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
