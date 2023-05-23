#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct node{
	
	int num;
	char* name;
	struct node* next;
}NODE;

void init(){
	printf("\n\n");
	printf("<<<<< 포켓몬 도감 >>>>>\n\n");
	printf("1. 포켓몬 등록\n");
	printf("2. 포켓몬 확인\n");
	printf("3. 포켓몬 검색\n");
	printf("4. 포켓몬 수정\n");
	printf("5. 포켓몬 삭제\n");
	printf("6. 프로그램 종료\n");
}
void addNode(NODE* head){
	int input;
	char poke[20];
	while(1){
		printf("\n등록할 포켓몬의 번호를 입력해주세요\n");
		printf("번호 입력(종료 0) : ");
		scanf("%d",&input);
		if(input == 0) break;
		
		NODE* newNode = (NODE*)malloc(sizeof(NODE));
		newNode->num = input;
		
		printf("\n등록할 포켓몬의 이름을 입력해주세요\n");
		printf("이름 입력 : ");
		fflush(stdin);
		gets(poke);
		newNode->name = (char*)malloc(sizeof(strlen(poke)));
		strcpy(newNode->name,poke);
		
		newNode->next = head->next;
		head->next = newNode;
		puts("");
	}
}

void listPrint(NODE* head){
	NODE* curr = head->next;
	while(curr != NULL)
	{
		printf("No.%d : ",curr->num);
		printf("%s\n",curr->name);
		curr = curr->next;
	}
}

void searchList(NODE* head)
{
	int input,count=0;
	NODE* curr = head->next;
	printf("검색할 포켓몬의 번호를 입력해주세요\n");
	printf("번호 입력 : ");
	scanf("%d",&input);
	while (curr != NULL){
		if(curr->num == input)
		{
			count++;
			printf("No.%d : ",curr->num);
			printf("%s\n",curr->name);
			break;
		}
		curr = curr->next;
	}
	if(count == 0) printf("번호가 저장되지 않았습니다.");
}

void fixList(NODE* head)
{
	int input,count=0;
	char fixname[20];
	NODE* curr = head->next;
	
	printf("변경할 포켓몬의 번호를 입력해주세요\n");
	printf("번호 입력 : ");
	scanf("%d",&input);
	
	while(curr != NULL)
	{
		if(curr->num == input)
		{
			count++;
			printf("No.%d : ",curr->num);
			printf("%s\n\n",curr->name);
			
			printf("변경할 포켓몬의 이름을 입력해주세요\n");
			fflush(stdin);
			gets(fixname);
			strcpy(curr->name,fixname);
			printf("변경이 완료되었습니다."); 
		}
		curr = curr->next;
	}
	if(count == 0) printf("번호가 저장되지 않았습니다."); 
}

void deleteList(NODE* head)
{
	int input,count=0;
	char answer[5] = "";
	NODE* curr = head->next;
	NODE* temp = curr;
	
	printf("삭제할 포켓몬의 번호를 입력하세요 : ");
	scanf("%d",&input);
	while(curr != NULL)
	{
		if(curr->num == input)
		{
			printf("No.%d : ",curr->num);
			printf("%s\n\n",curr->name);
			printf("정말로 삭제하시겠습니까?\n");
			printf("Y/N : ");
			fflush(stdin);
			gets(answer);
			puts(answer);
			if(!strcmp(answer,"Y"))
			{
				if(head->num == input)
				{
					head = curr->next;
					curr->next = NULL;
					free(curr);
				}
				else if(head->num != input)
				{
					temp = curr->next;
					curr->next = NULL;
					free(curr);
				}
				printf("포켓몬을 제거하였습니다.\n");
			}
			else if(!strcmp(answer,"N"))
			{
				printf("그래");
			}
		}
		temp = curr;
		curr = curr->next;
	}
}
void main(void)
{
	int input;
	NODE* head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;
	while(1){
	init();
	printf("\n입력 : ");
	scanf("%d",&input);
	
		
		if(input == 6){
			printf("\n프로그램을 종료합니다.\n");
			break;
		}
		else if(input == 1){
			system("cls");
			addNode(head);
			system("cls");
		}
		else if(input == 2){
			system("cls");
			printf("현재까지 등록된 포켓몬을 출력합니다.\n\n");
			listPrint(head);
		}
		else if(input == 3){
			system("cls");
			searchList(head); 
		}
		else if(input == 4){
			system("cls");
			fixList(head);
		}
		else if(input == 5){
			system("cls");
			deleteList(head);
		
		} 
	}

}
