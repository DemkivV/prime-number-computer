#pragma once
#include <vector>

using std::vector;


namespace PrimeNumberComputer {

	// Limit for n, so the corresponding prime number still fits into the
	// supported data type.
	// Note: MAX_N has to be manually evaluated when modifying uint_prime.
	typedef uint_fast64_t UintPrime;

	// Defines maximum allowed value for n in ComputePrimeNumbers().
	// Note: Value is currently approximated, since it's computationally
	// extremely intensive to compute so many prime numbers.
	// Web tools like https://primes.utm.edu/nthprime/index.php#nth
	// can be helpful, but are limited, in that case to MAX_N = 10^12.
	// For various large values, the indices corresponding to a certain prime
	// number are of the same order of magnitude or 1 lower. If checking for
	// the maximum accessible prime number on the previously mentioned website,
	// this assumption is confirmed. To be more conservative, another 2 orders
	// of magnitude are subtracted, for a total of 3.
	constexpr UintPrime MAX_N = std::numeric_limits<UintPrime>::max() / 1000;

	/**
	 * Computes a given amount of prime numbers, starting with 2.
	 *
	 * Requirements: 0 <= n <= MAX_N
	 * n is limited at the upper end because that's the highest prime number
	 * fitting into the supported data type.
	 *
	 * Runtime complexity: O(n^2)
	 *  Memory complexity: O(n)
	 */
	vector<UintPrime> ComputePrimeNumbers(UintPrime n);

}
