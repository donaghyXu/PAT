#include <cstdio>
#include <cstring>
int main() {
	int n;
	char temp[105];		//�ַ����� 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", temp);
		int len = strlen(temp); 
		int pIndex = 0, tIndex = 0;		//���P��T��һ�γ��ֵ�λ�� 
		bool flag = true;
		
		//�ַ�����ֻҪ�в���PAT�ľͱ��Ϊfalse���������Ҫ��ͼ�¼'P','T'��һ�γ��ֵ�λ�� 
		for(int j = 0; j < len; j++) {
			if(temp[j] != 'P' && temp[j] != 'A' && temp[j] != 'T') {
				flag = false;
				break;
			}
			if(temp[j] == 'P')
				pIndex = j;
			if(temp[j] == 'T') {
				tIndex = j;
				break;
			}			
		}
		if(flag == false) {
			printf("NO\n");
			continue;
		}
		
		//'P','T'�м�ĸ���С��0�ı��Ϊfalse����Ϊ����T��Pǰ�棬���Ի��и��������ж��ǲ��Ƕ�ΪA 
		int aMidNum = tIndex - pIndex - 1;
		if(aMidNum < 0) {
			flag = false;
		} else {
			for(int j = pIndex + 1; j < tIndex; j++) {
				if(temp[j] != 'A')
					flag = false;
			}
		}
		if(flag == false) {
			printf("NO\n");
			continue;
		}
		
		//ͳ��Pǰ���T����A�ĸ��� 
		int aPreNum = 0, aPostNum = 0;
		if(pIndex != 0) {
			for(int j = 0; j < len;) {
				if(temp[j] == 'A' && j < pIndex) {
					aPreNum++;
				} else if(temp[j] == 'A' && j > tIndex) {
					aPostNum++;	
				} else {
					flag = false;
					break;
				}
				if(j == pIndex - 1) j = tIndex + 1;
				else j++;
			}
		}
		
		//���������Pǰ��A�ĸ������м�A�ĸ�������T����A�ĸ��������false 
		if(aMidNum == 0) {
			flag = false;
		} else {
			if(aPreNum * aMidNum != aPostNum)	flag = false;
		}
		
		if(flag == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
