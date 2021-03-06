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
	public:
		Stmt() :
			stmtClass_(StmtClass::NoneClass) {}
		Stmt(StmtClass stmtClass) :
			stmtClass_(stmtClass) {}
		
		StmtClass getStmtClass() const
		{
			return stmtClass_;
		}
		virtual ~Stmt() {}
	protected:
		StmtClass stmtClass_;
		SourceLocation sourceLocation_;
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
		
		void addStmt(std::unique_ptr<Stmt>& pStmt)
		{
			stmtList_.emplace_back(std::move(pStmt));
		}

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
		IfStmt(std::unique_ptr<Expr> &expr,
			std::unique_ptr<Stmt> &thenBody,
			std::unique_ptr<Stmt> &elseBody) :
			Stmt(Stmt::StmtClass::IfStmtClass),
			expr_(std::move(expr)),thenBody_(std::move(thenBody)),
			elseBody_(std::move(elseBody)) {}
	protected:
		std::unique_ptr<Expr> expr_;
		std::unique_ptr<Stmt> thenBody_;
		std::unique_ptr<Stmt> elseBody_;
	};

	class WhileStmt : public Stmt
	{
	public:
		WhileStmt() :
			Stmt(Stmt::StmtClass::WhileStmtClass) {}
		WhileStmt(std::unique_ptr<Expr> &expr,std::unique_ptr<Stmt> &body) :
			Stmt(Stmt::StmtClass::WhileStmtClass), 
			expr_(std::move(expr)), body_(std::move(body)) {}
	private:
		std::unique_ptr<Expr> expr_;
		std::unique_ptr<Stmt> body_;
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
