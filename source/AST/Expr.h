#ifndef EXPR_H
#define EXPR_H

#include "Stmt.h"

namespace CppParser
{
	class Expr : public Stmt
	{
	public:
		
	public:
		Expr() :
			Stmt(Stmt::StmtClass::ExprClass) ,isCompileConstant_(false)
			,isMerged_(false) {}
		
		bool isCompileConstant()
		{
			if (isMerged_)
				return isCompileConstant_;
			else
				mergeCompileConstant();
		}
		
		virtual void mergeCompileConstant() = 0;

	protected:
		bool isCompileConstant_;
		bool isMerged_;
	};

	class DeclRefExpr : public Expr
	{
	public:
		DeclRefExpr() = default;
	};

	class PredefinedExpr : public Expr
	{

	};

	class IntegerLiteral : public Expr
	{

	};

	class CharacterLiteral : public Expr
	{

	};

	class FloatingLiteral : public Expr
	{

	};

	class StringLiteral : public Expr
	{

	};



	class ParenExpr : public Expr
	{

	};

	class UnaryOperator : public Expr
	{

	};

	class ArraySubscriptExpr : public Expr
	{

	};

	class CallExpr : public Expr
	{

	};

	class MemberExpr : public Expr
	{

	};

	class CastExpr : public Expr
	{

	};

	class ImplicitCastExpr : public CastExpr
	{

	};

	class ExplicitCastExpr : public CastExpr
	{

	};

	class BinaryOperator : public Expr
	{

	};

}

#endif
