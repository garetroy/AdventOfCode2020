#ifndef _DAY5_H_
#define _DAY5_H_

#include "../Helper/InputLoader.h"

#include <iostream>
#include <istream>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{

	class BoardingPass
	{
	public:
		float seatId;
		float row;
		float column;

		//No real error handling here.... Just for brevity
		friend std::istream& operator>>(std::istream& input, BoardingPass& boardingPass)
		{
			std::string line;
			std::getline(input, line);

			float currRowMax = 127;
			float currRowMin = 0;

			float currColMax = 7;
			float currColMin = 0;

			for (int i = 0; i < static_cast<int>(line.size()); i++)
			{
				if (line.at(i) == 'F')
				{
					currRowMax = std::floor((currRowMax + currRowMin) / 2);

					if (i == 6)
						boardingPass.row = currRowMin;
				}
				else if (line.at(i) == 'B')
				{
					currRowMin = std::ceil((currRowMax + currRowMin) / 2);

					if (i == 6)
						boardingPass.row = currRowMax;
				}
				else if (line.at(i) == 'L')
				{
					currColMax = std::floor((currColMax + currColMin) / 2);

					if (i == 9)
						boardingPass.column = currColMin;
				}
				else if (line.at(i) == 'R')
				{
					currColMin = std::ceil((currColMax + currColMin) / 2);

					if (i == 9)
						boardingPass.column = currColMax;
				}
			}

			boardingPass.seatId = boardingPass.row * 8 + boardingPass.column;

			return input;
		}

		friend std::ostream& operator<<(std::ostream& os, const BoardingPass& boardingPass)
		{
			os << "-- Boarding Pass --" << std::endl;
			os << "Row: " << boardingPass.row << std::endl;
			os << "Column: " << boardingPass.column << std::endl;
			os << "SeadId: " << boardingPass.seatId << std::endl;
			os << "--------------------------" << std::endl;

			return os;
		}
	};

	class Day5
	{
	private:
		folly::fbstring input;
		folly::fbvector<BoardingPass> data;

	public:
		Day5()
			: input("./Day5/Day5Source.txt")
		{
			data = AdventOfCode2020::InputLoader().getInput<BoardingPass>(input);
		}

		const float part1()
		{
			float max = -1;
			for (auto a : data)
				if (a.seatId > max)
					max = a.seatId;

			return max;
		};

		const float part2()
		{
			std::sort(data.begin(), data.end(), [](const BoardingPass& a, const BoardingPass& b) -> bool
				{
					return a.seatId < b.seatId;
				});

			for (size_t i = 1; i < data.size() - 1; i++)
			{
				BoardingPass& before = data.at(i - 1);
				BoardingPass& curr = data.at(i);
				BoardingPass& next = data.at(i + 1);

				if (before.column == 7 && curr.column != 0)
				{
					return (before.row + 1) * 8;
				}
				else if (next.column == 0 && curr.column != 7)
				{
					return (next.row - 1) * 8 + 7;
				}
				else if (before.column + 1 != curr.column && curr.column != 0)
				{
					return before.seatId + 1;
				}
			}

			return -1;
		};
	}; //End of class Day5
} //End of AdventOfCode2020 namespace

#endif //End of _DAY5_H_