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

}

#endif
