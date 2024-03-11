/*
 * project: formatter
 * creator: Jeslan
 * version: 01/11/2023
 */

#include <bits/stdc++.h>

const char *dirName = "testpoint";
const char *tempfileName = "_temp_.log";
const int BEGIN_INDEX = 1;
const int END_INDEX = 0;

void inputFormatter() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
}

void outputFormatter() {
	long long ans;
	scanf("%lld", &ans);
	printf("%lld\n", ans);
}

int main() {
	char filename[128];
	for(int i = BEGIN_INDEX; i <= END_INDEX; ++i) {
		sprintf(filename, "%s\\%d.in", dirName, i);
		freopen(filename, "rb", stdin);
		sprintf(filename, "%s", tempfileName);
		freopen(filename, "wb", stdout);
		
		inputFormatter();
		
		fclose(stdin);
		fclose(stdout);
		sprintf(filename, "move /Y %s %s\\%d.in", tempfileName, dirName, i);
		system(filename);
		
		sprintf(filename, "%s\\%d.out", dirName, i);
		freopen(filename, "rb", stdin);
		sprintf(filename, "%s", tempfileName);
		freopen(filename, "wb", stdout);
		
		outputFormatter();
		
		fclose(stdin);
		fclose(stdout);
		sprintf(filename, "move /Y %s %s\\%d.out", tempfileName, dirName, i);
		system(filename);
	}
	return 0;
}
