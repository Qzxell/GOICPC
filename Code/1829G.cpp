#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

const int n = 1e6 + 2;
vector<int> ni(n);
vector<int> pa_d(n,0);
vector<int> pa_i(n,0);
vector<ll> dp(n,0);
vector<int> vis(n,0);
void init(){
        for(int i = 1,au = 1 ; i < n;au++){
                int in = i;
                for(int j = i;i < j+au;i++){
                        if(i < n)ni[i] = au;
                        if(i+au < n)pa_d[i+au] = i;
                        if(i+au+1 < n)pa_i[i+au+1] = i;
                }
        }
}

ll rec(int nod){
        if(vis[nod])return dp[nod];
        if(nod <= 0)return 0;
        vis[nod] = 1;
        return dp[nod] = nod*1ll*nod + rec(pa_i[nod]) + rec(pa_d[nod]) - rec(pa_d[pa_i[nod]]);
}

void so(){
        int x;
        cin >> x;
        cout << rec(x) << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        init();
        //return 0;
        while(tt--)so();
        return 0;
}
