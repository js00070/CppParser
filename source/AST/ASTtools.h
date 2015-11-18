#ifndef ASTTOOLS_H
#define ASTTOOLS_H

#include <string>
#include <vector>

namespace CppParser
{
	class Stmt;
	class Expr;
	class Decl;

	class SourceLocation
	{
	public:
		SourceLocation() :
			fileName_(""), line_(0), row_(0) {}
		SourceLocation(std::string fileName, int line, int row) :
			fileName_(fileName), line_(line), row_(row) {}
		std::string toString() const;
	private:
		std::string fileName_;
		int line_;
		int row_;
	};

	typedef std::vector<std::unique_ptr<Stmt>> StmtList;
	typedef std::vector<std::unique_ptr<Expr>> ExprList;
}

#endif