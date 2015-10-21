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
		
		Dictionary();
		bool HaveToken(const std::string& name);
	private:
		void AddToken(const std::string& name,TokenType type,TokenValue value,int symbolPrecedence);

		std::unordered_map<std::string, std::tuple<TokenType, TokenValue, int>> dict_;
	};
}

#endif