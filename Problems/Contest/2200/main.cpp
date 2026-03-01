#include<bits/stdc++.h>
#define INI cin.tie(0)->sync_with_stdio(0);cout.tie(0);
#define int ll
#define readi(a) int a;cin>>a;
#define query readi(n) while(n--)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define endl '\n'
#define ll long long 
using namespace std;
const ll inf=numeric_limits<ll>::max();
int M[25];
vector<int>y;
int f(int k,int c,vector<int>v)
{
    if(v.empty())return c;
    if(k==20)return inf;
    if(k%2)
    {
        int r=-1;
        for(int i:v)
        {
            int l=(-y[i]%M[k+1]+M[k+1])%M[k+1];
            if(r==-1)r=l;
            else if(r!=l)return inf;
        }
        return f(k+1,r,v);
    }
    else
    {
        int m=inf;
        vector<int>q(v.size());
        fore(j,0,v.size()-1)q[j]=(-y[v[j]]%M[k+1]+M[k+1])%M[k+1];
        fore(d,0,6)
        {
            int w=c+d*M[k];
            vector<int>u;
            fore(j,0,v.size()-1)if(q[j]==w)u.push_back(v[j]);
            m=min(m,f(k+1,w,u));
        }
        return m;
    }
}
void solve()
{
    readi(s);
    vector<int>a(s);
    bool b=1;
    fore(i,0,s-1)
    {
        cin>>a[i];
        if(i>0&&a[i]%6!=a[0]%6)b=0;
    }
    if(!b)
    {
        cout<<-1<<endl;
        return;
    }
    int x=(6-a[0]%6)%6;
    y.resize(s);
    vector<int>v(s);
    fore(i,0,s-1)
    {
        y[i]=(a[i]+x)/6;
        v[i]=i;
    }
    int t=f(0,0,v);
    if(t==inf)cout<<-1<<endl;
    else cout<<x+6*t<<endl;
}
int main()
{
    INI M[0]=1;
    fore(i,1,20)M[i]=M[i-1]*(i%2?7:6);
    query{solve();}
    return 0;
}

