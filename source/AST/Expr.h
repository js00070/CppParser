#ifndef EXPR_H
#define EXPR_H

#include "Stmt.h"

namespace CppParser
{
	class Expr : public Stmt
	{
	public:
		enum class ExprClass
		{
			DeclRefExprClass,
			PredefinedExprClass,
			IntegerLiteralClass,
			CharacterLiteralClass,
			FloatingLiteral,
			StringLiteral,
			EnumConstantExprClass,
			ParenExprClass,
			UnaryOperatorClass,
			ArraySubscriptExprClass,
			CallExprClass,
			MemberExprClass,
			CastExprClass,
			BinaryOperatorClass
		};
	public:
		Expr() :
			Stmt(Stmt::StmtClass::ExprClass) {}

		Expr(ExprClass exprClass) :
			Stmt(Stmt::StmtClass::ExprClass),
			exprClass_(exprClass) {}

		ExprClass getExprClass()
		{
			return exprClass_;
		}

	private:
		ExprClass exprClass_;
	};

	class DeclRefExpr : public Expr
	{
	public:
		DeclRefExpr() :
			Expr(Expr::ExprClass::DeclRefExprClass) {}
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
