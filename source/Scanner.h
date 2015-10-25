#ifndef SCANNER_H
#define SCANNER_H

#include "Basic.h"
#include <fstream>
#include <iostream>
#include "Token.h"
#include "Dictionary.h"

namespace CppParser
{

	class Scanner : public zl::Interface
	{
	public:
		explicit Scanner(const std::string& srcFileName);
		Token GetToken() const;
		Token GetNextToken();
		bool GetErrorFlag();
		
		enum class State
		{
			NONE,

			END_OF_FILE,
			IDENTIFIER,
			NUMBER,
			STRING,
			OPERATION
		};

	private:
		void GetNextChar();
		char PeekChar();
		void AddToBuffer(char c);
		void ReduceBuffer();

		void MakeToken(TokenType tt,TokenValue tv,
			const TokenLocation& loc,std::string name);

		void MakeToken(TokenType tt,TokenValue tv,
			const TokenLocation& loc,int intValue,std::string name);

		void MakeToken(TokenType tt, TokenValue tv,
			const TokenLocation& loc, double floatValue, std::string name);

		void HandleEOFState();
		void HandleIdentifierState();
		void HandleNumberState();
		void HandleStringState();
		void HandleOperationState();
		void Preprocess();
		void HandleLineComment();
		void HandleBlockComment();
		TokenLocation GetTokenLocation() const;

		void HandleDigit();
		void HandleXDigit();
		

	private:
		const std::string fileName_;
		std::ifstream input_;
		int line_;
		int column_;
		TokenLocation loc_;
		char currentChar_;
		bool errorFlag_;
		State state_;
		Token token_;
		Dictionary dictionary_;
		std::string buffer_;
	};
}
#endif