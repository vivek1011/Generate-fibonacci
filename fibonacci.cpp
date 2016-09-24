#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define	fl(i,a,b) for(int i=a;i<(int)b;i++)
#define MOD 1000000007
ll tmp[2][2] = {{1,1},{1,0}};
void multiply(ll f[2][2] , ll tmp[2][2])
{
	int i , j , k ; 
	ll C[2][2] = {{0,0} , {0,0}}; 
	fl(i,0,2){
		fl(j,0,2){
			fl(k, 0, 2){
				C[i][j] = (C[i][j] + (f[i][k] * tmp[k][j]) % MOD) % MOD ; 
			}
		}	
	}
	fl(i,0,2){
		fl(j,0,2) f[i][j] = C[i][j]; 
	}
}

void mat(ll x , ll f[2][2])
{
	if(x == 0 || x==1) return; 

	mat(x/2 , f); 
	multiply(f,f); 

	if(x%2!=0)
		multiply(f,tmp) ;
}		

ll getfib(ll n)
{
	if(n == 2 || n==1)
		return 1; 

	ll f[2][2] = {{1,1} , {1,0}};

	mat(n-1 , f); 	

	return f[0][0]; 
}	
int main()
{
	int n; 
	cin >> n ;
	cout << getfib(n) << endl;
}
