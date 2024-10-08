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
    int n;
    cin >> n;
    stack<char> st;
    auto fu = [&](string s){
        ii ret = {0,0};
        int len = s.size();
        for (int i = 0 ; i < len ; i++){
            if (!st.empty() and st.top() == '(' and s[i] == ')') {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            if (st.top() == '(') {
                ret.se += 1; 
            }else ret.fi += 1;
            st.pop();
        }
        return ret;
    };
    int cont = 0;
    vii v;
    int max = 5e5 + 2;

    vi lef(max,0);
    vi rig(max,0);

    for (int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        ii cur = fu(s);
        //cout << cur.fi << ' ' << cur.se << " ,";
        if (cur.fi == 0 and cur.se == 0) {
            cont ++;
            continue;
        }
        if (cur.fi > 0 and cur.se > 0) {
            continue;
        }
        if (cur.fi) {
            lef[cur.fi] ++;
        }
        if (cur.se) {
            rig[cur.se] ++;
        }
    }
    int ans = cont/2;
    for (int i = 0 ; i < max ; i++){
        ans += min(lef[i],rig[i]);     
    }
    cout << ans << ln;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--){
        so();
    }
    return 0;
}

