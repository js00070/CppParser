#ifndef TOKEN_H
#define TOKEN_H

#include "Basic.h"
#include <string>

namespace CppParser
{
	enum class TokenType
	{
		NONE,

		INT,
		FLOAT,
		BOOL,
		CHAR,
		STRING,

		IDENTIFIER,
		KEYWORDS,
		OPERATORS,
		DELIMITER,
	};

	enum class TokenValue
	{
		NONE,

		// keywords
		AUTO,
		BOOL,
		BREAK,
		CASE,
		CATCH,
		CHAR,
		CLASS,
		CONST,
		CONSTEXPR,
		CONST_CAST,
		CONTINUE,
		DECLTYPE,
		DEFAULT,
		DELETE,
		DO,
		DOUBLE,
		DYNAMIC_CAST,
		ELSE,
		ENUM,
		EXPLICIT,
		EXTERN,
		FLOAT,
		FOR,
		FRIEND,
		GOTO,
		IF,
		INLINE,
		INT,
		LONG,
		MUTABLE,
		NAMESPACE,
		NEW,
		NOEXCEPT,
		NULLPTR,
		OPERATOR,
		PRIVATE,
		PROTECTED,
		PUBLIC,
		REINTERPRET_CAST,
		RETURN,
		SHORT,
		SIGNED,
		SIZEOF,
		STATIC,
		STATIC_CAST,
		STRUCT,
		SWITCH,
		TEMPLATE,
		THIS,
		THROW,
		TRY,
		TYPEDEF,
		TYPEID,
		TYPENAME,
		UNION,
		UNSIGNED,
		USING,
		VIRTUAL,
		VOID,
		VOLATILE,
		WCHAR_T,
		WHILE,
		OVERRIDE,
		FINAL,

		// preprocessor...

		// symbols
		LEFT_PAREN,        //(
		RIGHT_PAREN,       //)
		LEFT_SQUARE,       //[
		RIGHT_SQUARE,      //]
		PLUS,              //+
		PLUS_PLUS,         //++
		MINUS,             //-
		MINUS_MINUS,       //--
		MULTIPLY,          //*
		DIVIDE,            //div
		COMMA,             //,
		SEMICOLON,         //;
		COLON,             //:
		COLON_COLON,       //::
		ASSIGN,            //=
		PLUS_ASSIGN,       //+=
		MINUS_ASSIGN,      //-=
		MULTIPLY_ASSIGN,   //*=
		DIVIDE_ASSIGN,     //div=
		DOT,               //.
		RIGHT_ARROW        //->
		
	};

	class TokenLocation : public zl::Object
	{
	public:
		TokenLocation() :
			fileName_(""), line_(0), column_(0)
		{}
		TokenLocation(const std::string fileName, int line, int column) :
			fileName_(fileName), line_(line), column_(column)
		{}
		std::string ToString() const;
	private:
		std::string fileName_;
		int line_;
		int column_;
	};

	class Token : public zl::Object
	{
	public:
		Token() :
			type_(TokenType::NONE), value_(TokenValue::NONE),
			location_(std::string(""),0,0), symbolPrecedence_(0), name_(""),
			intValue_(0), floatValue_(0.0), strValue_(std::string(""))
		{}

		Token(TokenType, TokenValue, TokenLocation&, int, const std::string&, int);
		Token(TokenType, TokenValue, TokenLocation&, int, const std::string&, double);
		Token(TokenType, TokenValue, TokenLocation&, int, const std::string&, const std::string);
	private:
		TokenType type_;
		TokenValue value_;
		TokenLocation location_;
		int symbolPrecedence_;
		std::string name_;

		// const values of token
		int intValue_;
		double floatValue_;
		std::string strValue_;
	};
}

#endif