#include<bits/stdc++.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define P(x) printf("%d",x)
#define fl(i , a, b) for(i = a; i<b; i++)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define MAX 1000000010
#define ll long long
#define mp make_pair
#define pb push_back
typedef pair<int,int> pp;
typedef pair<ll,ll> ppl;
int f[2][2] = {{1,1},{1,0}};
int tmp[2][2] = {{1,1} , {1,0}};
void multiply(int f[2][2] , int f1[2][2])
{
	int x = f[0][0]*f1[0][0] + f[0][1]*f1[1][0];
	int y = f[0][0]*f1[0][1] + f[0][1]*f1[1][1] ; 
	int w = f[1][0]*f1[0][0] + f[1][1]*f1[1][0] ;
	int z = f[1][0]*f1[0][1] + f[1][1]*f1[1][1];
	f[0][0] = x; f[0][1] = y; f[1][0] = w; f[1][1] = z;
	return ;
}
void power(int x)
{
	if(x==0 || x==1)
		return ;
	power(x/2);
	multiply(f , f);
	if(x%2!=0)
		multiply( f , tmp);
}
int fib(int n)
{
	if(n==0) return 0;
	power(n-1);
	return f[0][0];
}
int main()
{
	int n ; 
	cin>>n;
	cout<<fib(n);
	return 0;
}
