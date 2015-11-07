#ifndef TYPE_H
#define TYPE_H

#include "ASTtools.h"

namespace CppParser
{
	class Qualifiers
	{

	};

	class QualType
	{

	};

	class Type
	{

	};

	class BuiltinType : public Type
	{

	};

	class PointerType : public Type
	{

	};

	class ReferenceType : public Type
	{

	};

	class LValueReferenceType : public ReferenceType
	{

	};

	class RValueReferenceType : public ReferenceType
	{

	};

	class ArrayType : public Type
	{

	};

	class ConstantArrayType : public ArrayType
	{

	};

	class IncompleteArrayType : public ArrayType
	{

	};

	class VariableArrayType : public ArrayType
	{

	};

	class FunctionType : public Type
	{

	};

	class FunctionNoProtoType : public FunctionType
	{

	};

	class FunctionProtoType : public FunctionType
	{

	};

	class TypedefType : public Type
	{

	};

	class TypeWithKeyword : public Type
	{

	};

	class ElaboratedType : public TypeWithKeyword
	{

	};
}

#endif
