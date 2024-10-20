#include "Lexer.h"
#include "Log/Log.h"

namespace MagnoCompiler {
	
	std::vector<Token> Lexer::LexSource(const std::string& source) {
		m_Input = source;
		m_Pos = 0;

		std::vector<Token> tokens;
		while (m_Pos < m_Input.size()) {
			tokens.push_back(FetchToken());
		}

		std::unordered_map<TokenType, std::string> tokenTypeToString = {
			{ TokenType::NAME, "name" },
			{ TokenType::STRING, "string" },
			{ TokenType::LPAREN, "lparen" },
			{ TokenType::RPAREN, "rparen" },
			{ TokenType::LBRACE, "lbrace" },
			{ TokenType::RBRACE, "rbrace" },
			{ TokenType::LCURLYBRACE, "lcurlybrace" },
			{ TokenType::RCURLYBRACE, "rcurlybrace" },
		};

		for (Token &tok : tokens) {
			INFO("{0} -> {1}", tokenTypeToString[tok.type], tok.value);
		}

		return tokens;
	}

	Token Lexer::FetchToken() {
		while (m_Pos < m_Input.size()) {
			char current = m_Input[m_Pos];
			if (std::isspace(current)) { m_Pos++; continue; }

			if (std::isalpha(current)) {
				return LexName();
			}

			switch (current) {
			case '"': return LexString();
			case '(': m_Pos++; return { .type = LPAREN, .value = std::string(1, current) };
			case ')': m_Pos++; return { .type = RPAREN, .value = std::string(1, current) };
			case '[': m_Pos++; return { .type = LBRACE, .value = std::string(1, current) };
			case ']': m_Pos++; return { .type = RBRACE, .value = std::string(1, current) };
			case '{': m_Pos++; return { .type = LCURLYBRACE, .value = std::string(1, current) };
			case '}': m_Pos++; return { .type = RCURLYBRACE, .value = std::string(1, current) };
			}

			m_Pos++;
		}
	}

	Token Lexer::LexName() {
		int start = m_Pos;
		while (m_Pos < m_Input.size() && std::isalnum(m_Input[m_Pos])) { m_Pos++; }
		std::string value = m_Input.substr(start, m_Pos - start);

		return { .type = NAME, .value = value };
	}

	Token Lexer::LexString() {
		m_Pos++;
		int start = m_Pos;
		while (m_Pos < m_Input.size() && m_Input[m_Pos] != '"') { m_Pos++; }
		std::string value = m_Input.substr(start, m_Pos - start);
		m_Pos++;

		return { .type = STRING, .value = value };
	}

}