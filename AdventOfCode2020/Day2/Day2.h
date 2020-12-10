#ifndef _DAY2_H_
#define _DAY2_H_

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{

	class Day2
	{
	private:
		folly::fbstring input;

	public:
		Day2()
			: input("Day2Source.txt")
		{}

		int part1() { return -1; };
		int part2() { return -1; };
	}; //End of class Day2
} //End of AdventOfCode2020 namespace

#endif //End of _DAY2_H_