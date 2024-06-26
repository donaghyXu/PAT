#include <cstdio> 
#include <cstring>
int main() {
	char str[110], res[4];
	char numEng[10][6]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	gets(str);
	int sum = 0, count = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		sum += (str[i] - '0');
	}
	if(sum == 0) printf("%s", numEng[0]);
	while(sum != 0) {
		res[count++] = sum % 10;
		sum /= 10;
	}
	for(int i = count - 1; i >= 0; i--) {
		printf("%s",numEng[res[i]]);
		if(i != 0) printf(" ");
	}
	return 0;
}
