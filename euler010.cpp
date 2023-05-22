/*
Name: Brian Cabinian
Description: This script solves project euler problem 10, 
https://projecteuler.net/problem=10
*/

#include <iostream>
#include <vector>

std::vector<bool> sieve_of_erast(int upper_limit);

int main()
{
	std::vector<bool> prime_list;
	int upper_limit = 2000000;
	long long int sum_val = 0;

	prime_list = sieve_of_erast(upper_limit);

	for (int i = 2; i < upper_limit; i++)
	{
		if (prime_list.at(i))
		{
			sum_val += i;
		}
	}

	std::cout << "The sum of all primes less than " << upper_limit << " is "
		<< sum_val;

	return 0;
}

// Signature: Int -> Vector<bool>
// Purpose: returns a vector of bools (essentially a bit array) that represents 
// the list of prime numbers less than the upper limit specified. Except for 
// the 0 and 1 indices of the vector, if the vector is 1 at index i, then i 
// is a prime number.
std::vector<bool> sieve_of_erast(int upper_limit)
{
	std::vector<bool> prime_list(upper_limit, 1);
	double sqrt_upper_limit;

	sqrt_upper_limit = floor(sqrt(upper_limit));

	for (int i = 2; i <= sqrt_upper_limit; i++)
	{
		if (prime_list[i])
		{
			for (int j = i*i; j < upper_limit; j = j + i)
			{
				prime_list[j] = 0;
			}
		}
	}

	return prime_list;
}