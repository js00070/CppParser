#ifndef GRAMMAR_H
#define GRAMMAR_H

namespace CppParser
{
	/*
	expr           : or_expr
					 postfix_expr assign_operator or_expr
					 unary_operator postfix_expr assign_operator or_expr

	assign_operator: =
					 *=
					 /=
					 %=
					 +=
					 -=

	or_expr        : and_expr
					 or_expr || and_expr

	and_expr       : equal_expr
					 and_expr && equal_expr

	equal_expr     : relation_expr
					 equal_expr == relation_expr
					 equal_expr != relation_expr

	relation_expr  : relation_expr < add_expr
					 relation_expr > add_expr
					 relation_expr <= add_expr
					 relation_expr >= add_expr

	add_expr       : mult_expr
					 add_expr + mult_expr
					 add_expr - mult_expr

	mult_expr      : cast_expr
					 mult_expr * cast_expr
					 mult_expr / cast_expr
					 mult_expr % cast_expr

	cast_expr      : unary_expr
					 (type_id) cast_expr

	unary_expr     : postfix_expr
					 unary_operator cast_expr
					 new_expr
					 delete_expr

	unary_operator : ++
					 --
					 *
					 &
					 +
					 -
					 !
					 ~

	postfix_expr   : primary_expr
					 postfix_expr [ expr ]
					 postfix_expr ( expr_list )
					 postfix_expr (  )
					 postfix_expr . id_expr
					 postfix_expr -> id_expr
					 postfix_expr ++
					 postfix_expr --

	primary_expr   : literal
					 this
					 (expr)
					 id_expr

	id_expr        : unqualified_id
					 qualified_id

	unqualified_id : identifier
					 // more

	qualified_id   : name_specifier unqualified_id

	name_specifier : type_name::
					 namespace_name::

	expr_list      : expr_list , expr
					 expr

	*/

}

#endif