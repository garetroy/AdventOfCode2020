#ifndef _DAY6_H_
#define _DAY6_H_

#include "../Helper/InputLoader.h"

#include <iostream>
#include <istream>
#include <unordered_set>
#include <unordered_map>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{

	class CustomsSheet 
	{
	public:
		std::unordered_set<char> answerSet;
		std::unordered_map<char, int> allAnsweredSet;
		int personsInGroup;

		//No real error handling here.... Just for brevity
		friend std::istream& operator>>(std::istream& input, CustomsSheet& customsSheet)
		{
			std::string line;
			std::getline(input, line);

			int personCount = 0;

			while (!line.empty())
			{
				personCount++;

				for (char c : line)
				{
					if (std::isalpha(c))
					{
						customsSheet.answerSet.insert(c);

						if(customsSheet.allAnsweredSet.find(c) == customsSheet.allAnsweredSet.end())
							customsSheet.allAnsweredSet.insert_or_assign(c, 1);
						else
							customsSheet.allAnsweredSet.insert_or_assign(c, customsSheet.allAnsweredSet[c] + 1);
					}
				}

				if (!input.eof())
					std::getline(input, line);
				else
					break;
			}

			customsSheet.personsInGroup = personCount;

			return input;
		}

		friend std::ostream& operator<<(std::ostream& os, const CustomsSheet& customsSheet)
		{
			os << "-- Customs Sheet --" << std::endl;

			for (auto i : customsSheet.answerSet)
				os << i;

			os << std::endl;
			os << "--------------------------" << std::endl;

			return os;
		}
	};

	class Day6
	{
	private:
		folly::fbstring input;
		folly::fbvector<CustomsSheet> data;

	public:
		Day6()
			: input("./Day6/Day6Source.txt")
		{
			data = AdventOfCode2020::InputLoader().getInput<CustomsSheet>(input);
		}

		const int part1()
		{
			int count = 0;
			for(CustomsSheet cs : data)
				count += static_cast<int>(cs.answerSet.size());

			return count;
		};

		const int part2()
		{
			int count = 0;
			for (CustomsSheet cs : data)
				for (auto answer : cs.allAnsweredSet)
					if (answer.second == cs.personsInGroup)
						count++;

			return count;
		};
	}; //End of class Day6
} //End of AdventOfCode2020 namespace

#endif //End of _DAY6_H_