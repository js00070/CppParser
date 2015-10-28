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
				Preprocess();
				if (input_.eof())
					state_ = State::END_OF_FILE;
				else
				{
					if (std::isalpha(currentChar_))
						state_ = State::IDENTIFIER;
					else
					{
						if (std::isdigit(currentChar_))
							state_ = State::NUMBER;
						else
						{
							if (currentChar_ == '\"')
								state_ = State::STRING;
							else
								state_ = State::OPERATION;
						}
					}
				}
				break;
			case State::END_OF_FILE:
				HandleEOFState();
				break;
			case State::IDENTIFIER:
				HandleIdentifierState();
				break;
			case State::NUMBER:
				HandleNumberState();
				break;
			case State::OPERATION:
				HandleOperationState();
				break;
			case State::STRING:
				HandleStringState();
				break;
			default:
				break;
			}

		} while (!matched);
	}

	inline void Scanner::HandleIdentifierState()
	{
		loc_ = GetTokenLocation();
		while (std::isalnum(currentChar_) || currentChar_ == '_')
		{
			AddToBuffer(currentChar_);
			GetNextChar();
		}
		auto tokenInfo = dictionary_.LookUp(buffer_);
		token_ = Token(std::get<0>(tokenInfo),std::get<1>(tokenInfo),loc_,buffer_);
	}

	inline void Scanner::HandleNumberState()
	{
		loc_ = GetTokenLocation();

	}

	inline void Scanner::HandleOperationState()
	{
		loc_ = GetTokenLocation();
		while (!(std::isalnum(currentChar_) || std::isspace(currentChar_)))
		{
			AddToBuffer(currentChar_);
			GetNextChar();
		}
		auto tokenInfo = dictionary_.LookUp(buffer_);
		token_ = Token(std::get<0>(tokenInfo), std::get<1>(tokenInfo), loc_, buffer_);
	}

	inline void Scanner::HandleStringState()
	{
		loc_ = GetTokenLocation();
		while (PeekChar() != '\"')
		{
			AddToBuffer(currentChar_);
			GetNextChar();
		}
	}

	inline void Scanner::HandleDigit()
	{

	}

	inline Token Scanner::GetToken() const
	{
		return token_;
	}

	inline bool Scanner::GetErrorFlag()
	{
		return errorFlag_;
	}

	inline TokenLocation Scanner::GetTokenLocation() const
	{
		return TokenLocation(fileName_,line_,column_);
	}
}
