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
    int le ;cin >> le;
    string s;
    cin >> s;
    int open = 0;
    for(int i = 0 ; i < le;i++){
        if(s[i] == '(') open++;
        if(s[i] == '_' and open){
            s[i] = ')';
        }
        if(s[i] == '_' and open == 0){
            s[i] = '('; open++;
        }

        if(s[i] == ')')open--;
    }
    int con = 0;
    ll ans = 0;
    stack<int> st;
    for(int i = 0 ; i < le ;i++){
        if (s[i] == '(') {
            st.push(i) ;
        }else{
            int wa = st.top();
            ans += i - wa; 
            st.pop();
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
