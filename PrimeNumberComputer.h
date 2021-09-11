#pragma once
#include <vector>

using std::vector;


namespace PrimeNumberComputer {

	/**
	 * Defines the data type to limit both, the parameter n and the range where
	 * prime numbers can be found. Can be changed here centrally and will
	 * automatically adjust the upper limit for n (MAX_N) and the value range
	 * for prime numbers.
	 */
	typedef uint_fast64_t UintPrime;

	/**
	 * Defines the maximum allowed value for n in ComputePrimeNumbers().
	 * Note: Value is currently approximated, since it's computationally
	 * extremely intensive to compute so many prime numbers.
	 * Web tools like https://primes.utm.edu/nthprime/index.php#nth
	 * can be helpful, but are limited, in that case to MAX_N = 10^12.
	 * For various large values, the indices corresponding to a certain prime
	 * number are of the same order of magnitude or 1 lower. If checking for
	 * the maximum accessible prime number on the previously mentioned website,
	 * this assumption is confirmed. To be more conservative, another 2 orders
	 * of magnitude are subtracted, for a total of 3. If it's too conservative,
	 * for a new UintPrime, try to remove 1–2 orders of magnitude.
	 */
	constexpr UintPrime MAX_N = std::numeric_limits<UintPrime>::max() / 1'000;

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
