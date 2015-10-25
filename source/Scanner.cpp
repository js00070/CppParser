#include "Scanner.h"
#include <cctype>

namespace CppParser
{
	Scanner::Scanner(const std::string & srcFileName) :
		fileName_(srcFileName), line_(1), column_(0),
		currentChar_(0),errorFlag_(false),
		state_(State::NONE)
	{
		input_.open(fileName_);
		if (input_.fail())
		{
			std::cerr << "Failed to open the file : " << fileName_ << std::endl;
			errorFlag_ = true;
		}
	}

	inline void Scanner::GetNextChar()
	{
		currentChar_ = input_.get();
		if (currentChar_ == '\n')
		{
			line_++;
			column_ = 0;
		}
		else
		{
			column_++;
		}
	}

	inline char Scanner::PeekChar()
	{
		char c = input_.peek();
		return c;
	}

	inline void Scanner::AddToBuffer(char c)
	{
		buffer_.push_back(c);
	}

	inline void Scanner::ReduceBuffer()
	{
		buffer_.pop_back();
	}

	inline void Scanner::MakeToken(TokenType tt, TokenValue tv,
		const TokenLocation& loc, std::string name)
	{
		token_ = Token(tt,tv,loc,name);
		buffer_.clear();
		state_ = State::NONE;
	}

	inline void Scanner::MakeToken(TokenType tt, TokenValue tv,
		const TokenLocation& loc, int intValue, std::string name)
	{
		token_ = Token(tt,tv,loc,name,intValue);
		buffer_.clear();
		state_ = State::NONE;
	}

	inline void Scanner::MakeToken(TokenType tt, TokenValue tv,
		const TokenLocation& loc, double floatValue, std::string name)
	{
		token_ = Token(tt, tv, loc, name, floatValue);
		buffer_.clear();
		state_ = State::NONE;
	}

	inline void Scanner::Preprocess()
	{
		do
		{
			while (std::isspace(currentChar_))
			{
				GetNextChar();
			}
			HandleLineComment();
			HandleBlockComment();
		} while (std::isspace(currentChar_));
	}

	Token Scanner::GetNextToken()
	{
		bool matched = false;

		do
		{
			if (state_ != State::NONE)
				matched = true;
			switch (state_)
			{
			case State::NONE:
				GetNextChar();
				break;
			case State::END_OF_FILE:
				break;
			case State::IDENTIFIER:
				break;
			case State::NUMBER:
				break;
			case State::OPERATION:
				break;
			case State::STRING:
				break;
			default:
				break;
			}

		} while (!matched);
	}

	inline Token Scanner::GetToken() const
	{
		return token_;
	}

	inline bool Scanner::GetErrorFlag()
	{
		return errorFlag_;
	}
}