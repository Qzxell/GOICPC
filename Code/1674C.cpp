#include<bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    string s,t;
    cin >> s >> t;
    int le = (int)t.size();
    bool a = 0;
    for (int i = 0; i < le; ++i) {
        if (t[i] == 'a') {
            a = 1;
        } 
    }
    if (a and le > 1) {
        cout << -1 << ln; 
        return;
    }
    if (t == "a") {
        cout << 1 << ln;
        return;
    }
    int k = (int)s.size();
    cout << (1ll << k) << ln;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}

