#include <stdio.h>
#include <stdlib.h>

void main(){
	
	char str[10];
	int num;
	/*FILE* fp = fopen("1234.txt", "wt");
	
	fprintf(fp, "%s %d", "�ǽ�Ƽ", 80);
	
	
	fclose(fp);*/
	
	FILE* fp = fopen("1234.txt", "r");
	if(fp == NULL){
		printf("������ �����ϴ�.\n");
		return;
	}
	//feof(fp); ���� ���̸� 0 ��ȯ 
	
	
	while(!feof(fp)){
	fscanf(fp, "%s %d", str, &num);
	printf("%s %d\n", str, num);
    }
	
}
