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

int bruh(ll x){
    int c = 0;
    f(i,0,62)if((x>>i)&1){
        c = i;
    }
    return c;
}

void so(int test){
    ll n,num;
    cin >> n >> num;
    vi ans(n,-1);
    int exp = bruh(num);
    ll res = num - (1ll<<exp);
    int tot = n-1;
    int cu = 1;
    int ind_i = 0;
    int ind_f = n-1;
    if(exp == n-1 and res > 0){
        cout << -1 << ln;
        return;
    }
    if(exp > n-1){
        cout << -1 << ln;
        return;
    }
    while(tot >= 0){
        if (exp < tot -1 or ((exp == tot -1) and res == 0)) {
            ans[ind_i] =cu;
            ind_i++;
        }else{
            ans[ind_f]=cu;
            ind_f--;
            num -= (1ll<<(tot-1));
            exp = bruh(num);
            res = (num) - (1ll<<exp);
        }
        cu++;
        tot--;
    }
    //gaaaaaaaaaaaa
    f(i,0,n)cout << ans[i] << ' ';
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
