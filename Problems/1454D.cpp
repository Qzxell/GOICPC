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


void so(int test){
    ll n;
    cin >> n;
    int sq = sqrt(n);
    map<ll,int> m;
    for(int i = 2 ; i <= sq; i++){
        int c = 0 ;
        while(n % i == 0) {
            c++;
            n/=i;
        }
        if(c) m[i] = c;
        c = 0;
    }
    if(n > 1)m[n]++;
    int le = 0;
    for(auto x : m) le = max(le,x.se); 

    vector<ll> ans(le+1,1);
    for(auto x : m) {
        ans[le - x.se + 1] *= x.fi;
    }

    cout << le << ln;
    for(int i = 1; i <= le;i++){
        ans[i] = ans[i]*1ll*ans[i-1];
        cout << ans[i] << ' ';
    }
    cout << ln;
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
