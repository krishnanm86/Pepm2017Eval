/* multiply: An interesting method to multiply integers. Again, not entirely fast. */
mpz_t multiply(mpz_t x , mpz_t y){


	mpz_t product;
	mpz_init_set_ui(product, 0);

	if (mpz_cmp_ui(x, 0) >= 0 && mpz_cmp_ui(y, 0) > 0){
		mpz_t y2;
		mpz_init(y2);
		mpz_div_ui(y2, y, 2);
		mpz_t z = multiply(x, y2);
		mpz_t ymod;
		mpz_init(ymod);
		mpz_mod(ymod, y, 2);
		if (ymod == 0)
			mpz_mul_ui(product, z, 2);
		else
		{
			mpz_t z2;
			mpz_init(z2);
			mpz_mul_ui(z2, z, 2);
			mpz_add(product, x, z2);
		}
	}
	return product;

}
