#ifndef STMT_H
#define STMT_H

#include <memory>
#include "ASTtools.h"

namespace CppParser
{
	class Stmt;
	class Expr;
	class Decl;

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
		SourceLocation sourceLocation_;
	public:
		Stmt() : stmtClass_(StmtClass::NoneClass) {}
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

	class CompoundStmt : public Stmt
	{

	};

	class SwitchStmt : public Stmt
	{

	};

	class SwitchCase : public Stmt
	{

	};

	class CaseStmt : public SwitchCase
	{

	};

	class DefaultStmt : public SwitchCase
	{

	};

	class IfStmt : public Stmt
	{

	};

	class WhileStmt : public Stmt
	{

	};

	class ForStmt : public Stmt
	{

	};

	class ContinueStmt : public Stmt
	{

	};

	class BreakStmt : public Stmt
	{

	};

	class ReturnStmt : public Stmt
	{

	};
}

#endif
