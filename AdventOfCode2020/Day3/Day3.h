#ifndef _DAY3_H_
#define _DAY3_H_

#include "../Helper/InputLoader.h"

#include <iostream>
#include <istream>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{
	class TrajectoryMap
	{
	private:
		folly::fbvector<folly::fbstring> map;

		void doubleSize(int fromY)
		{
			for (int i = fromY; i < map.size(); i++)
			{
				//Just continuing the map
				map[i] = map[i] + map[i];
			}
		}

	public:
		TrajectoryMap()
			: map()
		{}

		friend std::istream& operator>>(std::istream& input, TrajectoryMap& trajectoryMap)
		{
			std::string line;

			while (std::getline(input, line))
			{
				trajectoryMap.map.emplace_back(line);
			}

			return input;
		}

		const int const rowCount()
		{
			return static_cast<int>(map.size());
		}

		const char const getAtCoordinates(int x, int y)
		{
			if (y > map.size())
				return '-';

			if (x > map[y].size())
				doubleSize(y);

			return map.at(y).at(x);
		}
	};

	class Day3
	{
	private:
		folly::fbstring input;
		TrajectoryMap data;

	public:
		Day3()
			: input("./Day3/Day3Source.txt")
		{
			data = AdventOfCode2020::InputLoader().getSingleItemInput<TrajectoryMap>(input);
		}

		const int part1()
		{
			int treeCount = 0;
			int xPosition = 3;
			for (int i = 1; i < data.rowCount(); i++)
			{
				const char location = data.getAtCoordinates(xPosition, i);

				if (location == '-')
					return treeCount;
				else if (location == '#')
					treeCount++;
				
				xPosition += 3;
			}

			return treeCount;
		};

		const double part2()
		{
			std::pair<int, int> directions[] = 
			{
				std::make_pair(1, 1), //right steps, down steps
				std::make_pair(3, 1),
				std::make_pair(5, 1),
				std::make_pair(7, 1),
				std::make_pair(1, 2),
			};

			unsigned long long treeProd = 1;
			for (std::pair<int, int> direction : directions)
			{
				unsigned long long treeCount = 0;
				int xPos = direction.first;
				for (int yPos = direction.second; yPos < data.rowCount(); yPos += direction.second, xPos += direction.first)
				{
					const char location = data.getAtCoordinates(xPos, yPos);

					if (location == '-')
						break;
					else if (location == '#')
						treeCount++;
				}

				treeProd *= treeCount;
			}

			return treeProd;
		};
	}; //End of class Day3
} //End of AdventOfCode2020 namespace

#endif //End of _DAY3_H_