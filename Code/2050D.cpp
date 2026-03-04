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
    int le = sz(s);
    string ans;
    for(int i = 0 ; i < le ; i++){
        int ma = s[i] - '0';
        int ind = i;
        for(int j = i +1 ; j < min(sz(s),i+10) ; j++){
            if(s[j]-'0' - (j-i) > ma ){
                ma = s[j] - '0' - (j-i);
                ind = j;
            }
        }
        char aux = ma + '0';
        for(int k = i ; k <= ind ; k++){
            swap(s[k],aux); 
        }
    }
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
