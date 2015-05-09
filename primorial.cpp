#include <stdio.h>
#include <gmpxx.h>
#include <vector>
#include <unistd.h>

# Usage: ./bin_name first_n_primorial_numbers_to_compute_and_factor
# Compile with 'g++ primorial.cpp -o bin_name -lgmp --std=c++11'

std::vector<mpz_class> prime_factors(mpz_class n)
{
    mpz_class i = 2;
    std::vector<mpz_class> factors;
    while (i*i < n) {
        if (n % i != 0) {
            i++;
        }
        else {
            n /= i;
            factors.push_back(i);
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main(int argc, char *argv[])
{
    std::vector<mpz_class> array = std::vector<mpz_class>(100);
    mpz_t currentPrime;
    mpz_init_set_ui(currentPrime, 2);
    for (int i = 0; i < 100; i++) {
        mpz_primorial_ui(array[i].get_mpz_t(), mpz_get_ui(currentPrime));
        mpz_nextprime(currentPrime, currentPrime);
        array[i]++;
    }
    
    for (int i = 0; i < atoi(argv[1]); i++) {
        std::vector<mpz_class> factors = prime_factors(array[i]);
        gmp_printf("Prime factors of %Zd:\n", array[i].get_mpz_t());
        for (auto factor : factors) {
            gmp_printf("%Zd\n", factor.get_mpz_t());
        }
    }

    return(0);
}
