/*
Class definitions:

Stmt
  Expr
    DeclRefExpr // reference to a declared variable
    PredefinedExpr // such as __func__
    IntegerLiteral
    CharacterLiteral
    FloatingLiteral
    StringLiteral
    ParenExpr // (1)
	UnaryOperator
	OffsetOfExpr // ?
	ArraySubscriptExpr
	CallExpr
	MemberExpr // X->F and X.F
    CastExpr
	  ImplicitCastExpr
	  ExplicitCastExpr
	BinaryOperator
	  CompoundAssignOperator // +=

  DeclStmt // Declaration mixed with Statement
  NullStmt
  CompoundStmt
  SwitchCase
    CaseStmt
    DefaultStmt
  IfStmt
  SwitchStmt
  WhileStmt
  ForStmt
  ContinueStmt
  BreakStmt
  ReturnStmt
  AsmStmt // 

Decl
  NameDecl
    NamespaceDecl
	VarDecl
	  ParmVarDecl
	FunctionDecl
	FieldDecl
	EnumConstantDecl
	TypeDecl
//	  TypedefNameDecl
	  TypedefDecl
	  TagDecl // struct/union/class/enum
	    EnumDecl
		RecordDecl // struct/union/class


Qualifiers // const, volatile, restrict
QualType
Type
  BuiltinType
  PointerType
  ReferenceType
    LValueReferenceType
	RValueReferenceType //
  ArrayType
    ConstantArrayType // int A[10]
    IncompleteArrayType // int A[]
	VariableArrayType // int A[n]
	DependentSizedArrayType // used in template
  FunctionType
    FunctionNoProtoType // int func()
	FunctionProtoType // int func(void)
	UnresolvedUsingType // used in template
  TypedefType
  TypeWithKeyword
    ElaboratedType
	...


*/
#ifndef AST_H
#define AST_H

#include "Stmt.h"
#include "Expr.h"
#include "Decl.h"

namespace CppParser
{
	
}

#endif