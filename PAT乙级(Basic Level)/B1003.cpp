#include <cstdio>
#include <cstring>
int main() {
	int n;
	char temp[105];		//字符数组 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", temp);
		int len = strlen(temp); 
		int pIndex = 0, tIndex = 0;		//存放P和T第一次出现的位置 
		bool flag = true;
		
		//字符串中只要有不是PAT的就标记为false，如果符合要求就记录'P','T'第一次出现的位置 
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
		
		//'P','T'中间的个数小于0的标记为false，因为可能T在P前面，所以会有负数，并判断是不是都为A 
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
		
		//统计P前面和T后面A的个数 
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
		
		//如果不符合P前面A的个数乘中间A的个数等于T后面A的个数，标记false 
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
