/*#pragma warning(disable:4996)//disable depriciated warning
#pragma GCC optimize ("Ofast")//may cause floating point error
#pragma comment(linker, "/stack:200000000")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")
These statements help with TLE
*/

#include<bits/stdc++.h>

using namespace std;

#define fo(i,n)   for(int i=0;i<(n); i ++)
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define modul 1000000007

typedef long double ld;
typedef long long int ll;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
typedef vector<ll> vl;

/*ll mpow(ll a, ll n){
	if(n==0)return 1;
	if(n==1)
		return a%modul;
	if(n%2){
		ll q = power(a, n/2);
		q%=modul;
		ll ans = (q*q)%modul;
		return (ans*a)%modul;
	}
	else{
		ll q = power(a, n/2);
		q%=modul;
		return (q*q)%modul;
	}
}*/



ll n;
vl E[500005];
int col[500005];
int altcol[500005];
ll counter = 0;
ll size = 0;
int check = 0;
void dfs(ll u, int flag){
	//cout<<u<<' ';
	altcol[u] = flag;
	col[u] = 1;
	for(auto v : E[u]){
		if(altcol[v] == altcol[u]){
			//cout<<"ERROR "<<u<<" = "<<altcol[u]<<' '<<v<<" = "<<altcol[v]<<'\n';
			check = -1;
		}
		if(col[v] == 0 && v!= u){	
			dfs(v, 1 - flag);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin>>n>>m;
   // cout<<n<<m;
    ll a, b;
    ll e[m][2];
	fo(i, m){
    	cin>>a>>b;
    	e[i][0] = a;
    	e[i][1] = b;
    	E[a].pb(b);
    	E[b].pb(a);
	}
	fo(i, n+1){
		col[i] = 0;altcol[i] = -1;
	}
	dfs(1, 0);
	if(check == -1)
		cout<<"NO"<<'\n';
	else{
		cout<<"YES"<<'\n';
		fo(i, m)
			if(altcol[e[i][0]])
				cout<<"0";
			else
				cout<<"1";
	}	
    /*ll t;
    cin>>t;
    while(t--){
    }
    ll a, b;
	fo(i, n){
    	cin>>a>>b;
    	E[i+1].pb(p);
    	E[p].pb(i+1);
	}
	memset(col, 0, n);
	fo(i, n){
		if(col[i]==0){
  			dfs(i);
   			//counter++;
   			size = 0;
   		}
	}
	*/
}

