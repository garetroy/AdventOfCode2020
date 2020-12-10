#include "./Day1/Day1.h"
#include "./Day2/Day2.h"
#include "./Day3/Day3.h"

#include <iostream>
#include <memory>

int main()
{
	std::cout << "---- DAY 1 ----" << std::endl;
	std::unique_ptr<AdventOfCode2020::Day1> d1(new AdventOfCode2020::Day1);
	const int d1p1(d1->solutionp1());
	std::cout << "Part 1: " << d1p1 << std::endl;
	const int d1p2(d1->solutionp2());
	std::cout << "Part 2: " << d1p2 << std::endl;

	std::cout << "---- DAY 2 ----" << std::endl;
	std::unique_ptr<AdventOfCode2020::Day2> d2(new AdventOfCode2020::Day2);
	const int d2p1(d2->part1());
	std::cout << "Part 1: " << d2p1 << std::endl;
	const int d2p2(d2->part2());
	std::cout << "Part 2: " << d2p2 << std::endl;

	std::cout << "---- DAY 3 ----" << std::endl;
	std::unique_ptr<AdventOfCode2020::Day3> d3(new AdventOfCode2020::Day3);
	const int d3p1(d3->part1());
	std::cout << "Part 1: " << d3p1 << std::endl;
	const unsigned long long d3p2(d3->part2());
	std::cout << "Part 2: " << d3p2 << std::endl;


}
