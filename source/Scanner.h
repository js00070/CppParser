#ifndef SCANNER_H
#define SCANNER_H

#include "Basic.h"
#include <fstream>
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