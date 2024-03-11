#include "generator.h"

const int TESTPOINT_BEGIN = 1;
const int TESTPOINT_END = 20;
const char *SOLUTION_EXE = "sol.exe";
const std::vector<std::string> ALT_SOL_EXE = {};
const char *CHECKER_EXE = "checker.exe";
const char *TESTPOINT_DIR = "testpoint";
const char *ALT_SOL_OUTPUT_DIR = "alt_sol_output";
const bool DO_GENERATE = 1;
const bool RUN_SOLUTION = 1;
const bool RUN_ALT_SOL = 0;
const bool DO_CHECK = 0;

void gen(int tp) {
	int n=rand_integer(100000000000000000,1000000000000000000);
	int k=rand_integer(1,n);
	printf("%d %d\n",n,k);
}

int main() {
	main_interact(gen);
	return 0;
}
