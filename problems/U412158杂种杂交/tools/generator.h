#ifndef _GENERATOR_H
#define _GENERATOR_H "generator.h v2.3 04/01/2024"

#include <bits/stdc++.h>

std::default_random_engine dre (
	std::chrono::duration_cast<std::chrono::nanoseconds>
	(std::chrono::system_clock::now().time_since_epoch()).count()
);

extern const int TESTPOINT_BEGIN;
extern const int TESTPOINT_END;
extern const char *SOLUTION_EXE;
extern const std::vector<std::string> ALT_SOL_EXE;
extern const char *CHECKER_EXE;
extern const char *TESTPOINT_DIR;
extern const char *ALT_SOL_OUTPUT_DIR;
extern const bool DO_GENERATE;
extern const bool RUN_SOLUTION;
extern const bool RUN_ALT_SOL;
extern const bool DO_CHECK;

clock_t main_solve (
	std::string in_file,
	std::string out_file,
	std::string sol_cmd
) {
	freopen(in_file.c_str(), "rb", stdin);
	freopen(out_file.c_str(), "wb", stdout);
	
	clock_t time_begin = clock();
	system(sol_cmd.c_str());
	clock_t time_used = clock() - time_begin;
	
	fclose(stdin);
	fclose(stdout);
	
	return time_used;
}

void main_interact (
	void (*generator)(int)
) {
	if(RUN_SOLUTION) {
		system((std::string() + "IF NOT EXIST " + TESTPOINT_DIR + " MKDIR " + TESTPOINT_DIR).c_str());
	}
	
	if(ALT_SOL_EXE.size()) {
		system((std::string() + "IF NOT EXIST " + ALT_SOL_OUTPUT_DIR + " MKDIR " + ALT_SOL_OUTPUT_DIR).c_str());
	}
	
	for(int tp = TESTPOINT_BEGIN; tp <= TESTPOINT_END; ++tp) {
		std::string in_file = std::string() + TESTPOINT_DIR + "\\" + std::to_string(tp) + ".in";
		std::string out_file = std::string() + TESTPOINT_DIR + "\\" + std::to_string(tp) + ".out";
		
		if(DO_GENERATE && generator) {
			freopen(in_file.c_str(), "wb", stdout);
			generator(tp);
			fclose(stdout);
		} // DO_GENERATE
		
		if(RUN_SOLUTION && SOLUTION_EXE) {
			clock_t time_used = main_solve(in_file, out_file, SOLUTION_EXE);
			fprintf(stderr, "testpoint %d: %ld ms\n", tp, time_used);
		} // SOLUTION_EXE
		
		if(RUN_ALT_SOL) {
			for(int idx = 0; idx < ALT_SOL_EXE.size(); idx++) {
				std::string out_file_another = std::string() + ALT_SOL_OUTPUT_DIR + "\\" + std::to_string(tp) + "_" + std::to_string(idx) + ".out";
				
				clock_t time_used = main_solve(in_file, out_file_another, ALT_SOL_EXE[idx]);
				fprintf(stderr, "testpoint %d: %ld ms\n", tp, time_used);
				
				if(DO_CHECK && CHECKER_EXE) {
					system((std::string() + CHECKER_EXE + " " + in_file + " " + out_file_another + " " + out_file).c_str());
				} // DO_CHECK
			} // ALT_SOL_EXE vector
		} // RUN_ALT_SOL
		
		fprintf(stderr, "\n");
	} // main loop
}

template<typename Type,
	typename = typename std::enable_if<std::is_integral<Type>::value>::type>
Type rand_integer(const Type &min, const Type &max) {
	std::uniform_int_distribution<Type> rndev(min, max);
	return rndev(dre);
}

template<typename Type,
	typename = typename std::enable_if<std::is_floating_point<Type>::value>::type>
Type rand_real(const Type &min, const Type &max) {
	std::uniform_real_distribution<Type> rndev(min, max);
	return rndev(dre);
}

int rand(int l, int r) { return rand_integer(l, r); }
long long rand(long long l, long long r) { return rand_integer(l, r); }
double rand(double l, double r) { return rand_real(l, r); }

#endif
