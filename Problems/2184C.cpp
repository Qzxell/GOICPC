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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
        int n,k;
        cin >>n >> k;
        set<int> s;
        s.insert(n);
        int op =1;
        if(n == k){
                cout<< 0 << '\n';
                return;
        }
        while(true){
                set<int> ga;
                for(auto x : s){
                        if(x/2 == k or (x+1)/2 == k){
                                cout << op << '\n';
                                return;
                        }
                        ga.insert(x/2);
                        ga.insert((x+1)/2);
                }
                swap(ga,s);
                op++;
                if(op > 40)break;
        }
        cout << -1 << '\n';
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


