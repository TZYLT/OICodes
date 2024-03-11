/*
 * project: checker
 * creator: Jeslan
 * version: 01/01/2024
 */

#include <bits/stdc++.h>

#define USING_CPP_IOS

void WA(int _wa_on_number_x);
void WA(const char *format, ...);
void AC(int _x_number_matched);
void AC(const char *format, ...);

#ifdef USING_CPP_IOS
void cmp(std::ifstream &fin, std::ifstream &fout, std::ifstream &fans)
#else
void cmp(FILE* &fin, FILE* &fout, FILE* &fans)
#endif
{
	int cnt = 0;
	std::string out, ans;
	while(fans >> ans) {
		cnt++;
		if(!(fout >> out) || out != ans) {
			WA(cnt);
			return;
		}
	}
	if(fout >> out) {
		WA("\033[31mWrong answer\033[0m. Output is too long.\n");
		return;
	}
	AC(cnt);
	return;
}

int main(int argc, char **argv)
{
	#ifdef USING_CPP_IOS
	
	std::ifstream fin(argv[1], std::ios::in|std::ios::binary);
	std::ifstream fout(argv[2], std::ios::in|std::ios::binary);
	std::ifstream fans(argv[3], std::ios::in|std::ios::binary);
	
	cmp(fin, fout, fans);
	
	fin.close();
	fout.close();
	fans.close();
	
	#else
	
	FILE *fin = fopen(argv[1], "rb");
	FILE *fout = fopen(argv[2], "rb");
	FILE *fans = fopen(argv[3], "rb");
	
	cmp(fin, fout, fans);
	
	fclose(fin);
	fclose(fout);
	fclose(fans);
	
	#endif
	
	return 0;
}

void WA(int _wa_on_number_x) {
	fprintf(stderr, "\033[31mWrong answer\033[0m on the %d%s number.\n",
		_wa_on_number_x,
		(_wa_on_number_x % 100 / 10 == 1) ? "th" :
			(_wa_on_number_x % 10 == 1) ? "st" :
				(_wa_on_number_x % 10 == 2) ? "nd" :
					(_wa_on_number_x % 10 == 3) ? "rd" : "th"
	);
}

void WA(const char *format, ...) {
	va_list vlist;
	va_start(vlist, format);
	vfprintf(stderr, format, vlist);
	va_end(vlist);
}

void AC(int _x_number_matched) {
	fprintf(stderr, "\033[32mAccepted\033[0m. %d numbers matched.\n",
		_x_number_matched
	);
}

void AC(const char *format, ...) {
	va_list vlist;
	va_start(vlist, format);
	vfprintf(stderr, format, vlist);
	va_end(vlist);
}
