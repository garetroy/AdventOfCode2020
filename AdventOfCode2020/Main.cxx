#include "./Day1/Day1.h"
#include "./Day2/Day2.h"
#include "./Day3/Day3.h"
#include "./Day4/Day4.h"
#include "./Day5/Day5.h"
#include "./Day6/Day6.h"
#include "./Day7/Day7.h"

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

	std::cout << "---- DAY 4 ----" << std::endl;
	std::unique_ptr<AdventOfCode2020::Day4> d4(new AdventOfCode2020::Day4);
	const int d4p1(d4->part1());
	std::cout << "Part 1: " << d4p1 << std::endl;
	const unsigned long long d4p2(d4->part2());
	std::cout << "Part 2: " << d4p2 << std::endl;

	std::cout << "---- DAY 5 ----" << std::endl;
	std::unique_ptr<AdventOfCode2020::Day5> d5(new AdventOfCode2020::Day5);
	const float d5p1(d5->part1());
	std::cout << "Part 1: " << d5p1 << std::endl;
	const float d5p2(d5->part2());
	std::cout << "Part 2: " << d5p2 << std::endl;

	std::cout << "---- DAY 6 ----" << std::endl;
	std::unique_ptr<AdventOfCode2020::Day6> d6(new AdventOfCode2020::Day6);
	const int d6p1(d6->part1());
	std::cout << "Part 1: " << d6p1 << std::endl;
	const int d6p2(d6->part2());
	std::cout << "Part 2: " << d6p2 << std::endl;

	std::cout << "---- DAY 7 ----" << std::endl;
	std::unique_ptr<AdventOfCode2020::Day7> d7(new AdventOfCode2020::Day7);
	const int d7p1(d7->part1());
	std::cout << "Part 1: " << d7p1 << std::endl;
	const int d7p2(d7->part2());
	std::cout << "Part 2: " << d7p2 << std::endl;

}
