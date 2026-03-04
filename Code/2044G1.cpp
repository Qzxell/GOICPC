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
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int n;
    cin >> n;
    vi freq(n+1,0);
    vi v(n+1,0);
    vector<bool> vis(n+1,false);
    f(i,1,n+1){
        int x;
        cin >> x;
        v[i] = x;
        freq[x]++;
    }
    queue<int> qu;
    vi ans(n+1,0);
    for(int i = 1; i < n+1;i++)if(freq[i] == 0){
        qu.push(i);
        ans[i] = 1;
    }
    if (qu.empty()) {
        cout << 2 << ln;
        return;
    }
    while(!qu.empty()){
        int u = qu.front();
        if (freq[u] != 0) {
            qu.pop(); 
            continue;
        }
        int to = v[u];
        freq[to]--;
        if (!vis[to]) {
            qu.push(to);
            ans[to] = max(ans[to],ans[u] + 1);
            vis[to] = 1;
        }
            qu.pop();
    }
    cout << *max_element(all(ans)) + 1 << ln; 
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
