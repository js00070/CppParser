#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <unordered_map>
#include <string>
#include <tuple>
#include "Token.h"

namespace CppParser
{
	class Dictionary
	{
	public:

	private:
		std::unordered_map<std::string, std::tuple<TokenType, TokenValue, int>> dict_;
	};
}

#endif