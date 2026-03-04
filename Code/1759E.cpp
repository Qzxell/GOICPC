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
    //cout << "test " << test << ':' << ln;
    ll n,h;
    cin >> n >> h;
    vi v(n);
    ll aux = h;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    int ans = 0;
    sort(all(v));
    int astr = 0;
    int i = 0;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 2;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 2;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 3;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    //cout << astr << ln;
    ans = max(ans,astr);
    //
    h = aux;
    astr = 0;
    i = 0;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 2;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 3;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 2;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    //cout << astr << ln;
    ans = max(ans,astr);
    //
    h = aux;
    astr = 0;
    i = 0;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 3;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 2;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    h *= 2;
    while (i < n and h > v[i]){
        h += (v[i]/2);
        astr++;
        i++;
    }
    //cout << astr << ln;
    ans = max(ans,astr);
    //
    cout << ans << ln;

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
