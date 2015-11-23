#ifndef TYPE_H
#define TYPE_H

#include "ASTtools.h"

namespace CppParser
{
	class Type
	{
	public:
		enum class TypeClass
		{
			BuiltinTypeClass,
			PointerTypeClass,
			LValueReferenceTypeClass,
			RValueReferenceTypeClass,
			ArrayTypeClass,
			FunctionTypeClass,
			TypedefTypeClass,
			ElaboratedType
		};
	public:
		virtual TypeClass getType() = 0;
		virtual ~Type() = 0;
	};

	class BuiltinType : public Type
	{
	public:
		enum class BuiltinTypeClass
		{
			Int,
			Char,
			Float,
			Bool
		};

		BuiltinType(BuiltinTypeClass builtinTypeClass) :
			builtinTypeClass_(builtinTypeClass) {}

	private:
		BuiltinTypeClass builtinTypeClass_;
	};

	class PointerType : public Type
	{
	public:

	private:

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

	class TypeWithKeyword : public Type
	{

	};

	class TypedefType : public TypeWithKeyword
	{

	};

	class ElaboratedType : public TypeWithKeyword
	{

	};
}

#endif
