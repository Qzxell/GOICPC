#include <bits/stdc++.h>

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
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int n;
    cin >> n;
    vi v(n);
    f(i,0,n)cin >> v[i];
    ll ans = 0;
    int point = 0;
    f(i,0,n){
        ll wa = 0;
        int cur = v[i];
        for(int j = i ; j >= 0 ;j--){
            cur = min(cur,v[j]);
            wa += cur;
        }
        cur = v[i];
        for(int j = i+1; j < n ; j++){
            cur = min(cur,v[j]);
            wa += cur;
        }
        if (wa > ans) {
            ans = wa; 
            point = i;
        }
    }
    vi wasa;
    int cur = v[point];
    for(int i = point; i >= 0 ;i--){
        cur= min(cur,v[i]);
        wasa.pb(cur);
    }
    reverse(all(wasa));
    cur = v[point];
    for(int j = point+1; j < n ; j++){
        cur = min(cur,v[j]);
        wasa.pb(cur);
    }
    for(int x : wasa)cout << x << ' ';
    cout << ln;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
