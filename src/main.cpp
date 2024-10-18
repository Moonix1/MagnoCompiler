#include <iostream>
#include <stdlib.h>

static void usage(char *program) {
	std::cout << "Usage: " << program << " <Subcommand> <Args>" << std::endl;
	std::cout << "[SUBCOMMANDS]" << std::endl;
	std::cout << "  - build =  Compiles the program" << std::endl;
	std::cout << "    - <input>" << std::endl;
	std::cout << "    - <output>" << std::endl;
	std::cout << "  - run   =  Compiles & Runs the program" << std::endl;
	std::cout << "    - <input>" << std::endl;
	std::cout << "    - <output>" << std::endl << std::endl;
	std::cout << "  - help  =  Literally just prints this" << std::endl;
}

static char *shift(int &argc, char ***argv) {
	char *result = **argv;
	*argv += 1;
	argc += 1;
	return result;
}

int main(int argc, char **argv) {
	char *program = shift(argc, &argv);
	if (argc < 3) {
		usage(program);
		exit(1);
	}

	char *subcommand = shift(argc, &argv);
	if (subcommand == "build") {
	} else if (subcommand == "run") {
	} else {
		usage(program);
		std::cout << "[Error]: ";
		exit(1);
	}
}