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

    ll ga = 0;
    int c = 0;
    for(int i = 0 ; i <n ; i+=2){
        ga += v[i];
        c++;
    }
    if (ga %c != 0) {
        cout << "NO"<<ln;    
        return;
    }
    int owo1 = ga/c;
    ga = 0;
    c = 0;
    for(int i = 1 ; i <n ; i+=2){
        ga += v[i];
        c++;
    }
    if (ga %c != 0) {
        cout << "NO"<<ln;    
        return;
    }
    int owo2 = ga/c;
    cout << (owo1 == owo2 ? "YES" : "NO") <<ln;
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
