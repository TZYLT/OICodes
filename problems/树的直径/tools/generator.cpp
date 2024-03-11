#include "generator.h"

const int TESTPOINT_BEGIN = 1;
const int TESTPOINT_END = 2;
const char *SOLUTION_EXE = "solution.exe";
const std::vector<std::string> ALT_SOL_EXE = {"bf.exe", "wa.exe"};
const char *CHECKER_EXE = "checker.exe";
const char *TESTPOINT_DIR = "testpoint";
const char *ALT_SOL_OUTPUT_DIR = "alt_sol_output";
const bool DO_GENERATE = 1;
const bool RUN_SOLUTION = 0;
const bool RUN_ALT_SOL = 0;
const bool DO_CHECK = 0;

void gen(int tp) {
	printf("Hello World!\n");
}

int main() {
	main_interact(gen);
	return 0;
}
