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
	  TypedefNameDecl
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
    ConstantArrayType
    IncompleteArrayType
	VariableArrayType
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


namespace CppParser
{
	
}