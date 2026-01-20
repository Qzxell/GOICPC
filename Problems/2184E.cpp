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
        int n;
        cin >> n;
        int p[n],dif[n];
        vi ind(n+1,-1);
        vl ans(n+1,0);
        vi pre_ind(n+1,n-1);
        vi suf_ind(n+1,-1);
        forn(i,n)cin >> p[i];
        stack<int> st;
        forn(i,n-1)
                dif[i] = abs(p[i+1] - p[i]);
        forn(i,n-1){
                while(!st.empty() and dif[st.top()] > dif[i]){
                        int tp = st.top();
                        pre_ind[tp] = i ;
                        st.pop();
                }
                st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = n - 2 ; i >= 0 ; i--){
                while(!st.empty() and dif[st.top()] >= dif[i]){
                        int tp = st.top();
                        suf_ind[tp] = i ;
                        st.pop();
                }
                st.push(i);
        }
        forn(i,n-1){
                ll dis = (pre_ind[i]-i) *1ll*( i - suf_ind[i]) ;
                ans[dif[i]] += dis;
        }
        for(int i = n-2 ; i >= 0;i--)
                ans[i] += ans[i+1];
        forsn(i,1,n){
                cout << ans[i] << ' ';
        }

        cout << '\n';
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


