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
    string s;
    cin >> s;
    vi freq(27,0);
    f(i , 0 , sz(s)){
        freq[s[i]-'a']++;
    }
    ll ans = *max_element(all(freq));
    ll v[27][27];
    memset(v,0,sizeof(v));
    f(i,0,sz(s)){
        freq[s[i]-'a'] = max(freq[s[i]-'a'] - 1 , 0);
        for(int j = 0 ; j < 27 ; j++){
            v[s[i]-'a'][j] += freq[j];
        }
    }
    f(i,0,27){
        f(j,0,27){
            ans = max(ans,v[i][j]);
        }
    }
    cout << ans;

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
