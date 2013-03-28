#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
 
struct List
{
	int num;
	List *next;
};
 
void printmenu(){
	printf("\nChoose action number: ");
	printf("\n1. Input");
	printf("\n2. Add beefor last");
	printf("\n3. Association two list");
	printf("\n4. Turn the lust");
	printf("\n5. Show all");
	printf("\n6. Exit\n");
}

List *Add(List *root)
{   
    List *tmp=new List;
	List *p;
	printf("\nSome incoming data...\n");
	printf("Enter number ");
	scanf("%d",&(tmp->num));
	tmp->next=NULL;
	if(root==NULL)
	{
		return tmp;
 }
	else
	{
		p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=tmp;
		return root;
	}
}

void ShowAll(List *root)
{
     
	while(root)
	{
		printf("%d ;  ",root->num);
		root=root->next;
	}
}

List* Reverse(List* root)
{
    if(root==0)
        return 0;
    if(root->next==0)
        return root;
    List *rv = Reverse(root->next);
    root->next->next = root;
    root->next = 0;
    return rv;
}

int main()
{
    List *root=NULL,*tmp;
    char ch[10];
    int k;
    while(1)
	{
		printmenu();
        scanf("%s",ch);
        k=atoi(ch);           
                       switch(k){
                                    case 1:
                                       {     
                                         system("cls");
                                         int a,b = 0;
                                         printf("\nHow much element do you want add? ");
                 	                     scanf("%d",&a);
                                         while(b < a)
                                           {  
                                                root = Add(root); b++; 
                                           } 
                                         printf("All number added. Press any key to continue");
                                         getch();
                                         system("cls");
                                         break;
                                       };  
                                    case 2:
                                    case 3:
                                    case 4: 
                                         root = Reverse(root); 
                                         printf("List turned. Press any key to continue"); 
                                         getch(); 
                                         system("cls");
                                         break;
                                    case 5: 
                                         system("cls"); 
                                         ShowAll(root); 
                                         printf("\n"); 
                                         break;     
                                    case 6: 
                                         exit(0);
                                    default: 
                                         printf("\nIncorrect input. Press any key to continue\n");
                                         getch(); 
                                         system("cls");                           
                                }
     }
     while(tmp=root){
                     root=root->next;
                     delete tmp;
                    }                                
     return 0;
}