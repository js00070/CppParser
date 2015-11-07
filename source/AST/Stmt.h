#ifndef STMT_H
#define STMT_H

#include "AST.h"
#include "Decl.h"
#include "Expr.h"
#include <memory>

namespace CppParser
{
	class Stmt
	{
	public:
		enum class StmtClass
		{
			NoneClass,
			ExprClass,
			DeclStmtClass,
			NullStmtClass,
			CompoundStmtClass,
			SwitchStmtClass,
			SwitchCaseClass,
			IfStmtClass,
			WhileStmtClass,
			ForStmtClass,
			ContinueStmtClass,
			BreakStmtClass,
			ReturnStmtClass
		};
	protected:
		StmtClass stmtClass_;
	public:
		Stmt(StmtClass stmtClass) : stmtClass_(stmtClass) {}
		
		StmtClass getStmtClass() const
		{
			return stmtClass_;
		}


	
	};

	class DeclStmt : public Stmt
	{
	public:
		
	protected:
		std::unique_ptr<Decl> declaration_;
		
	};

	class NullStmt : public Stmt
	{

	};
}

#endif
