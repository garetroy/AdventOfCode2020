#ifndef _INPUTLOADER_H_
#define _INPUTLOADER_H_

#include <fstream>

#include <folly/FBString.h>
#include <folly/FBVector.h>

namespace AdventOfCode2020
{
	class InputLoader
	{
	public:
		template<typename T>
		const folly::fbvector<T> const getInput(folly::fbstring fileLocation)
		{
			T item;
			folly::fbvector<T> out;
			std::ifstream infile(fileLocation.toStdString());

			while (infile >> item)
			{
				out.emplace_back(item);
				item = T();
			}

			return out;
		}

		template<typename T>
		const T const getSingleItemInput(folly::fbstring fileLocation)
		{
			T item;
			std::ifstream infile(fileLocation.toStdString());

			infile >> item;

			return item;
		}

		const folly::fbvector<folly::fbstring> const splitString(std::string str, std::string delimiter)
		{
			folly::fbvector<folly::fbstring> splitStrings;
			while (str.find(delimiter) != std::string::npos)
			{
				folly::fbstring subStr = str.substr(0, str.find(delimiter));
				splitStrings.emplace_back(subStr);

				str.erase(0, str.find(delimiter) + 1);
			}

			if (str != "")
				splitStrings.emplace_back(str);

			return splitStrings;
		}
	};

} //End of namespace AdventOfCode2020

#endif //End of _INPUTLOADER_H_
