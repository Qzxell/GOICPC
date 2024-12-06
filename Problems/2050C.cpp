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
    vi fre(4,0);
    int su = 0;
    f(i,0,sz(s)){
        su += s[i]-'0';
        su %= 9;
    }
    f(i,0,sz(s))if(s[i] == '2' or s[i] == '3')fre[s[i]-'0']++;

    int x = fre[2];
    int y = fre[3];

    f(i,0,x+1){
        f(j,0,y+1){
            if((su + 2*i - 3*j)%9 == 0){
                cout << "YES" << ln;
                return;
            }
        }
    }
                cout << "NO" << ln;

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
