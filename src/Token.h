#pragma once

#include <string>

namespace MagnoCompiler {

	enum TokenType {
		NAME,
		STRING,
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