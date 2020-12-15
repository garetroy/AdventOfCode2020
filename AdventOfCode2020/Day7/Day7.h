#ifndef _DAY7_H_
#define _DAY7_H_

#include "../Helper/InputLoader.h"

#include <iostream>
#include <istream>
#include <unordered_map>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{

	class LuggageRule 
	{
	public:
		std::unordered_map<folly::fbstring, int> containingBags; //bag name and amount
		folly::fbstring bagName;

		//No real error handling here.... Just for brevity
		friend std::istream& operator>>(std::istream& input, LuggageRule& luggageRule)
		{
			std::string line;
			std::getline(input, line);

			if (line.empty())
				return input;

			//Assumes no bad data... 
			size_t bagNameEndingLocation = line.find("bags");
			luggageRule.bagName = line.substr(0, bagNameEndingLocation - 1); //-1 removes space

			size_t afterBagNameOffset = bagNameEndingLocation + folly::fbstring("bags contain ").length();
			if (line.find("no other bags", afterBagNameOffset)  != std::string::npos)
				return input;

			folly::fbstring allowedBagsWithinString = line.substr(afterBagNameOffset, line.size() - 1); //-1 removes period
			folly::fbvector<folly::fbstring> allowedBagsWithin = AdventOfCode2020::InputLoader().splitString(allowedBagsWithinString.toStdString(), ",");

			for (folly::fbstring allowedBag : allowedBagsWithin)
			{
				//Assumes no duplicates..
				//Assumes first part is always a number and seperated by space.. E.G. 10 ...

				size_t countEnd = allowedBag.find(" ", 1);
				folly::fbstring countOfAllowedBagString = allowedBag.substr(0, countEnd);
				int countOfAllowedBag = std::stoi(countOfAllowedBagString.toStdString());

				folly::fbstring endingBagName = countOfAllowedBag == 1 ? "bag" : "bags";
				size_t bagNameEnd = allowedBag.find(endingBagName);
				folly::fbstring bagName = allowedBag.substr(countEnd + 1, bagNameEnd - endingBagName.length() + 1); //+1 removes space after count

				char lastChar = bagName.at(bagName.length() - 1);
				if (lastChar == ' ' || lastChar == '.' || lastChar == ',')
					bagName = bagName.substr(0, bagName.length() - 1);

				luggageRule.containingBags.insert_or_assign(bagName, countOfAllowedBag);
			}

			return input;
		}

		friend std::ostream& operator<<(std::ostream& os, const LuggageRule& luggageRule)
		{
			os << "-- Luggage Rule --" << std::endl;

			os << std::endl;
			os << "--------------------------" << std::endl;

			return os;
		}
	};

	class Day7
	{
	private:
		folly::fbstring input;
		folly::fbvector<LuggageRule> data;

	public:
		Day7()
			: input("./Day7/Day7Source.txt")
		{
			data = AdventOfCode2020::InputLoader().getInput<LuggageRule>(input);
		}

		const int part1()
		{
			int count = 0;
			return count;
		};

		const int part2()
		{
			int count = 0;
			return count;
		};
	}; //End of class Day7
} //End of AdventOfCode2020 namespace

#endif //End of _DAY7_H_