#include "Scanner.h"
#include <iostream>
using namespace CppParser;

int main()
{
	Scanner scan \
		("D:\\code\\GitHubVisualStudio\\CppParser\\source\\TestText.txt");
	scan.GetNextToken();
	while (scan.GetToken().GetTokenType() != TokenType::END_OF_FILE)
	{
		scan.GetToken().Dump(std::cout);
		getchar();
		scan.GetNextToken();
	}

	return 0;
}