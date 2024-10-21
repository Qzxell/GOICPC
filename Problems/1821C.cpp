#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb emplace_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(int test){
    string s;
    cin >> s;

    int le = sz(s);
    auto fu = [&](int x){
        int re = 0;
        while(x){
            re++;
            x >>= 1;
        }
        return re;
    };
    int ans = 1e9;
    for(int i = 0 ; i < 27 ; i++){
        int pos = -1;
        int pots = 0;
        int c = 0;
        for(int j = 0 ; j < le ; j++){
            if(s[j] == 'a' + i){
                c++;
                pots = max(fu(j-pos-1),pots);
                pos = j;
            }
        }
        if (pos != le-1) {
            pots = max(fu(le-pos-1),pots);
        }
        if (c) {
            ans = min(ans, pots)    ;
        }
    }
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
