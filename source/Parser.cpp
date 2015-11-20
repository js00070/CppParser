#include "Parser.h"

namespace CppParser
{
	Token& TokenStream::operator[](int x)
	{
		while (tokenQueue_.size() - 1 < x)
			tokenQueue_.push_back(scanner_.GetNextToken());
		return tokenQueue_[x];
	}

	void Parser::eatToken(TokenType tt)
	{
		if (tt == tokenStream_[0].GetTokenType())
		{
			tokenStream_.popToken();
		}
	}

	void Parser::eatToken(TokenValue tv)
	{
		if (tv == tokenStream_[0].GetTokenValue())
		{
			tokenStream_.popToken();
		}
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
		switch (token.GetTokenValue())
		{
		case TokenValue::IF:
			return parseIfStmt();
			break;
		case TokenValue::FOR:
			return parseForStmt();
			break;
		case TokenValue::WHILE:
			return parseWhileStmt();
			break;
		case TokenValue::LEFT_BRACE:
			return parseCompoundStmt();
			break;
		}
	}

	std::unique_ptr<Stmt> Parser::parseIfStmt()
	{
		eatToken(TokenValue::IF); // eat 'if'
		eatToken(TokenValue::LEFT_PAREN); // eat '('
		std::unique_ptr<Expr> expr(parseExpr());
		std::unique_ptr<Stmt> thenBody(parseStmt());
		std::unique_ptr<Stmt> elseBody(nullptr);
		if (peekValue() == TokenValue::ELSE)
		{
			eatToken();
			elseBody = parseStmt();
		}
		return std::unique_ptr<Stmt> \
			(new IfStmt(expr, thenBody, elseBody));
	}

	std::unique_ptr<Stmt> Parser::parseForStmt()
	{

	}

	std::unique_ptr<Stmt> Parser::parseWhileStmt()
	{
		eatToken(TokenValue::WHILE); // eat 'while'
		eatToken(TokenValue::LEFT_PAREN); // eat '('
		std::unique_ptr<Expr> expr(parseExpr());
		std::unique_ptr<Stmt> body(parseStmt());
		return std::unique_ptr<Stmt>(new WhileStmt(expr,body));
	}

	std::unique_ptr<Stmt> Parser::parseCompoundStmt()
	{
		eatToken(TokenValue::LEFT_BRACE); // eat '{'
		std::unique_ptr<CompoundStmt> ret(new CompoundStmt);
		while (peekValue() != TokenValue::RIGHT_BRACE)
		{
			ret->addStmt(parseStmt());
		}
		eatToken(TokenValue::RIGHT_BRACE); // eat '}'
		return std::unique_ptr<Stmt>(std::move(ret));
	}

	std::unique_ptr<Expr> Parser::parseExpr()
	{
		std::unique_ptr<Expr> ret;
	}

	std::unique_ptr<Expr> Parser::parsePostfixExpr()
	{
		std::unique_ptr<Expr> ret;
	}

	std::unique_ptr<Expr> Parser::parsePrimaryExpr()
	{
		TokenValue tv = peekValue();

	}
}