# C++ Algorithm: Prime Number Computer

## Purpose of Repository
* `C++` algorithm for the computation of prime numbers, including unit tests.
* Suitable as a code sample for `C++` code.

## Setup
* *IDE:* `Visual Studio` (2019)
* *Project template:* `Native Unit Test Project`
  * To simplify the project structure, the prime number algorithm is embedded directly in the same test project.
* *Settings:* `Default`
* *Naming style:* `Microsoft`

## Benchmark
The test suite should typically finish in <27 seconds on a Ryzen 5900x in a `Release x64` build.

## Notes
Especially the latter tests with the naming scheme `TestValidInputLarge*` run noticeably slow in a `Debug` or `x86` build, since they're computationally intensive. Thus, recommended running them in a `Release x64` build.
