#include<bits/stdc++.h>

using namespace std;

#define ll long long

void so(){
        int n;
        cin >> n;
        string s ;
        cin >> s;
        vector<int> fre(26,0);
        vector<pair<int,int>> gru;
        vector<vector<int>> abc(26);

        for(int i =0 ; i < n ;i++){
                abc[s[i]-'a'].push_back(i);
                fre[s[i]-'a']++;
        }
        vector<int> dis;
        for(int i =0 ; i < 26 ;i++){
                if(fre[i] == 0){
                        dis.push_back(i);
                        continue;
                }
                gru.push_back({fre[i],i});
        }
        sort(gru.rbegin(),gru.rend());
        ll ans = (1ll<<60);
        int ga = -1;
        for(int i = 1; i <= n ;i++){
                if(n % i)continue;
                int cnt = n/i;
                if(cnt > 26)continue;
                ll pre = 0;
                if(cnt >= gru.size()){
                        for(auto [x,_] : gru){
                                pre += max(x-i,0);
                        }
                }else{
                        for(int j = 0 ;j < cnt;j++){
                                pre += max<ll>(gru[j].first-i,0);
                        }
                        for(int j = cnt;j < (int)(gru.size());j++){
                                pre += gru[j].first;
                        }
                }
                if(pre < ans){
                        ga = i;
                        ans = pre;
                }
        }
        cout << ans << '\n';
        int cnt = n/ga;

        vector<int> fi(26,0);
        int u = 0;
        for(auto [x,ad] : gru){
                if(u == cnt)break;
                fi[ad] = 1;
                u++;
        }
        if(cnt > gru.size()){
                for(int i = 0 ; i < cnt - (int)(gru.size());i++){
                        fi[dis[i]] = 1;
                }
        }

        vector<int> gar;
        for(int i =0 ; i < 26;i++){
                for(int j = (fi[i]? ga : 0); j < abc[i].size();j++){
                        gar.push_back(abc[i][j]);
                }
        }
        string ret = s;
        for(int i =0 ; i < 26;i++){
                if(!fi[i])continue;
                while(abc[i].size() < ga){
                        if(gar.empty())assert(false);
                        int ul = gar.back();gar.pop_back();
                        abc[i].push_back(ul);
                }
        }
        for(int i =0 ; i < 26;i++){
                if(!fi[i])continue;
                for(int j = 0 ; j < ga; j++){
                        ret[abc[i][j]] = (char)('a'+i);
                }
        }
        cout << ret << '\n';

}

int main(){
        int tt;
        cin >> tt;
        while(tt--){
                so();
        }

        return 0;
}
