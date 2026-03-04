#include<bits/stdc++.h>

using namespace std;

void so(){
        cout << "==============\n";
        int n,x;
        cin >> n;
        vector<vector<int>> G(n+1);
        for(int i = 1; i <= n ; i++){
                cin >> x;
                G[i].push_back(x);
                G[x].push_back(i);
        }
        queue<pair<int,int>> qu;
        vector<bool> color(n+1,0);
        auto bfs = [&](int nod)->bool{
                color[nod] = 1;
                qu.push({nod,-1});
                bool cic = 0;
                while(!qu.empty()){
                        auto [fr,p] = qu.front();qu.pop();
                        color[fr] = 1;
                        for(auto x : G[fr])if(x != p){
                                if(color[x] == 0){
                                        qu.push({x,fr});
                                }else{
                                        cic = 1;
                                }
                        }
                }
                return cic;
        };
        int mi = 0,li = 0;
        for(int i = 1; i <= n ;i++){
                if(color[i] ==0){
                        if(bfs(i)){
                                mi++;
                        }else{
                                li++;
                        }
                }
        }
        cout << mi + (li > 0)<< ' ' << li+ mi<< '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--){
                so();
        }

        return 0;
}
