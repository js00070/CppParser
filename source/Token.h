#ifndef TOKEN_H
#define TOKEN_H

#include "Basic.h"
#include <string>

namespace CppParser
{
	enum class TokenType
	{
		INT,
		FLOAT,
		BOOL,
		CHAR,
		STRING,

		IDENTIFIER,
		KEYWORDS,
		OPERATORS,
		DELIMITER,
		UNKNOWN
	};

	enum class TokenValue
	{
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
		TokenLocation();
		TokenLocation(std::string fileName, int line, int column);
		std::string ToString() const;
	private:
		std::string _fileName;
		int _line;
		int _column;
	};

	class Token : public zl::Object
	{
	public:

	private:
		TokenType _type;
		TokenValue _value;
		TokenLocation _location;
		int _symbolPrecedence;
		std::string _name;
	};
}

#endif