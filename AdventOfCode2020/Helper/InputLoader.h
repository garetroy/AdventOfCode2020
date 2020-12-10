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
	};

} //End of namespace AdventOfCode2020

#endif //End of _INPUTLOADER_H_
