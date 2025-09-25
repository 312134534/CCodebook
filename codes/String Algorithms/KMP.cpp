string a; // 文本串
string b; // 模板串(将被匹配的子串)
int kmp_next[N]; // next数组

void getNext(int m=b.size()){//初始化
	int j = 0;
	kmp_next[0] = 0;
	for(int i=1; i<m; ++i){
		while(j>0 && b[i]!=b[j]) j=kmp_next[j-1];
		if(b[i]==b[j]) ++j;
		kmp_next[i] = j;
	}
}

int kmp(int n=a.size(),int m=b.size()){//使用KMP寻找匹配位置
	int i, j = 0;
	int p = -1;
	getNext(m);
	for(i=0; i<n; ++i){
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		if(b[j]==a[i]) ++j;
		if(j==m){
			p = i - m + 1;
			break;
		}
	}
	return p;
}

int kmp(int n=a.size(),int m=b.size()){//使用KMP计算匹配次数
	int i, j = 0, res = 0;
	getNext(m);
	for(i=0; i<n; ++i){
		while(j>0 && b[j]!=a[i]) j=kmp_next[j-1];
		if(b[j]==a[i]) ++j;
		if(j==m) ++res;
	}
	return res;
}
