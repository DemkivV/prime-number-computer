#pragma once
#include <vector>

using std::vector;


namespace PrimeNumberComputer {

	/**
	 * Defines the data type to save prime numbers with. Since the parameter n
	 * is only a few orders of magnitude smaller, it uses the same data type.
	 * Can be changed centrally here and automatically adjusts the upper limit
	 * limit for n (MAX_N) and the value range for prime numbers.
	 */
	typedef uint_fast64_t UintPrime;

	/**
	 * Defines the maximum allowed value for the parameter n. The main objective
	 * of this limit is not to exhaust the range of the data type UintPrime,
	 * otherwise fewer prime numbers would be delivered than requested.
	 *
	 * Note: Value is currently approximated, since it's computationally
	 * extremely intensive to compute as many prime numbers.
	 * Web tools like https://primes.utm.edu/nthprime/index.php#nth
	 * can be helpful, but are limited, in that case to MAX_N = 10^12.
	 * For various checked (large) values in that range, the indices
	 * corresponding to a certain prime number are of the same order of
	 * magnitude or 1 lower. Thus, MAX_N should be at least 1 order of magnitude
	 * lower. To be more conservative, another 2 orders of magnitude are
	 * subtracted, for a total of 3.
	 */
	constexpr UintPrime MAX_N = std::numeric_limits<UintPrime>::max() / 1'000;

	/**
	 * Computes a specified amount of prime numbers.
	 *
	 * n: number of prime numbers to be computed.
	 *
	 * Requirements: 0 <= n <= MAX_N
	 *
	 * Runtime complexity: O(n^2)
	 *  Memory complexity: O(n)
	 */
	vector<UintPrime> ComputePrimeNumbers(UintPrime n);

}
