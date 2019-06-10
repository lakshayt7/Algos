#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int main() {
	int t;//subsequence is obtained if we remove any arbitary number of elements from the sequence
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int A[n], B[n];
	    for(int i = 0; i < n; i++){
	        cin>>A[i];B[i] = A[i];
	    }
	    sort(B, B+n);
	    long int dp[n+1][n+1];//sorting solves the problem for without duplicates
      //CAUTION if duplicates present form vector and remove duplicates
	    for(int i= 0 ; i< n+1 ; i++){
	        dp[i][0] = 0;
	    }
	    for(int i= 0 ; i< n+1 ; i++){
	        dp[0][i] = 0;
	    }
	    for(int i=1;i <= n;i++){
	        for(int j = 1 ; j <= n ; j++){
	            if(A[i-1] == B[j-1])
	                dp[i][j] = dp[i-1][j-1] + 1;//if last element same last element of lcs must be same as that of them so i-1 j-1 +1
	            else{
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);//if last element different last element of lcs cannot be same as that of both
                                                          //sequences so we can eliminate last element of each sequence and consider both cases
	            }
	        }
	    }
	    cout<<dp[n][n]<<'\n';
	  
	}
	return 0;
}
