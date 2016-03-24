#include <cstdio>
#include <cstring>

const int MAXN = 220 + 1;

int n;
char list[MAXN];

inline bool isValid() {
	if (list[0] == '@' || list[n - 1] == '@') return false;
	for (int i = 1; i < n; i++) {
		if (list[i - 1] == '@' && list[i] == '@') return false;
	}
	for (int i = 1; i < n - 1; i++) {
		if (list[i - 1] == '@' && list[i] != '@' && list[i + 1] == '@') return false;
	}
	for (int i = 0; i < n; i++) {
		if (list[i] == '@') return true;
	}
	return false;
}

int main() {
	scanf("%s", list);
	n = (int)strlen(list);
	if (!isValid()) puts("No solution");
	else {
		int first, last;
		for (first = 0; first < n; first++) {
			if (list[first] == '@') break;
		}
		for (last = n - 1; last >= 0; last--) {
			if (list[last] == '@') break;
		}
		int i;
		for (i = 0; i <= first; i++) putchar(list[i]);
//printf("i = %d\n", i);
		while (true) {
			if (i >= last) {
				while (i < n) putchar(list[i++]);
				break;
			}
			putchar(list[i++]);
			putchar(',');
			while (list[i] != '@') putchar(list[i++]);
			putchar(list[i++]);
		}
		putchar('\n');
	}
}