#ifndef _DAY1_H_
#define _DAY1_H_

#include "../Helper/InputLoader.h"

#include <fstream>
#include <vector>
#include <unordered_map>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{
	class Day1
	{
	private:
		folly::fbstring input;

	public:
		Day1() 
			: input("./Day1/Day1Source.txt")
		{}

		const int solutionp1()
		{
			int entry = -1;
			std::unordered_map<int, int> additionSet;
			std::ifstream infile(input.toStdString());

			while (infile >> entry)
			{
				const auto found = additionSet.find(entry);
				if (found != additionSet.end())
				{
					return entry * found->second;
				}

				int remainder = 2020 - entry;
				additionSet.insert_or_assign(remainder, entry);
			}

			return -1;
		}

		const int solutionp2()
		{
			int desiredSum = 2020;

			folly::fbvector<int> data = AdventOfCode2020::InputLoader().getInput<int>(input); 
			std::sort(data.begin(), data.end());

			int dataSize = static_cast<int>(data.size());

			for(int i = 0; i < dataSize - 2; i++)
			{
				int j = i + 1;
				int k = dataSize - 1;

				while (j < k)
				{ 
					int sum = data[i] + data[j] + data[k];
					if (sum == desiredSum)
						return data[i] * data[j] * data[k];
					else if (sum > desiredSum)
						k--;
					else if (sum < desiredSum)
						j++;
				}
			}

			return -1;
		}
	}; // End Day1 Class

} //End AdventOfCode2020 Namespace

#endif