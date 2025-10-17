#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<int> leder(N,0);
vector<int> color(N,0);// 0-
vector<int> comp(N,0);// cuantos negros hay, respector al leder

int pare(int nod){
        if(leder[nod] == nod)return nod;
        return leder[nod] = pare(leder[nod]);
}
void so(){
        int n,q;
        cin >> n >> q;
        for(int i = 1; i <= n ; i++)leder[i] = i;
        for(int i = 0; i < q ; i++){
                int op;
                int u,v;
                cin >> op;
                if(op == 1){
                        cin >> u >> v;
                        int pa1 = pare(u);
                        int pa2 = pare(v);
                        if(pa1 == pa2)continue;
                        leder[pa2] = pa1;
                        comp[pa1] += comp[pa2];
                        continue;
                }
                if(op == 2){
                        cin >> u;
                        int pa1 = pare(u);
                        if(color[u] == 1){
                                comp[pa1]--;
                        }else{
                                comp[pa1]++;
                        }
                        color[u] ^= 1;
                        continue;
                }
                cin >> v;
                int pa1 = pare(v);
                cout << (comp[pa1] > 0 ? "Yes" : "No") << '\n';
        }
}

int main(){
        so();
        return 0;
}
