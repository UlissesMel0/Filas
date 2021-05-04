#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
FILE *fl;

typedef struct stack{
	
	char site[51];
	char link[51];
	struct stack* right;
};

typedef struct stack Stack;
Stack* base = NULL;
Stack* top = NULL;
Stack* x;

int Empty_Stack(){
	
	if(base == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

// - Done  -
void Insert_Site_and_Link(){
	
	char site[51];
	char link[51];

	
	if(Empty_Stack() == 1){
		
		base = (Stack*)malloc(sizeof(Stack));
		
		printf("\n\nSite: ");
		fflush(stdin);
		scanf("%s",&base->site);
		
		printf("\nLink: ");
		fflush(stdin);
		scanf("%s",&base->link);
		
		base->right = NULL;
		
		x = base;
		top = base;
		
		printf("\nThe site and its link were successfully added!\n");
		
	}else{
		
		top = (Stack*)malloc(sizeof(Stack));
		
		printf("Site: ");
		fflush(stdin);
		scanf("%s",&top->site);
		
		printf("Link: ");
		fflush(stdin);
		scanf("%s",&top->link);
		
		top->right = x;
		x = top;
		printf("\nThe site and its link were successfully added!\n");		
	}
}

// -  Done  -
void Print_Link(){
	
	Stack* x;
	
	if(Empty_Stack() == 1){
		printf("\nThe stack is empty, there's no site nor link to print.\n");
	}else{
		
		printf("\nPrinting the whole stack.\n");
		
		x = top;
		while(x != NULL){
			printf("[%s : %s]\t",&x->site,x->link);
			x = x->right;
		}
		
	}
	
}

// -  Dona  -
void Find_Site(){
	
	char site[51];
	Stack* x;
	Stack* y;
	
	if(Empty_Stack() == 1){
		printf("The stack is empty, there's no site nor link.");
	}else{
		printf("Site: ");
		scanf("%s",&site);
		
		x = top;
		y = top;
		
		while(strcmp(x->site,site) != 0){
			
			y = x;
			x = x->right;
			
		}
		
		if(x != top){
			
			y->right = x->right;
		
			x->right = top;
			top = x;
			
		}
		
		printf("\n[%s : %s]",x->site,x->site);
		
	}
	
}


int main(int argc, char *argv[]) {
	
	char site[50];
	int menu = 0;
	
	printf("[1] Insert a site and its link.\n");
	printf("[2] Search for a site and its link.\n");
	printf("[3] Printg all the sites and corresponding links on our database.\n");
	printf("[4] Quit.\nChoice: ");

	scanf("%d",&menu);
	
	while((menu == 1) ||(menu == 2) ||(menu == 3) ||(menu == 4)){
		
		switch(menu){
		case 1: Insert_Site_and_Link();
			break;
		case 2:
			Find_Site();
			break;
		case 3: Print_Link();
			break;
		case 4: printf("\nClosing system...");
			 exit(0);
		default: printf("\nNo such option.\n");
			break;	
	}
	
	printf("\nAction: ");
	scanf("%d",&menu);
		
	}	
	
	return 0;
}
