# O(1) Fib

The fibonacci sequence can be made in an O(1) algorithm by exploiting the fact that n/n-1 revolves around the golden ratio.

* fib(60) is: 1548008755920 [wolfram alpha link](https://www.wolframalpha.com/input/?i=fibonacci+60)

# Source

The main algorithm is in [fib.hpp](./fib.hpp)
```cpp
#include <cmath>

const double SQRT5 = sqrt(5.0);
const double PHI = (SQRT5+1.0) * 0.5;
const double ONE_MINUS_PHI = 1-PHI;

long long fib(int n) {
	double f = (pow(PHI, n) - pow(ONE_MINUS_PHI, n)) / SQRT5;
	return f;
}
```

# Benchmark

* fib(2) is just as fast as fib(60)

```
./fibbench
2019-12-10 01:27:26
Running ./fibbench
Run on (16 X 2400 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 256 KiB (x8)
  L3 Unified 16384 KiB (x1)
Load Average: 1.74, 1.59, 1.73
***WARNING*** Library was built as DEBUG. Timings may be affected.
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Fib/1         28.0 ns         28.0 ns     24638431
BM_Fib/2         46.9 ns         46.9 ns     13153691
BM_Fib/3         47.0 ns         47.0 ns     12850167
BM_Fib/4         46.8 ns         46.8 ns     13770040
BM_Fib/10        47.2 ns         47.2 ns     12950253
BM_Fib/20        47.0 ns         47.0 ns     13379205
BM_Fib/40        47.3 ns         47.3 ns     13698094
BM_Fib/60        47.1 ns         47.1 ns     10767740
BM_Fib/90        47.6 ns         47.6 ns     12798947
BM_Fib_BigO      44.99 (1)       44.98 (1)  
BM_Fib_RMS         13 %            13 %
```

# Building

Using CMake
```
git submodule update --init --recursive
mkdir build && cd build
cmake ../
make -j$(sysctl -n hw.ncpu)
```

Using Clang
```
make
```