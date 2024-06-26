#include <cstdio>
#include <cstring>
int main() {
	char str[10010];
	gets(str);
	int pos, exp = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(str[i] == 'E')
			pos = i;
	}
	for(int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}	
	if(str[pos + 1] == '-') {
		if(str[0] == '-')	printf("-");	
		printf("0.");
		for(int i = 0; i < exp - 1; i++) {
			printf("0");
		}
		for(int i = 1; i < pos; i++) {
			if(str[i] != '.')
				printf("%c", str[i]);
		}			
	} else {
		if(str[0] == '-')	printf("-");
		if((pos - 3) == exp) {
			for(int i = 1; i < pos; i++) {
				if(str[i] != '.')
					printf("%c",str[i]);
			}
		} else if((pos - 3) < exp) {
			for(int i = 1; i < pos; i++) {
				if(str[i] != '.')
					printf("%c",str[i]);
			}
			for(int i = 0; i < exp - pos + 3; i++) {
				printf("0");
			}
		} else {
			for(int i = 1; i <= exp + 2; i++) {
				if(str[i] != '.')	printf("%c",str[i]);
			}
			printf(".");
			for(int i = exp + 3; i < pos; i++) {
				printf("%c", str[i]);
			}
		}
	}
	return 0;
}
