#ifndef dupr_AST_VISITOR_DEAMER_VISITOR_H
#define dupr_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "dupr/Ast/Node/dupr.h"
#include "dupr/Ast/Enum/Type.h"
#include "dupr/Ast/Node/LEFT_BRACKET.h"
#include "dupr/Ast/Node/RIGHT_BRACKET.h"
#include "dupr/Ast/Node/LEFT_PARANTHESIS.h"
#include "dupr/Ast/Node/RIGHT_PARANTHESIS.h"
#include "dupr/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "dupr/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "dupr/Ast/Node/ADD.h"
#include "dupr/Ast/Node/MINUS.h"
#include "dupr/Ast/Node/MULTI.h"
#include "dupr/Ast/Node/DIVIDE.h"
#include "dupr/Ast/Node/LT.h"
#include "dupr/Ast/Node/LE.h"
#include "dupr/Ast/Node/GT.h"
#include "dupr/Ast/Node/GE.h"
#include "dupr/Ast/Node/EQ.h"
#include "dupr/Ast/Node/DOT.h"
#include "dupr/Ast/Node/COMMA.h"
#include "dupr/Ast/Node/COLON.h"
#include "dupr/Ast/Node/SEMICOLON.h"
#include "dupr/Ast/Node/PATTERN_INSERTION.h"
#include "dupr/Ast/Node/VARNAME.h"
#include "dupr/Ast/Node/NUMBER.h"
#include "dupr/Ast/Node/DECIMAL.h"
#include "dupr/Ast/Node/ESCAPE_CHARS.h"

#include "dupr/Ast/Node/program.h"
#include "dupr/Ast/Node/deamerreserved_star__stmt__.h"
#include "dupr/Ast/Node/stmt.h"
#include "dupr/Ast/Node/pattern_execution.h"
#include "dupr/Ast/Node/pattern_execution_content.h"
#include "dupr/Ast/Node/deamerreserved_plus__pattern_execution_content_stmt__.h"
#include "dupr/Ast/Node/pattern_execution_content_stmt.h"
#include "dupr/Ast/Node/pattern_constructor.h"
#include "dupr/Ast/Node/pattern_type.h"
#include "dupr/Ast/Node/pattern_name.h"
#include "dupr/Ast/Node/pattern_constructor_content.h"
#include "dupr/Ast/Node/deamerreserved_plus__pattern_constructor_content_stmt__.h"
#include "dupr/Ast/Node/pattern_constructor_content_stmt.h"
#include "dupr/Ast/Node/pattern_constructor_operator.h"
#include "dupr/Ast/Node/pattern_constructor_structure.h"
#include "dupr/Ast/Node/pattern_constructor_terminate.h"
#include "dupr/Ast/Node/pattern_constructor_encapsulation.h"

namespace dupr { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<dupr::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case dupr::ast::Type::LEFT_BRACKET:
			{
				Visit(static_cast<const dupr::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case dupr::ast::Type::RIGHT_BRACKET:
			{
				Visit(static_cast<const dupr::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case dupr::ast::Type::LEFT_PARANTHESIS:
			{
				Visit(static_cast<const dupr::ast::node::LEFT_PARANTHESIS*>(node));
				break;
			}
			case dupr::ast::Type::RIGHT_PARANTHESIS:
			{
				Visit(static_cast<const dupr::ast::node::RIGHT_PARANTHESIS*>(node));
				break;
			}
			case dupr::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Visit(static_cast<const dupr::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case dupr::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Visit(static_cast<const dupr::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case dupr::ast::Type::ADD:
			{
				Visit(static_cast<const dupr::ast::node::ADD*>(node));
				break;
			}
			case dupr::ast::Type::MINUS:
			{
				Visit(static_cast<const dupr::ast::node::MINUS*>(node));
				break;
			}
			case dupr::ast::Type::MULTI:
			{
				Visit(static_cast<const dupr::ast::node::MULTI*>(node));
				break;
			}
			case dupr::ast::Type::DIVIDE:
			{
				Visit(static_cast<const dupr::ast::node::DIVIDE*>(node));
				break;
			}
			case dupr::ast::Type::LT:
			{
				Visit(static_cast<const dupr::ast::node::LT*>(node));
				break;
			}
			case dupr::ast::Type::LE:
			{
				Visit(static_cast<const dupr::ast::node::LE*>(node));
				break;
			}
			case dupr::ast::Type::GT:
			{
				Visit(static_cast<const dupr::ast::node::GT*>(node));
				break;
			}
			case dupr::ast::Type::GE:
			{
				Visit(static_cast<const dupr::ast::node::GE*>(node));
				break;
			}
			case dupr::ast::Type::EQ:
			{
				Visit(static_cast<const dupr::ast::node::EQ*>(node));
				break;
			}
			case dupr::ast::Type::DOT:
			{
				Visit(static_cast<const dupr::ast::node::DOT*>(node));
				break;
			}
			case dupr::ast::Type::COMMA:
			{
				Visit(static_cast<const dupr::ast::node::COMMA*>(node));
				break;
			}
			case dupr::ast::Type::COLON:
			{
				Visit(static_cast<const dupr::ast::node::COLON*>(node));
				break;
			}
			case dupr::ast::Type::SEMICOLON:
			{
				Visit(static_cast<const dupr::ast::node::SEMICOLON*>(node));
				break;
			}
			case dupr::ast::Type::PATTERN_INSERTION:
			{
				Visit(static_cast<const dupr::ast::node::PATTERN_INSERTION*>(node));
				break;
			}
			case dupr::ast::Type::VARNAME:
			{
				Visit(static_cast<const dupr::ast::node::VARNAME*>(node));
				break;
			}
			case dupr::ast::Type::NUMBER:
			{
				Visit(static_cast<const dupr::ast::node::NUMBER*>(node));
				break;
			}
			case dupr::ast::Type::DECIMAL:
			{
				Visit(static_cast<const dupr::ast::node::DECIMAL*>(node));
				break;
			}
			case dupr::ast::Type::ESCAPE_CHARS:
			{
				Visit(static_cast<const dupr::ast::node::ESCAPE_CHARS*>(node));
				break;
			}

			case dupr::ast::Type::program:
			{
				Visit(static_cast<const dupr::ast::node::program*>(node));
				break;
			}
			case dupr::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const dupr::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case dupr::ast::Type::stmt:
			{
				Visit(static_cast<const dupr::ast::node::stmt*>(node));
				break;
			}
			case dupr::ast::Type::pattern_execution:
			{
				Visit(static_cast<const dupr::ast::node::pattern_execution*>(node));
				break;
			}
			case dupr::ast::Type::pattern_execution_content:
			{
				Visit(static_cast<const dupr::ast::node::pattern_execution_content*>(node));
				break;
			}
			case dupr::ast::Type::deamerreserved_plus__pattern_execution_content_stmt__:
			{
				Visit(static_cast<const dupr::ast::node::deamerreserved_plus__pattern_execution_content_stmt__*>(node));
				break;
			}
			case dupr::ast::Type::pattern_execution_content_stmt:
			{
				Visit(static_cast<const dupr::ast::node::pattern_execution_content_stmt*>(node));
				break;
			}
			case dupr::ast::Type::pattern_constructor:
			{
				Visit(static_cast<const dupr::ast::node::pattern_constructor*>(node));
				break;
			}
			case dupr::ast::Type::pattern_type:
			{
				Visit(static_cast<const dupr::ast::node::pattern_type*>(node));
				break;
			}
			case dupr::ast::Type::pattern_name:
			{
				Visit(static_cast<const dupr::ast::node::pattern_name*>(node));
				break;
			}
			case dupr::ast::Type::pattern_constructor_content:
			{
				Visit(static_cast<const dupr::ast::node::pattern_constructor_content*>(node));
				break;
			}
			case dupr::ast::Type::deamerreserved_plus__pattern_constructor_content_stmt__:
			{
				Visit(static_cast<const dupr::ast::node::deamerreserved_plus__pattern_constructor_content_stmt__*>(node));
				break;
			}
			case dupr::ast::Type::pattern_constructor_content_stmt:
			{
				Visit(static_cast<const dupr::ast::node::pattern_constructor_content_stmt*>(node));
				break;
			}
			case dupr::ast::Type::pattern_constructor_operator:
			{
				Visit(static_cast<const dupr::ast::node::pattern_constructor_operator*>(node));
				break;
			}
			case dupr::ast::Type::pattern_constructor_structure:
			{
				Visit(static_cast<const dupr::ast::node::pattern_constructor_structure*>(node));
				break;
			}
			case dupr::ast::Type::pattern_constructor_terminate:
			{
				Visit(static_cast<const dupr::ast::node::pattern_constructor_terminate*>(node));
				break;
			}
			case dupr::ast::Type::pattern_constructor_encapsulation:
			{
				Visit(static_cast<const dupr::ast::node::pattern_constructor_encapsulation*>(node));
				break;
			}
			}
		}
		virtual void Visit(const dupr::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Visit(const dupr::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Visit(const dupr::ast::node::LEFT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const dupr::ast::node::RIGHT_PARANTHESIS* node)
		{
		}
		virtual void Visit(const dupr::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const dupr::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const dupr::ast::node::ADD* node)
		{
		}
		virtual void Visit(const dupr::ast::node::MINUS* node)
		{
		}
		virtual void Visit(const dupr::ast::node::MULTI* node)
		{
		}
		virtual void Visit(const dupr::ast::node::DIVIDE* node)
		{
		}
		virtual void Visit(const dupr::ast::node::LT* node)
		{
		}
		virtual void Visit(const dupr::ast::node::LE* node)
		{
		}
		virtual void Visit(const dupr::ast::node::GT* node)
		{
		}
		virtual void Visit(const dupr::ast::node::GE* node)
		{
		}
		virtual void Visit(const dupr::ast::node::EQ* node)
		{
		}
		virtual void Visit(const dupr::ast::node::DOT* node)
		{
		}
		virtual void Visit(const dupr::ast::node::COMMA* node)
		{
		}
		virtual void Visit(const dupr::ast::node::COLON* node)
		{
		}
		virtual void Visit(const dupr::ast::node::SEMICOLON* node)
		{
		}
		virtual void Visit(const dupr::ast::node::PATTERN_INSERTION* node)
		{
		}
		virtual void Visit(const dupr::ast::node::VARNAME* node)
		{
		}
		virtual void Visit(const dupr::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const dupr::ast::node::DECIMAL* node)
		{
		}
		virtual void Visit(const dupr::ast::node::ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const dupr::ast::node::program* node)
		{
		}
		virtual void Visit(const dupr::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const dupr::ast::node::stmt* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_execution* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_execution_content* node)
		{
		}
		virtual void Visit(const dupr::ast::node::deamerreserved_plus__pattern_execution_content_stmt__* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_execution_content_stmt* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_constructor* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_type* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_name* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_constructor_content* node)
		{
		}
		virtual void Visit(const dupr::ast::node::deamerreserved_plus__pattern_constructor_content_stmt__* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_constructor_content_stmt* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_constructor_operator* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_constructor_structure* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_constructor_terminate* node)
		{
		}
		virtual void Visit(const dupr::ast::node::pattern_constructor_encapsulation* node)
		{
		}
	};

}}}

#endif // dupr_AST_VISITOR_DEAMER_VISITOR_H
