#include "Dictionary.h"

namespace CppParser
{
	Dictionary::Dictionary()
	{
	}

	bool Dictionary::HaveToken(const std::string& name)
	{
		auto it = dict_.find(name);
		if (it == dict_.end())
			return false;
		return true;
	}

	void Dictionary::AddToken(const std::string& name, TokenType type,
		TokenValue value, int symbolPrecedence)
	{
		dict_.insert(std::make_pair(name,std::make_tuple(type,value,symbolPrecedence)));
	}
}