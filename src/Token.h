#pragma once

#include <string>

namespace MagnoCompiler {

	enum TokenType {
		IDENT,
		STRING,

		FUNCTION,

		LPAREN,
		RPAREN,
		LBRACE,
		RBRACE,
		LCURLYBRACE,
		RCURLYBRACE,
	};

	struct Token {
		TokenType type;
		std::string value;
	};

}