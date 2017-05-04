#include <cstdio>
#include <cstring>
int main() {
	char str1[65], str2[65], str3[65], str4[65];	//定义4个字符串 
	scanf("%s %s %s %s", str1, str2, str3, str4);
	char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};	//定义一个代表星期的字符数组 
	int len1 = strlen(str1);	//获取字符串长度 
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	int len5 = len1 < len2? len1 : len2;	//获取比较小的那个字符串长度 
	int len6 = len3 < len4? len3 : len4;
	int i;	//由于第一个字符串中要找2个字符，第二个字符是在找到第一个字符后紧接着继续找，所以定义在外面 
	
	//寻找第一个相同的大写字符，输出星期 
	for(i = 0; i < len5; i++) {
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') {
			printf("%s ", week[str1[i] - 'A']);
			break;
		}	
	}
	
	//寻找第二个相同的字符，在0~9和A~N之间，输出小时 
	for(i++; i < len5; i++) {
		if(str1[i] == str2[i]) {
			if(str1[i] >= '0' && str1[i] <= '9') {
				printf("%02d:", str1[i] - '0');	//不足2位补足0 
				break;
			} else if(str1[i] >= 'A' && str1[i] <= 'N') {
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			} 
		}
	}
	
	//在第三和第四字符串中寻找第三个字符，为英文字母，输出分钟 
	for(i = 0; i < len6; i++) {
		if(str3[i] == str4[i]) {
			if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z')) {
				printf("%02d", i);
				break;
			}
		}
	}
	return 0;
} 
