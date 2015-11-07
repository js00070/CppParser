#ifndef DECL_H
#define DECL_H

namespace CppParser
{
	class Decl
	{
	public:
	protected:
	};

	class NameDecl : public Decl
	{

	};

	class NamespaceDecl : public NameDecl
	{

	};

	class VarDecl : public NameDecl
	{

	};

	class ParmVarDecl : public VarDecl
	{

	};

	class FunctionDecl : public NameDecl
	{

	};

	class EnumConstantDecl : public NameDecl
	{

	};

	class TypeDecl : public NameDecl
	{

	};

	class TypedefDecl : public TypeDecl
	{

	};

	class TagDecl : public TypeDecl
	{

	};

	class EnumDecl : public TagDecl
	{

	};

	class RecordDecl : public TagDecl
	{

	};
}

#endif
