#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
#define sz(v) ((int)((v).size()))

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> id(n,-1);
        int m=0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') id[i] = m++;
        }
        if (m == 0) {
            cout << "YES\n";
            continue;
        }
        vector<vector<pair<int,int>>> g(m);
        vector<int> val(m,-1), st;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (s[i] != '1') continue;
            bool l= (i - 1>= 0 && s[i - 1] == '0'), r = (i + 1< n && s[i + 1] == '0');
            if (l && r){
                int u = id[i - 1], v = id[i + 1];
                g[u].push_back({v,1});
                g[v].push_back({u,1});
            } 
            else if(l){
                int u = id[i - 1];
                if(val[u] == -1) {
                    val[u] = 0;
                    st.push_back(u);
                }
                else if (val[u] != 0) ok = false;
            } 
            else if (r){
                int v= id[i + 1];
                if(val[v]== -1){
                    val[v] = 1; 
                    st.push_back(v);
                }
                else if(val[v] != 1) ok=false;
            }
        }
        while (ok && !st.empty()){
            int u = st.back(); 
            st.pop_back();
            for (auto &e: g[u]){
                int v= e.first, w = e.second;
                int aux = (val[u] ^ w);
                if(val[v] == -1) { 
                    val[v]= aux; st.push_back(v);
                }
                else if(val[v]!=aux) { 
                    ok = false; 
                    break; 
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (val[i] != -1) continue;
            val[i] = 0; 
            st.push_back(i);
            while (ok && !st.empty()){
                int u = st.back(); 
                st.pop_back();
                for (auto &e: g[u]){
                    int v= e.first, aux = (val[u] ^ e.second);
                    if (val[v] == -1){ 
                        val[v] = aux; 
                        st.push_back(v); 
                    }
                    else if (val[v] != aux){ 
                        ok = false; 
                        break;
                    }
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}

