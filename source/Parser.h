#ifndef PARSER_H
#define PARSER_H

#include "Basic.h"
#include "Scanner.h"
#include <string>
#include "AST\AST.h"

namespace CppParser
{
	class Parser : public zl::Interface
	{
	public:
		explicit Parser(std::string& fileName);
		

	private:
		const std::string fileName_;
		Scanner scanner_;

	};


}

#endif
