#include <cstdio>
#include <cstring>
int main() {
	char str1[65], str2[65], str3[65], str4[65];	//����4���ַ��� 
	scanf("%s %s %s %s", str1, str2, str3, str4);
	char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};	//����һ���������ڵ��ַ����� 
	int len1 = strlen(str1);	//��ȡ�ַ������� 
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	int len5 = len1 < len2? len1 : len2;	//��ȡ�Ƚ�С���Ǹ��ַ������� 
	int len6 = len3 < len4? len3 : len4;
	int i;	//���ڵ�һ���ַ�����Ҫ��2���ַ����ڶ����ַ������ҵ���һ���ַ�������ż����ң����Զ��������� 
	
	//Ѱ�ҵ�һ����ͬ�Ĵ�д�ַ���������� 
	for(i = 0; i < len5; i++) {
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') {
			printf("%s ", week[str1[i] - 'A']);
			break;
		}	
	}
	
	//Ѱ�ҵڶ�����ͬ���ַ�����0~9��A~N֮�䣬���Сʱ 
	for(i++; i < len5; i++) {
		if(str1[i] == str2[i]) {
			if(str1[i] >= '0' && str1[i] <= '9') {
				printf("%02d:", str1[i] - '0');	//����2λ����0 
				break;
			} else if(str1[i] >= 'A' && str1[i] <= 'N') {
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			} 
		}
	}
	
	//�ڵ����͵����ַ�����Ѱ�ҵ������ַ���ΪӢ����ĸ��������� 
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
