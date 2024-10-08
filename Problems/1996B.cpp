#include<bits/stdc++.h>
using namespace std;

void so(){
    int n,k;cin >> n >> k;
    vector<string> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i]; 
    }

    vector<string> ans(n/k,string(n/k,' '));

    for (int i = 0; i < n; i+=k) {
        for (int j = 0; j < n; j += k) {

            if (v[i][j] == '1')  {
                ans[i/k][j/k] = '1'; 
            }else ans[i/k][j/k]= '0';
        } 
    }
    for(auto s : ans)cout << s << '\n';
}
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}
