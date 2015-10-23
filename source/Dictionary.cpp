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

		AddToken("(", TokenType::DELIMITER, TokenValue::LEFT_PAREN, -1);
		AddToken(")", TokenType::DELIMITER, TokenValue::RIGHT_PAREN, -1);
		AddToken("[", TokenType::DELIMITER, TokenValue::LEFT_SQUARE, -1);
		AddToken("]", TokenType::DELIMITER, TokenValue::RIGHT_SQUARE, -1);
		AddToken("{", TokenType::DELIMITER, TokenValue::LEFT_BRACE, -1);
		AddToken("}", TokenType::DELIMITER, TokenValue::RIGHT_BRACE, -1);
		AddToken(",", TokenType::DELIMITER, TokenValue::COMMA, -1);
		AddToken(";", TokenType::DELIMITER, TokenValue::SEMICOLON, -1);
		AddToken(":", TokenType::DELIMITER, TokenValue::COLON, -1);
		AddToken("::", TokenType::DELIMITER, TokenValue::COLON_COLON, -1);
		AddToken(".", TokenType::DELIMITER, TokenValue::DOT, -1);
		AddToken("->", TokenType::DELIMITER, TokenValue::RIGHT_ARROW, -1);


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
		AddToken("double", TokenType::KEYWORDS, TokenValue::DOUBLE, -1);
		AddToken("dynamic_cast", TokenType::KEYWORDS, TokenValue::DYNAMIC_CAST, -1);
		AddToken("else", TokenType::KEYWORDS, TokenValue::ELSE, -1);
		AddToken("enum", TokenType::KEYWORDS, TokenValue::ENUM, -1);
		AddToken("explicit", TokenType::KEYWORDS, TokenValue::EXPLICIT, -1);
		AddToken("extern", TokenType::KEYWORDS, TokenValue::EXTERN, -1);
		AddToken("float", TokenType::KEYWORDS, TokenValue::FLOAT, -1);
		AddToken("for", TokenType::KEYWORDS, TokenValue::FOR, -1);
		AddToken("friend", TokenType::KEYWORDS, TokenValue::FRIEND, -1);
		AddToken("goto", TokenType::KEYWORDS, TokenValue::GOTO, -1);
		AddToken("if", TokenType::KEYWORDS, TokenValue::IF, -1);
		AddToken("inline", TokenType::KEYWORDS, TokenValue::INLINE, -1);
		AddToken("int", TokenType::KEYWORDS, TokenValue::INT, -1);
		AddToken("long", TokenType::KEYWORDS, TokenValue::LONG, -1);
		AddToken("mutable", TokenType::KEYWORDS, TokenValue::MUTABLE, -1);
		AddToken("namespace", TokenType::KEYWORDS, TokenValue::NAMESPACE, -1);
		AddToken("new", TokenType::KEYWORDS, TokenValue::NEW, -1);
		AddToken("noexcept", TokenType::KEYWORDS, TokenValue::NOEXCEPT, -1);
		AddToken("nullptr", TokenType::KEYWORDS, TokenValue::NULLPTR, -1);
		AddToken("operator", TokenType::KEYWORDS, TokenValue::OPERATOR, -1);
		AddToken("private", TokenType::KEYWORDS, TokenValue::PRIVATE, -1);
		AddToken("protected", TokenType::KEYWORDS, TokenValue::PROTECTED, -1);
		AddToken("public", TokenType::KEYWORDS, TokenValue::PUBLIC, -1);
		AddToken("reinterpret_cast", TokenType::KEYWORDS, TokenValue::REINTERPRET_CAST, -1);
		AddToken("return", TokenType::KEYWORDS, TokenValue::RETURN, -1);
		AddToken("short", TokenType::KEYWORDS, TokenValue::SHORT, -1);
		AddToken("signed", TokenType::KEYWORDS, TokenValue::SIGNED, -1);
		AddToken("sizeof", TokenType::KEYWORDS, TokenValue::SIZEOF, -1);
		AddToken("static", TokenType::KEYWORDS, TokenValue::STATIC, -1);
		AddToken("static_cast", TokenType::KEYWORDS, TokenValue::STATIC_CAST, -1);
		AddToken("struct", TokenType::KEYWORDS, TokenValue::STRUCT, -1);
		AddToken("switch", TokenType::KEYWORDS, TokenValue::SWITCH, -1);
		AddToken("template", TokenType::KEYWORDS, TokenValue::TEMPLATE, -1);
		AddToken("this", TokenType::KEYWORDS, TokenValue::THIS, -1);
		AddToken("throw", TokenType::KEYWORDS, TokenValue::THROW, -1);
		AddToken("try", TokenType::KEYWORDS, TokenValue::TRY, -1);
		AddToken("typedef", TokenType::KEYWORDS, TokenValue::TYPEDEF, -1);
		AddToken("typeid", TokenType::KEYWORDS, TokenValue::TYPEID, -1);
		AddToken("typename", TokenType::KEYWORDS, TokenValue::TYPENAME, -1);
		AddToken("union", TokenType::KEYWORDS, TokenValue::UNION, -1);
		AddToken("unsigned", TokenType::KEYWORDS, TokenValue::UNSIGNED, -1);
		AddToken("using", TokenType::KEYWORDS, TokenValue::USING, -1);
		AddToken("virtual", TokenType::KEYWORDS, TokenValue::VIRTUAL, -1);
		AddToken("void", TokenType::KEYWORDS, TokenValue::VOID, -1);
		AddToken("volatile", TokenType::KEYWORDS, TokenValue::VOLATILE, -1);
		AddToken("wchar_t", TokenType::KEYWORDS, TokenValue::WCHAR_T, -1);
		AddToken("while", TokenType::KEYWORDS, TokenValue::WHILE, -1);
		AddToken("override", TokenType::KEYWORDS, TokenValue::OVERRIDE, -1);
		AddToken("final", TokenType::KEYWORDS, TokenValue::FINAL, -1);
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