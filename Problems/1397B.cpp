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
ll fp(ll b,ll e){
    ll re = 1;
    while(e>0){
        if(e&1) re *= b;
        b = b*b;
        e /= 2;
    }
    return re;

}
void so(int test){
    int n;
    cin >> n;
    vi v(n);
    ll ans = 0;
    f(i,0,n){
        cin >> v[i];
        ans += v[i]-1;
    }
    sort(all(v));
    bool nor = 0;
    int b = 1;
    int owo = 1e5;
    f(i,2,owo){
        ll sur = 0;
        if(nor)break;
        f(j,0,n){
            sur += abs(fp(i,j)-v[j]);
            if(sur > ans){
                nor = 1;
                break;
            }
        }
        b= i;
        ans = min(ans,sur);
    }
    cout << ans <<ln;

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
