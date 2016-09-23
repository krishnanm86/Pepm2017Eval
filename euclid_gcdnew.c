 mpz_t euclid_gcd(mpz_t a, int b){

	 mpz_t gcd;
	 mpz_init_set_ui(gcd, 0);

	 if (a >= b && b >= 0){
		 if (b == 0)
			 mpz_set(gcd, a);
		 else
		 {
		 	mpz_t mod;
		 	mpz_init(mod);
		 	mpz_mod(mod, a, b);
			mpz_set(gcd, euclid_gcd(b, mod);
		 }
	 }

	 return gcd;
 }
