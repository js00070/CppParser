#ifndef PARSER_H
#define PARSER_H

#include "Basic.h"
#include "Scanner.h"

namespace CppParser
{
	class ExprAST // Base class for all expression nodes
	{
	public:
		virtual ~ExprAST() {}
	};



	class Parser : public zl::Interface
	{
	public:

	private:
		
	};


}

#endif
