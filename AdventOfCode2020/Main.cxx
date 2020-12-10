#include "./Day1/Day1.h"

#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<AdventOfCode2020::Day1> d1(new AdventOfCode2020::Day1);
	const int d1p1Sol(d1->solutionp1());
	std::cout << "Day Answer 1 Part 1: " << d1p1Sol << std::endl;
	const int d1p2Sol(d1->solutionp2());
	std::cout << "Day Answer 1 Part 2: " << d1p2Sol << std::endl;
}
