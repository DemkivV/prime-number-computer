#include "pch.h"
#include "PrimeNumberComputer.h"

#include <stdexcept>
#include <string>

using PrimeNumberComputer::UintPrime;


vector<UintPrime> PrimeNumberComputer::Compute(const UintPrime n)
{
	// Check for valid input parameters.
	if (n > MAX_N)
	{
		throw std::invalid_argument("Argument 'n' is too large. n must be"
			" positive and <= " + std::to_string(MAX_N)
			+ ", but was " + std::to_string(n));
	}
	// Early out for empty request.
	if (n < 1)
	{
		return {};
	}

	vector<UintPrime> results;
	// Reserve the required amount of memory, so, in case of issues, it better
	// fails directly than during/after computations.
	results.reserve(n);
	// Define initial and only even prime number, so only odd numbers have to be
	// parsed.
	results.push_back(2);

	// Parse through all odd numbers and check for divisibility with previously
	// found prime numbers.
	bool isDivisible = false;
	for (UintPrime currentNumber = 3; results.size() < n; currentNumber += 2)
	{
		// Check if currentNumber is a prime number.
		// Skip the first prime number (2), since only odd numbers are checked.
		// Check only against prime numbers, since this is sufficient.
		for (auto it = ++results.begin(); it != results.end(); ++it)
		{
			const auto& currentPrimeNumber = *it;
			// Quit if checked prime number is larger than square root.
			// See: https://stackoverflow.com/a/5811176
			if (currentPrimeNumber * currentPrimeNumber > currentNumber)
			{
				break;
			}

			// Check if current number is divisible by this prime number.
			if (currentNumber % currentPrimeNumber == 0)
			{
				isDivisible = true;
				break;
			}
		}
		if (!isDivisible)
		{
			results.emplace_back(currentNumber);
		}
		else
		{
			isDivisible = false;
		}

		// Quit if currentNumber approaches the limits of supported data type.
		if (currentNumber >= std::numeric_limits<UintPrime>::max() - 2)
		{
			break;
		}
	}

	return results;
}
