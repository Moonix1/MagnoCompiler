#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "Log/Log.h"

#include "Lexer.h"

static std::string GetFileContents(std::string path) {
	std::ifstream file(path);
	
	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

static void Usage(std::string program) {
	WARN("Usage: {0} <Subcommand> <Args>", program);
	std::cout << "[SUBCOMMANDS]" << std::endl;
	std::cout << "  - build =  Compiles the program" << std::endl;
	std::cout << "    - <input>" << std::endl;
	std::cout << "    - <output>" << std::endl;
	std::cout << "  - run   =  Compiles & Runs the program" << std::endl;
	std::cout << "    - <input>" << std::endl;
	std::cout << "    - <output>" << std::endl << std::endl;
	std::cout << "  - help  =  Literally just prints this" << std::endl;
}

static char *Shift(int &argc, char ***argv) {
	char *result = **argv;
	*argv += 1;
	argc += 1;
	return result;
}

int main(int argc, char **argv) {
	MagnoCompiler::Log::Init();

	std::string program = Shift(argc, &argv);
	if (argc < 3) {
		Usage(program);
		exit(1);
	}

	std::string subcommand = Shift(argc, &argv);
	if (subcommand == "build" || subcommand == "run") {
		char *input = Shift(argc, &argv);
		char *output = Shift(argc, &argv);
		MagnoCompiler::Lexer lexer;
		lexer.LexSource(GetFileContents(input));
	} else if (subcommand == "help") {
		Usage(program);
		exit(0);
	} else {
		Usage(program);
		ERROR("Invalid subcommand: {0}", subcommand);
		exit(1);
	}
}