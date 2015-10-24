#include "Scanner.h"

namespace CppParser
{
	Scanner::Scanner(const std::string & srcFileName)
	{
	}
	inline Token Scanner::GetToken() const
	{
		return Token();
	}
	inline Token Scanner::GetNextToken()
	{
		return Token();
	}
	inline bool Scanner::GetErrorFlag()
	{
		return false;
	}
}