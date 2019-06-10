#include <iostream>
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
	    int l1;
	    int l2;
	    cin>>l1>>l2;
	    string s1, s2;
	    cin>>s1>>s2;
	    long int dp[l1+1][l2+1];
	    for(int i= 0 ; i< l1+1 ; i++){
	        dp[i][0] = 0;
	    }
	    for(int i= 0 ; i< l2+1 ; i++){
	        dp[0][i] = 0;
	    }
	    for(int i=1;i<=l1;i++){
	        for(int j = 1 ; j <= l2 ; j++){
	            if(s1[i-1] == s2[j-1])
	                dp[i][j] = dp[i-1][j-1] + 1;//if last element same last element of lcs must be same as that of them so i-1 j-1 +1
	            else{
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);//if last element different last element of lcs cannot be same as that of both
                                                          //sequences so we can eliminate last element of each sequence and consider both cases
	            }
	        }
	    }
	    cout<<dp[l1][l2]<<'\n';
	  
	}
	return 0;
}
