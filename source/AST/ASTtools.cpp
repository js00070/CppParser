#include "ASTtools.h"

namespace CppParser
{
	std::string SourceLocation::toString() const
	{
		return std::string \
			("(" + std::to_string(line_) + ":" \
				+ std::to_string(row_) + ")" \
				 + " at " + fileName_);
	}


}