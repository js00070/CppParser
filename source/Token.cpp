#include "Token.h"

namespace CppParser
{
	std::string TokenLocation::ToString() const
	{
		return std::move(fileName_ + ":" + std::to_string(line_) 
			+ "," + std::to_string(column_));
	}

	Token::Token(TokenType type,TokenValue value,TokenLocation& location,
		int symbolPrecedence, const std::string& name,int intValue) :
		type_(type), value_(value), location_(location),
		symbolPrecedence_(symbolPrecedence), name_(name),
		intValue_(intValue)
	{}

	Token::Token(TokenType type, TokenValue value, TokenLocation& location,
		int symbolPrecedence, const std::string& name, double floatValue) :
		type_(type), value_(value), location_(location),
		symbolPrecedence_(symbolPrecedence), name_(name),
		floatValue_(floatValue)
	{}

	Token::Token(TokenType type, TokenValue value, TokenLocation& location,
		int symbolPrecedence, const std::string& name, const std::string strValue) :
		type_(type), value_(value), location_(location),
		symbolPrecedence_(symbolPrecedence), name_(name),
		strValue_(strValue)
	{}
}