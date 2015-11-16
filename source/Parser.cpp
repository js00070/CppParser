#include "Parser.h"

namespace CppParser
{
	Token& TokenStream::operator[](int x)
	{
		while (tokenQueue_.size() - 1 < x)
			tokenQueue_.push_back(scanner_.GetNextToken());
		return tokenQueue_[x];
	}

	void Parser::parsing()
	{
		std::unique_ptr<Stmt> pStmt;
		while (tokenStream_[0].GetTokenType() != TokenType::END_OF_FILE)
		{
			pStmt = parseStmt();
		}
	}

	std::unique_ptr<Stmt> Parser::parseStmt()
	{
		Token token = peekToken();
		eatToken();
		switch (token.GetTokenValue())
		{
		case TokenValue::IF:
			return parseIfStmt();
			break;
		case TokenValue::FOR:
			break;
		case TokenValue::WHILE:
			break;
		
		}
	}

	std::unique_ptr<Stmt> Parser::parseIfStmt()
	{
		std::unique_ptr<Expr> expr(parseExpr());
		std::unique_ptr<Stmt> mainBody(parseStmt());
		std::unique_ptr<Stmt> elseBody(nullptr);
		if (peekValue() == TokenValue::ELSE)
		{
			eatToken();
			elseBody = parseStmt();
		}
		return std::unique_ptr<Stmt> \
			(new IfStmt(expr, mainBody, elseBody));
	}

	std::unique_ptr<Expr> Parser::parseExpr()
	{

	}
}