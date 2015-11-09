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
		Stmt() :
			stmtClass_(StmtClass::NoneClass) {}
		Stmt(StmtClass stmtClass) :
			stmtClass_(stmtClass) {}
		
		StmtClass getStmtClass() const
		{
			return stmtClass_;
		}

	};

	class DeclStmt : public Stmt
	{
	public:
		DeclStmt() :
			Stmt(Stmt::StmtClass::DeclStmtClass) {}
	protected:
		std::unique_ptr<Decl> declaration_;
		
	};

	class NullStmt : public Stmt
	{
		
	};

	class CompoundStmt : public Stmt
	{
	public:
		typedef StmtList::iterator Iterator;
	public:
		CompoundStmt() :
			Stmt(Stmt::StmtClass::CompoundStmtClass) {}
		void push_back(Stmt const* pStmt);

	protected:
		StmtList stmtList_;
	};

	class SwitchStmt : public Stmt
	{
	public:
		SwitchStmt() :
			Stmt(Stmt::StmtClass::SwitchStmtClass) {}
	};

	class SwitchCase : public Stmt
	{
	public:
		SwitchCase() :
			Stmt(Stmt::StmtClass::SwitchCaseClass) {}
	};

	class CaseStmt : public SwitchCase
	{
		
	};

	class DefaultStmt : public SwitchCase
	{

	};

	class IfStmt : public Stmt
	{
	public:
		IfStmt() :
			Stmt(Stmt::StmtClass::IfStmtClass) {}
	};

	class WhileStmt : public Stmt
	{
	public:
		WhileStmt() :
			Stmt(Stmt::StmtClass::WhileStmtClass) {}
	};

	class ForStmt : public Stmt
	{
	public:
		ForStmt() :
			Stmt(Stmt::StmtClass::ForStmtClass) {}
	};

	class ContinueStmt : public Stmt
	{
	public:
		ContinueStmt() :
			Stmt(Stmt::StmtClass::ContinueStmtClass) {}
	};

	class BreakStmt : public Stmt
	{
	public:
		BreakStmt() :
			Stmt(Stmt::StmtClass::BreakStmtClass) {}
	};

	class ReturnStmt : public Stmt
	{
	public:
		ReturnStmt() :
			Stmt(Stmt::StmtClass::ReturnStmtClass) {}
	};
}

#endif
