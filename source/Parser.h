#ifndef PARSER_H
#define PARSER_H

#include "Basic.h"
#include "Scanner.h"
#include <string>
#include "AST\AST.h"
#include <deque>

namespace CppParser
{
	class TokenStream
	{
	public:
		TokenStream(std::string& fileName) :
			fileName_(fileName), scanner_(fileName),
			tokenQueue_() {}
		
		void popToken()
		{
			tokenQueue_.pop_front();
		}

		Token& operator[](int x);

	private:
		std::string fileName_;
		Scanner scanner_;
		std::deque<Token> tokenQueue_;
	};

	class Parser : public zl::Interface
	{
	public:
		explicit Parser(std::string& fileName) :
			fileName_(fileName), tokenStream_(fileName) {}
		
		void parsing();

	private:
		void eatToken()
		{
			tokenStream_.popToken();
		}

		void eatToken(TokenType tt);
		void eatToken(TokenValue tv);

		Token& peekToken(int x = 0)
		{
			return tokenStream_[x];
		}

		TokenValue peekValue(int x = 0)
		{
			return tokenStream_[x].GetTokenValue();
		}

		TokenType peekType(int x = 0)
		{
			return tokenStream_[x].GetTokenType();
		}

		void pushStmt(Stmt* pStmt)
		{
			ast_.emplace_back(std::unique_ptr<Stmt>(pStmt));
		}

		void pushStmt(std::unique_ptr<Stmt>& pStmt)
		{
			ast_.emplace_back(std::move(pStmt));
		}

		std::unique_ptr<Stmt> parseStmt();
		std::unique_ptr<Stmt> parseIfStmt();
		std::unique_ptr<Stmt> parseForStmt();
		std::unique_ptr<Stmt> parseWhileStmt();
		std::unique_ptr<Stmt> parseCompoundStmt();

		std::unique_ptr<Expr> parseExpr();
		std::unique_ptr<Expr> parseParenExpr();

	private:
		const std::string fileName_;
		TokenStream tokenStream_;
		StmtList ast_;
	};


}

#endif
