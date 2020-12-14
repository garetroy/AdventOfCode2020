#ifndef _DAY4_H_
#define _DAY4_H_

#include "../Helper/InputLoader.h"

#include <iostream>
#include <istream>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <string>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{

	class Passport
	{
	private:
		std::unordered_map<folly::fbstring, folly::fbstring> parseableFields;


	public:

		Passport()
		{
			parseableFields = {
				{ "byr:", "" },//Birth Year
				{ "iyr:", "" },//Issue Year
				{ "eyr:", "" },//Experation Year
				{ "hgt:", "" },//Height
				{ "hcl:", "" },//Hair Color
				{ "ecl:", "" },//Eye Color
				{ "pid:", "" },//Passport ID
				{ "cid:", "" },//Country ID
			};
		}

		//No real error handling here.... Just for brevity
		friend std::istream& operator>>(std::istream& input, Passport& passport)
		{
			std::string line;
			std::getline(input, line);

			folly::fbvector<folly::fbstring> fieldsGathered;

			while (!line.empty())
			{
				folly::fbvector<folly::fbstring> fieldsFromLine = InputLoader().splitString(line, " ");
				fieldsGathered.insert(
					fieldsGathered.end(),
					fieldsFromLine.begin(),
					fieldsFromLine.end()
				);

				if (!input.eof())
					std::getline(input, line);
				else
					break;
			}

			for (folly::fbstring s : fieldsGathered)
			{
				if (static_cast<int>(s.length()) < 4)
					continue;

				folly::fbstring key = s.substr(0, 4);

				if (passport.parseableFields.find(key) == passport.parseableFields.end())
					continue;

				folly::fbstring value = s.substr(4, s.length());
				passport.parseableFields.insert_or_assign(key, value);
			}

			return input;
		}

		friend std::ostream& operator<<(std::ostream& os, const Passport& passport)
		{
			os << "-- Passport --" << std::endl;

			for (auto kv : passport.parseableFields)
				os << kv.first << kv.second << std::endl;

			os << "--------------------------" << std::endl;

			return os;
		}

		const bool isBasicValidPassport()
		{
			bool valid = true;
			for (auto kv : parseableFields)
			{
				valid = valid && (!kv.second.empty() || kv.first == "cid:");
			}

			return valid;
		}

		const bool isValidPassport()
		{
			//Could do this better, but I got fed up at this point.
			for (auto kv : parseableFields)
			{
				if (kv.first == "cid:")
					continue;

				if (kv.first == "byr:")
				{
					if (static_cast<int>(kv.second.length()) != 4)
						return false;

					int year = std::stoi(kv.second.toStdString());
					if (year < 1920 || year > 2002)
						return false;
				}
				else if (kv.first == "iyr:")
				{
					if (static_cast<int>(kv.second.length()) != 4)
						return false;

					int year = std::stoi(kv.second.toStdString());
					if (year < 2010 || year > 2020)
						return false;
				}
				else if (kv.first == "eyr:")
				{
					if (static_cast<int>(kv.second.length()) != 4)
						return false;

					int year = std::stoi(kv.second.toStdString());
					if (year < 2020 || year > 2030)
						return false;
				}
				else if (kv.first == "hgt:")
				{
					if (static_cast<int>(kv.second.length()) < 4)
						return false;

					folly::fbstring units = kv.second.substr(kv.second.length() - 2, kv.second.length());
					if (static_cast<int>(units.length()) != 2)
						return false;

					if (units != "cm" && units != "in")
						return false;

					folly::fbstring measurement = kv.second.substr(0, kv.second.length() - 2);
					int measurmentI = std::stoi(measurement.toStdString());
					if (units == "cm" && (measurmentI < 150 || measurmentI > 193))
						return false;

					if (units == "in" && (measurmentI < 59 || measurmentI > 76))
						return false;
				}
				else if (kv.first == "hcl:")
				{
					if (static_cast<int>(kv.second.length()) < 7)
						return false;

					const std::regex base_regex("#((?:[A-f0-9]{3}){1,2})");
					if (!std::regex_match(kv.second.toStdString(), base_regex))
						return false;
				}
				else if (kv.first == "ecl:")
				{
					if (static_cast<int>(kv.second.length()) < 3)
						return false;

					const std::unordered_set<folly::fbstring> validColors =
					{
						"amb",
						"blu",
						"brn",
						"gry",
						"grn",
						"hzl",
						"oth"
					};

					if (validColors.find(kv.second) == validColors.end())
						return false;
				}
				else if (kv.first == "pid:")
				{
					if (static_cast<int>(kv.second.length()) < 9)
						return false;

					try
					{
						std::stoi(kv.second.toStdString());
					}
					catch(std::exception e)
					{
						return false;
					}
				}
			}

			return true;
		}
	};

	class Day4
	{
	private:
		folly::fbstring input;
		folly::fbvector<Passport> data;

	public:
		Day4()
			: input("./Day4/Day4Source.txt")
		{
			data = AdventOfCode2020::InputLoader().getInput<Passport>(input);
		}

		const int part1()
		{
			int count = 0;
			for (Passport p : data)
				if (p.isBasicValidPassport())
					count++;

			return count;
		};

		const int part2()
		{
			int count = 0;
			for (Passport p : data)
				if (p.isValidPassport())
					count++;

			return count;
		};
	}; //End of class Day4
} //End of AdventOfCode2020 namespace

#endif //End of _DAY4_H_