#include <bits/stdc++.h>
using namespace std;
int a[200000][4],tre[200001]={},N;
int lowbit(int x){return x-(x&(x-1));}
void add(int x,int val){for(;x<=N;x+=lowbit(x)){tre[x]+=val;}}
int qsum(int x){int sum=0;for(;x>0;x-=lowbit(x)){sum+=tre[x];}return sum;}
int main(int argc, char** argv) {
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,q,i,j,k,op,l,r;
	for(cin>>T;T>0;T--)
	{
		cin>>n>>q;
		N=n;
		for(i=0;i<n;i++)
		{
			cin>>a[i][0];
			for(j=1;j<4;j++)
			{
				a[i][j]=0;
				for(k=a[i][j-1];k>0;k/=10)a[i][j]+=k%10;
			}
		}
		for(i=0;i<q;i++)
		{
			cin>>op;
			if(op==1)
			{
				cin>>l>>r;
				add(l,1);
				if(r<n)add(r+1,-1);
			}
			else
			{
				cin>>l;
				cout<<a[l-1][min(qsum(l),3)]<<'\n';
			}
		}
		for(i=1;i<=N;i++)tre[i]=0;
	}
	return 0;
}
