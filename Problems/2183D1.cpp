#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define sz(v) (v).begin(),(v).end()

void so(int test){
        int n;
        cin >> n;
        vector<vi> T(n);
        vi prof(n+1,0),dis(n+1,-1),son(n+1,0);
        forn(i,n-1){
                int u,v;
                cin >> u >> v;
                u--;v--;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        queue<int> qu;
        qu.push(0);
        dis[0] = 0;
        while(!qu.empty()){
                int fr = qu.front();qu.pop();
                prof[dis[fr]]++;
                int &ga = son[fr];
                for(auto x : T[fr])if(dis[x] == -1){
                        dis[x] = dis[fr] + 1;
                        qu.push(x);
                        ga++;
                }
        }
        cout << max(*max_element(prof.begin(),prof.end()),*max_element(son.begin(),son.end())+1) << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


