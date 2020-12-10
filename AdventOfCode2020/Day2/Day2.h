#ifndef _DAY2_H_
#define _DAY2_H_

#include "../Helper/InputLoader.h"

#include <iostream>
#include <istream>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{

	class PasswordRequirement
	{
	private:
		folly::fbstring password;
		int min;
		int max;
		char desiredChar;

	public:
		//No real error handling here.... Just for brevity
		friend std::istream& operator>>(std::istream& input, PasswordRequirement& passwordRequirement)
		{
			std::string line;
			std::getline(input, line);

			if (line == "")
				return input;

			//Left Half Processing
			size_t firstHalfLocation = line.find(":");
			folly::fbstring requirements = line.substr(0, firstHalfLocation);

			//Min-Max Processing
			size_t splitLocation = requirements.find(" ");
			folly::fbstring minMax = requirements.substr(0, splitLocation);
			passwordRequirement.min = std::stoi(minMax.substr(0).toStdString(), nullptr);
			passwordRequirement.max = std::stoi(minMax.substr(requirements.find("-") + 1).toStdString(), nullptr);

			//Desired Char Processing
			passwordRequirement.desiredChar = requirements.at(firstHalfLocation - 1);

			//Password Processing
			passwordRequirement.password = line.substr(firstHalfLocation + 2, line.size());

			return input;
		}

		friend std::ostream& operator<<(std::ostream& os, const PasswordRequirement& passwordRequirement)
		{
			os << "-- Password Requirement --" << std::endl;
			os << " -Password: " << passwordRequirement.password << std::endl;
			os << " -DesiredChar: " << passwordRequirement.desiredChar << std::endl;
			os << " -Min: " << passwordRequirement.min << std::endl;
			os << " -Max: " << passwordRequirement.max << std::endl;
			os << "--------------------------" << std::endl;

			return os;
		}
	};

	class Day2
	{
	private:
		folly::fbstring input;
		folly::fbvector<PasswordRequirement> data;

	public:
		Day2()
			: input("./Day2/Day2Source.txt")
		{
			data = AdventOfCode2020::InputLoader().getInput<PasswordRequirement>(input);
		}

		int part1() 
		{ 
			return -1;
		};

		int part2() { return -1; };
	}; //End of class Day2
} //End of AdventOfCode2020 namespace

#endif //End of _DAY2_H_