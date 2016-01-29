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
void power(int x , int f[2][2])
{
	if(x==0 || x==1)
		return ;
	power(x/2 ,f);
	multiply(f , f);
	if(x%2!=0)
		multiply( f , tmp);
}
int main()
{
	int n ; 
	cin>>n;
	int f[2][2] = {{1,1},{1,0}};
	power(n , f);
	return 0;
}
