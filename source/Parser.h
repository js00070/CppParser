#ifndef PARSER_H
#define PARSER_H

#include "Basic.h"
#include "Scanner.h"
#include <string>
#include "AST\AST.h"
#include <deque>

namespace CppParser
{
	class Parser : public zl::Interface
	{
	public:
		explicit Parser(std::string& fileName) :
			fileName_(fileName), scanner_(fileName),tokenStream_() {}
		

	private:
		const std::string fileName_;
		Scanner scanner_;
		 std::deque<Token> tokenStream_;
	};


}

#endif
