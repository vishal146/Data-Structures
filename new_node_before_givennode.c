#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
      int info;
      struct node *link;
};
struct node *FIRST;
void createlist()
{
      char ch;
      printf("Enter n for break\n");
      ch=getchar();
      while(ch!='n')
      {
      struct node *NEW_NODE,*SAVE;int x;
      NEW_NODE=(struct node *)malloc(sizeof(struct node));
      printf("Enter Data:");
      scanf("%d",&x);
      NEW_NODE->info=x;
      if(FIRST==NULL)
      {
         NEW_NODE->link=NULL;
         FIRST=NEW_NODE;
      }
      else
      {
         SAVE=FIRST;
         while(SAVE->link!=NULL)
         {
            SAVE=SAVE->link;
         }
         SAVE->link=NEW_NODE;
         NEW_NODE->link=NULL;
      }
      fflush(stdin);
      printf("Enter n for break\n");
      ch=getchar();
   }
}
void insertbefore(int x)
{
      struct node *NEW_NODE,*SAVE,*PRED;
      int value;
      NEW_NODE=(struct node *)malloc(sizeof(struct node));
      printf("Enter value of node:");
      scanf("%d",&value);
      NEW_NODE->info=value;
      if(FIRST==NULL)
      {
         printf("Specified Node Not Found\n");
      }
      else
      {
          SAVE=FIRST;
          while(x!=SAVE->info && SAVE->link!=NULL)
          {
          PRED=SAVE;
          SAVE=SAVE->link;
          }
          if(SAVE->info==x)
          {
          if(FIRST==SAVE)
          {
              NEW_NODE->link=SAVE;
              FIRST=NEW_NODE;
          }
          else
          {
              NEW_NODE->link=SAVE;
              PRED->link=NEW_NODE;
          }
          }
          else
          {
          printf("Specified Node Not Found");
          }
      }
}
void display()
{
      struct node *SAVE;
      if(FIRST==NULL)
      {
         printf("Linked List is empty\n");
         return;
      }
      printf("elements are:\n");
      SAVE=FIRST;
      while(SAVE!=NULL)
      {
         if(SAVE->link==NULL)
         printf("|%d|",SAVE->info);
         else
         printf("|%d|->",SAVE->info);
         SAVE=SAVE->link;
      }
      printf("\n");
      return;
}
void main()
{
      int x;
      clrscr();
      FIRST=NULL;
      createlist();
      display();
      printf("Enter value of Node before which you want to enter new node:");
      scanf("%d",&x);
      insertbefore(x);
      display();
      getch();
}
