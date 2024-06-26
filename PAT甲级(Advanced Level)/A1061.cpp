#include <cstdio>
#include <cstring>
int main() {
	char str[4][65];
	char day[8][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	for(int i = 0; i < 4; i++) {
		gets(str[i]);
	}
	int len1 = strlen(str[0]);
	int len2 = strlen(str[1]);
	int len3 = strlen(str[2]);
	int len4 = strlen(str[3]);
	int i, dd, hh, mm;
	for(i = 0; i < len1 && i < len2; i++) {
		if(str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
			dd = str[0][i] - 'A';
			break;
		}
	}
	for(i++;i < len1 && i < len2; i++) {
		if(str[0][i] == str[1][i]) {
//			printf("1:%c,2:%c\n", str[0][i], str[1][i])
			if(str[0][i] >= '0' && str[0][i] <= '9') {
				hh = str[0][i] - '0';
//				printf("str:%c", str[0][i]);
				break;
			}else if(str[0][i] >= 'A' && str[0][i] <= 'N') {
				hh = str[0][i] - 'A' + 10;
//				printf("str:%c,i:%d\n", str[0][i], i);
				break;
			}
		}
	}
	for(i = 0; i < len3 && i < len4; i++) {
		if(str[2][i] == str[3][i]) {
			if((str[2][i] >= 'A' && str[2][i] <= 'Z') || (str[2][i] >= 'a' && str[2][i] <= 'z')) {
				mm = i;
				break;
			}
		}
	}
//	printf("day:%d", dd);
	printf("%s %02d:%02d", day[dd], hh, mm);
	return 0; 
}
