#include "Token.h"

namespace CppParser
{
	std::string TokenLocation::ToString() const
	{
		return std::move(fileName_ + ":" + std::to_string(line_) 
			+ "," + std::to_string(column_));
	}

	Token::Token(TokenType type,TokenValue value,
		const TokenLocation& location,
		const std::string& name,int intValue) :
		type_(type), value_(value), location_(location),
		name_(name),
		intValue_(intValue)
	{}

	Token::Token(TokenType type, TokenValue value,
		const TokenLocation& location,
		const std::string& name, double floatValue) :
		type_(type), value_(value), location_(location),
		name_(name),
		floatValue_(floatValue)
	{}

	Token::Token(TokenType type, TokenValue value,
		const TokenLocation& location,
		const std::string& name, const std::string strValue) :
		type_(type), value_(value), location_(location),
		name_(name),
		strValue_(strValue)
	{}

	Token::Token(TokenType type, TokenValue value,
		const TokenLocation& location,
		const std::string& name) :
		type_(type), value_(value), location_(location),
		name_(name)
	{}

	TokenType Token::GetTokenType() const
	{
		return type_;
	}

	TokenValue Token::GetTokenValue() const
	{
		return value_;
	}
	
	void Token::Dump(std::ostream& out) const
	{
		out << location_.ToString() << "\t" << name_ << std::endl;
	}
}