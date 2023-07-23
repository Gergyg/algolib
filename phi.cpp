int phi(int n) {
    vector<pair<int, int>>divisors = factorize(n); 
    //pairs {prime number, exponent}
	
    int ans = 1;
    for(auto [prime, exp] : divisors) {
	int power = 1;
        for (int i = 1; i<exp; i++){
            power *= prime;
	}	
	ans *= (power * prime - power); // (p^exp - p^{exp-1})
    }
    return ans;
}

vector<int> phi_from_1_to_n(int n) {
    vector<int>phi(n + 1, 1), sieve(n + 1, -1);
    
    for(int i = 2; i <= n; i++) {
        if(sieve[i] == -1) {
            sieve[i] = i;
            for(long long j = 1ll * i * i; j <= n; j += i)
                sieve[j] = i;
        }
    }
    
    for(int i = 2; i <= n; i++) {
        int p = sieve[i], j = i;
        while(j % p == 0) {
        	phi[i] *= p;
        	j /= p;
       	}
        //j is now equal to i / p^k
        phi[i] = (phi[i] / p) * (p - 1) * phi[j];
    }
    return phi;
}