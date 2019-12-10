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
2019-12-10 02:08:43
Running ./fibbench
Run on (16 X 2400 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x8)
  L1 Instruction 32 KiB (x8)
  L2 Unified 256 KiB (x8)
  L3 Unified 16384 KiB (x1)
Load Average: 2.06, 1.85, 1.77
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Fib/1         16.7 ns         16.7 ns     40138765
BM_Fib/2         33.5 ns         33.5 ns     21219130
BM_Fib/3         32.3 ns         32.3 ns     21472985
BM_Fib/4         32.4 ns         32.4 ns     20765844
BM_Fib/10        32.3 ns         32.3 ns     21476082
BM_Fib/20        34.6 ns         34.6 ns     21289279
BM_Fib/40        32.2 ns         32.2 ns     21380705
BM_Fib/60        32.5 ns         32.5 ns     20973846
BM_Fib/90        32.1 ns         32.1 ns     21269355
BM_Fib_BigO      30.97 (1)       30.96 (1)  
BM_Fib_RMS         16 %            16 %    
```

# Building

Using CMake
```
git submodule update --init --recursive
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ../
make -j$(sysctl -n hw.ncpu)
```

Using Clang
```
make
```