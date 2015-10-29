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
		if (currentChar_=='0')
		{
			if (PeekChar() == 'x')
			{
				AddToBuffer(currentChar_);
				GetNextChar();
				AddToBuffer(currentChar_);
				GetNextChar();
				while (std::isdigit(currentChar_) || (std::tolower(currentChar_)<='f' && std::tolower(currentChar_)>='a'))
				{
					AddToBuffer(currentChar_);
					GetNextChar();
				}
				int value = std::stoi(buffer_, 0, 16);
				token_ = \
					Token(TokenType::INT,TokenValue::UNRESERVED,loc_,buffer_,value);
			}
			else
			{
				// base = 8 
			}
		}
		else
		{
			bool bfloat = false;
			while (std::isdigit(currentChar_) || currentChar_ == '.')
			{
				if (currentChar_ == '.')
					bfloat = true;
				AddToBuffer(currentChar_);
				GetNextChar();
			}
			if (bfloat)
			{
				double value = std::stod(buffer_,0);
				token_ = \
					Token(TokenType::FLOAT,TokenValue::UNRESERVED,loc_,buffer_,value);
			}
			else
			{
				int value = std::stoi(buffer_);
				token_ = \
					Token(TokenType::INT, TokenValue::UNRESERVED, loc_, buffer_, value);
			}
		}
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
		GetNextChar();
		AddToBuffer(currentChar_);
		token_ = Token(TokenType::STRING,TokenValue::UNRESERVED,loc_,buffer_,buffer_.substr(1,buffer_.length()-2));
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
