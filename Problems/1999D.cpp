#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    string s,t,temp;
    cin >> s >> t;
    int ls  = s.size(), lt = t.size();
    temp = s;
    int cur  = 0;
    for (int i = 0; i < ls; ++i) {
        if (cur < lt and (s[i] == t[cur] or s[i] == '?')) {
            if (s[i] == '?') {
                temp[i] = t[cur];
            }
            cur++;
        } 
    }
    if (cur == lt) {
        for (int i = 0; i < ls; ++i) {
            if (temp[i] == '?') {
                temp[i] = 'a';   
            } 
        } 
        cout << "YES\n";
        cout << temp << ln;
    }else cout << "NO\n";
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

