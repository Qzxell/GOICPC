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
    int n ;cin >> n;
    string s;
    cin >> s;
    int le = sz(s);
    vi v(27,0);
    vi dd(27,0);
    f(i,0,le){
        v[s[i]-'a']++;
        dd[s[i]-'a'] = i;
    }
    vii wasa ;
    f(i,0,27)if(v[i] != 0){
        wasa.pb({v[i],dd[i]}) ;
    }
    sort(all(wasa));
    int len = sz(wasa);
    s[wasa[0].se] = s[wasa[len-1].se];

    cout << s << ln;
    

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
