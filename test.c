#include <stdio.h>
#include <stdlib.h>

void main(){
	
	char str[10];
	int num;
	/*FILE* fp = fopen("1234.txt", "wt");
	
	fprintf(fp, "%s %d", "맨시티", 80);
	
	
	fclose(fp);*/
	
	FILE* fp = fopen("1234.txt", "r");
	if(fp == NULL){
		printf("파일이 없습니다.\n");
		return;
	}
	//feof(fp); 파일 끝이면 0 반환 
	
	
	while(!feof(fp)){
	fscanf(fp, "%s %d", str, &num);
	printf("%s %d\n", str, num);
    }
	
}
