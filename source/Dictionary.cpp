#include "Dictionary.h"

namespace CppParser
{
	Dictionary::Dictionary()
	{
		AddToken("=", TokenType::OPERATORS, TokenValue::ASSIGN, 0);
		AddToken("+=", TokenType::OPERATORS, TokenValue::PLUS_ASSIGN, 0);
		AddToken("*=", TokenType::OPERATORS, TokenValue::MULTIPLY_ASSIGN, 0);
		AddToken("-=", TokenType::OPERATORS, TokenValue::MINUS_ASSIGN, 0);
		AddToken("/=", TokenType::OPERATORS, TokenValue::DIVIDE_ASSIGN, 0);

		AddToken("+", TokenType::OPERATORS, TokenValue::PLUS, 10);
		AddToken("-", TokenType::OPERATORS, TokenValue::MINUS, 10);
		AddToken("*", TokenType::OPERATORS, TokenValue::MULTIPLY, 20);
		AddToken("/", TokenType::OPERATORS, TokenValue::DIVIDE, 20);
		AddToken("++", TokenType::OPERATORS, TokenValue::PLUS_PLUS, 40);
		AddToken("--", TokenType::OPERATORS, TokenValue::MINUS_MINUS, 40);

		
		AddToken("auto", TokenType::KEYWORDS, TokenValue::AUTO, -1);
		AddToken("bool", TokenType::KEYWORDS, TokenValue::BOOL, -1);
		AddToken("break", TokenType::KEYWORDS, TokenValue::BREAK, -1);
		AddToken("case", TokenType::KEYWORDS, TokenValue::CASE, -1);
		AddToken("catch", TokenType::KEYWORDS, TokenValue::CATCH, -1);
		AddToken("char", TokenType::KEYWORDS, TokenValue::CHAR, -1);
		AddToken("class", TokenType::KEYWORDS, TokenValue::CLASS, -1);
		AddToken("const", TokenType::KEYWORDS, TokenValue::CONST, -1);
		AddToken("const_cast", TokenType::KEYWORDS, TokenValue::CONSTEXPR, -1);
		AddToken("continue", TokenType::KEYWORDS, TokenValue::CONTINUE, -1);
		AddToken("decltype", TokenType::KEYWORDS, TokenValue::DECLTYPE, -1);
		AddToken("default", TokenType::KEYWORDS, TokenValue::DEFAULT, -1);
		AddToken("delete", TokenType::KEYWORDS, TokenValue::DELETE, -1);
		AddToken("do", TokenType::KEYWORDS, TokenValue::DO, -1);
//		AddToken("", TokenType::KEYWORDS, TokenValue::, -1);
	}

	bool Dictionary::HaveToken(const std::string& name)
	{
		auto it = dict_.find(name);
		if (it == dict_.end())
			return false;
		return true;
	}

	void Dictionary::AddToken(const std::string& name, TokenType type,
		TokenValue value, int symbolPrecedence)
	{
		dict_.insert(std::make_pair(name,std::make_tuple(type,value,symbolPrecedence)));
	}
}