#include "pch.h"
#include "PrimeNumberComputer.h"

#include "CppUnitTest.h"
#include <map>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using PrimeNumberComputer::UintPrime;


TEST_CLASS(PrimeNumberComputerTest)
{
public:

	TEST_METHOD(TestInvalidInputNegative);
	TEST_METHOD(TestInvalidInputTooLarge);
	TEST_METHOD(TestValidInputZero);
	TEST_METHOD(TestValidInputSmall1);
	TEST_METHOD(TestValidInputSmall2);
	TEST_METHOD(TestValidInputSmall3);
	TEST_METHOD(TestValidInputLarge1);
	TEST_METHOD(TestValidInputLarge2);
	TEST_METHOD(TestValidInputLarge3);
	TEST_METHOD(TestValidInputLarge4);
	TEST_METHOD(TestValidInputLarge5);
};


void PrimeNumberComputerTest::TestInvalidInputNegative()
{
	// Define invalid input.
	// Note: signed int will be converted to uint, and is expected to be larger
	// than the largest possible value (MAX_N)
	constexpr int_fast8_t n = -1;

	Assert::IsTrue(static_cast<UintPrime>(n) > PrimeNumberComputer::MAX_N);

	// Run the targeted function and notice if it failed.
	bool isFailed = false;
	try
	{
		PrimeNumberComputer::ComputePrimeNumbers(n);
	}
	catch (const std::invalid_argument&)
	{
		isFailed = true;
	}

	Assert::IsTrue(isFailed);
}


void PrimeNumberComputerTest::TestInvalidInputTooLarge()
{
	// Define invalid input.
	constexpr UintPrime n = PrimeNumberComputer::MAX_N + 1;

	// Run the targeted function and notice if it failed.
	bool isFailed = false;
	try
	{
		PrimeNumberComputer::ComputePrimeNumbers(n);
	}
	catch (const std::invalid_argument&)
	{
		isFailed = true;
	}

	Assert::IsTrue(isFailed);
}
void PrimeNumberComputerTest::TestValidInputZero()
{
	// Define input and expected output.
	constexpr UintPrime n = 0;
	const vector<UintPrime> expectedOutput = {};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	Assert::IsTrue(expectedOutput == actualOutput);
}

void PrimeNumberComputerTest::TestValidInputSmall1()
{
	// Define input and expected output.
	constexpr UintPrime n = 1;
	const vector<UintPrime> expectedOutput = {2};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	Assert::IsTrue(expectedOutput == actualOutput);
}

void PrimeNumberComputerTest::TestValidInputSmall2()
{
	// Define input and expected output.
	constexpr UintPrime n = 5;
	const vector<UintPrime> expectedOutput = {2, 3, 5, 7, 11};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	Assert::IsTrue(expectedOutput == actualOutput);
}

void PrimeNumberComputerTest::TestValidInputSmall3()
{
	// Define input and expected output.
	constexpr UintPrime n = 10;
	const vector<UintPrime> expectedOutput = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	Assert::IsTrue(expectedOutput == actualOutput);
}

void PrimeNumberComputerTest::TestValidInputLarge1()
{
	// Define input and expected output.
	// Note: Since a lot of values are expected, sample the results with some
	// defined pairs of index (+1) and corresponding prime number.
	// See: https://primes.utm.edu/nthprime/index.php#nth
	constexpr UintPrime n = 1'000;
	const std::map<UintPrime, UintPrime> expectedOutput = {
		{1, 2},
		{2, 3},
		{10, 29},
		{100, 541},
		{500, 3'571},
		{1'000, 7'919},
	};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	for (const auto &entry : expectedOutput)
	{
		Assert::AreEqual(entry.second, actualOutput[entry.first - 1]);
	}
}

void PrimeNumberComputerTest::TestValidInputLarge2()
{
	// Define input and expected output.
	constexpr UintPrime n = 10'000;
	const std::map<UintPrime, UintPrime> expectedOutput = {
		{100, 541},
		{1'000, 7'919},
		{2'000, 17'389},
		{3'000, 27'449},
		{5'000, 48'611},
		{10'000, 104'729},
	};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	for (const auto& entry : expectedOutput)
	{
		Assert::AreEqual(entry.second, actualOutput[entry.first - 1]);
	}
}

void PrimeNumberComputerTest::TestValidInputLarge3()
{
	// Define input and expected output.
	constexpr UintPrime n = 100'000;
	const std::map<UintPrime, UintPrime> expectedOutput = {
		{100, 541},
		{1'000, 7'919},
		{10'000, 104'729},
		{20'000, 224'737},
		{30'000, 350'377},
		{50'000, 611'953},
		{100'000, 1'299'709},
	};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	for (const auto& entry : expectedOutput)
	{
		Assert::AreEqual(entry.second, actualOutput[entry.first - 1]);
	}
}

void PrimeNumberComputerTest::TestValidInputLarge4()
{
	// Define input and expected output.
	constexpr UintPrime n = 1'000'000;
	const std::map<UintPrime, UintPrime> expectedOutput = {
		{100, 541},
		{1'000, 7'919},
		{10'000, 10'4729},
		{100'000, 1'299'709},
		{200'000, 2'750'159},
		{300'000, 4'256'233},
		{500'000, 7'368'787},
		{1'000'000, 15'485'863},
	};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	for (const auto& entry : expectedOutput)
	{
		Assert::AreEqual(entry.second, actualOutput[entry.first - 1]);
	}
}


void PrimeNumberComputerTest::TestValidInputLarge5()
{
	// Define input and expected output.
	constexpr UintPrime n = 10'000'000;
	const std::map<UintPrime, UintPrime> expectedOutput = {
		{100, 541},
		{1'000, 7'919},
		{10'000, 104'729},
		{100'000, 1'299'709},
		{1'000'000, 15'485'863},
		{2'000'000, 32'452'843},
		{3'000'000, 49'979'687},
		{5'000'000, 86'028'121},
		{10'000'000, 179'424'673},
	};

	// Run the targeted function.
	const auto actualOutput = PrimeNumberComputer::ComputePrimeNumbers(n);

	// Check the results.
	Assert::IsTrue(n == actualOutput.size());
	for (const auto& entry : expectedOutput)
	{
		Assert::AreEqual(entry.second, actualOutput[entry.first - 1]);
	}
}
