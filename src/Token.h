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
		COLON,
		SEMICOLON,
	};

	struct Token {
		TokenType type;
		std::string value;
	};

}