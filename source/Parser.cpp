#include "Parser.h"

namespace CppParser
{
	Parser::Parser(std::string & fileName) :
		fileName_(fileName),scanner_(fileName)
	{}


}