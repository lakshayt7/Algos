ll n = s.length();
    ll z[n];
    ll lf = 0, rt = 0;
    z[0] = 0;
	for(ll i = 1; i < n ; i++){
		if(i > rt){
			lf = rt = i ;
			while(rt<n && s[rt - lf] == s[rt])
				rt++;
			z[i] = rt - lf;rt--;
		}
		else{
			ll k = i - lf;
			if(z[k] < rt-i+1)
				z[i] = z[k];
			else{
				lf = rt =i;
				while(rt<n && s[rt-lf] == s[rt])
					rt++;
				z[i] = rt - lf;rt--;
			}	
		}
	} 
