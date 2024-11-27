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
    f(i,0,sz(s)-1){
        if (s[i] == s[i+1]) {
            cout << s[i]<< s[i+1]<<ln;
            return;
        }
    }
    f(i,0,sz(s)-2){
        if (s[i] != s[i+2]) {
            cout << s[i]<< s[i+1] << s[i+2]<<ln;
            return;
        }
    }

    cout << -1 << ln;
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
