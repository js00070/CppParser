#ifndef EXPR_H
#define EXPR_H

#include "Stmt.h"

namespace CppParser
{
	class Expr : public Stmt
	{
	public:
		
	public:
	protected:

	};

	class DeclRefExpr : public Expr
	{

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
