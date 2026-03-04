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


int n;
const int ga = 1e6 + 1;
int memo[ga];

int fu(int num){
    if (memo[num] != 0) return memo[num] ;
    if (num == 0) {
        return 0; 
    }
    string s = to_string(num) ;
    int ret = 1e9;
    f(i,0,sz(s)){
        string ss ;
        ss += s[i];
        int di = stoi(ss);
        if (di and num >= di) {
            ret = min(ret , fu(num - di )+ 1) ;
        }  
    }
    return memo[num] = ret;
}

void so(int test){
    cin >> n;
    cout << fu(n);
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
