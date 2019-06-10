#include <iostream>
using namespace std;

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;cin>>n;
	    int p[n+1];
	    p[0] = 0;
	    for(int i = 1 ;  i <= n ; i ++ )
	        cin>>p[i];
	    long int dp[n+1];
	    for(int i = 0 ; i < n+1 ; i ++ )
	        dp[i] = -1;
	    dp[0] = 0;
	   for(int i = 1 ; i <= n ; i ++ ){
	       long int m = -1;
	       for(int j = 1 ; j <= i ; j++){
	           m = max(m, p[j] + dp[i-j]);//main dp step for size k = best possible cutting place for left most cup cuts to the right handled by dp
	       }
	       dp[i] = m;
	   }
	   cout<<dp[n]<<'\n';    
	        
	}
}
