// Copyright (C) 2019 Robert A. Wallis, All Rights Reserved

#pragma once

#include <cmath>

const double SQRT5 = sqrt(5.0);
const double PHI = (SQRT5+1.0) * 0.5;
const double ONE_MINUS_PHI = 1-PHI;

long long fib(int n) {
	double f = (pow(PHI, n) - pow(ONE_MINUS_PHI, n)) / SQRT5;
	return f;
}
