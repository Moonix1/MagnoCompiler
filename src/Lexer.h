#pragma once

#include <vector>

#include "Token.h"

namespace MagnoCompiler {

	class Lexer {
	public:
		std::vector<Token> LexSource(const std::string &source);
	private:
		Token FetchToken();

		Token LexKI();
		Token LexString();
	private:
		std::string m_Input;
		int m_Pos;
	};

}