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
	printf("<<<<< ���ϸ� ���� >>>>>\n\n");
	printf("1. ���ϸ� ���\n");
	printf("2. ���ϸ� Ȯ��\n");
	printf("3. ���ϸ� �˻�\n");
	printf("4. ���ϸ� ����\n");
	printf("5. ���ϸ� ����\n");
	printf("6. ���α׷� ����\n");
}
void addNode(NODE* head){
	int input;
	char poke[20];
	while(1){
		printf("\n����� ���ϸ��� ��ȣ�� �Է����ּ���\n");
		printf("��ȣ �Է�(���� 0) : ");
		scanf("%d",&input);
		if(input == 0) break;
		
		NODE* newNode = (NODE*)malloc(sizeof(NODE));
		newNode->num = input;
		
		printf("\n����� ���ϸ��� �̸��� �Է����ּ���\n");
		printf("�̸� �Է� : ");
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
	printf("�˻��� ���ϸ��� ��ȣ�� �Է����ּ���\n");
	printf("��ȣ �Է� : ");
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
	if(count == 0) printf("��ȣ�� ������� �ʾҽ��ϴ�.");
}

void fixList(NODE* head)
{
	int input,count=0;
	char fixname[20];
	NODE* curr = head->next;
	
	printf("������ ���ϸ��� ��ȣ�� �Է����ּ���\n");
	printf("��ȣ �Է� : ");
	scanf("%d",&input);
	
	while(curr != NULL)
	{
		if(curr->num == input)
		{
			count++;
			printf("No.%d : ",curr->num);
			printf("%s\n\n",curr->name);
			
			printf("������ ���ϸ��� �̸��� �Է����ּ���\n");
			fflush(stdin);
			gets(fixname);
			strcpy(curr->name,fixname);
			printf("������ �Ϸ�Ǿ����ϴ�."); 
		}
		curr = curr->next;
	}
	if(count == 0) printf("��ȣ�� ������� �ʾҽ��ϴ�."); 
}

void deleteList(NODE* head)
{
	int input,count=0;
	char answer[5] = "";
	NODE* curr = head->next;
	NODE* temp = curr;
	
	printf("������ ���ϸ��� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d",&input);
	while(curr != NULL)
	{
		if(curr->num == input)
		{
			printf("No.%d : ",curr->num);
			printf("%s\n\n",curr->name);
			printf("������ �����Ͻðڽ��ϱ�?\n");
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
				printf("���ϸ��� �����Ͽ����ϴ�.\n");
			}
			else if(!strcmp(answer,"N"))
			{
				printf("�׷�");
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
	printf("\n�Է� : ");
	scanf("%d",&input);
	
		
		if(input == 6){
			printf("\n���α׷��� �����մϴ�.\n");
			break;
		}
		else if(input == 1){
			system("cls");
			addNode(head);
			system("cls");
		}
		else if(input == 2){
			system("cls");
			printf("������� ��ϵ� ���ϸ��� ����մϴ�.\n\n");
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
