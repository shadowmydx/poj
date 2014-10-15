#include <stdio.h>
#include <string.h>
int main(void)
{
    char stack1[200][200];
    char stack2[200][200];
    char command[12];
    char web[200];
    int top1 = -1;
    int top2 = -1;
    strcpy(web, "http://www.acm.org/");
    while(scanf("%s",command))
    {
                              if(strcmp(command,"QUIT") == 0)break;
                              else if(strcmp(command,"VISIT") == 0)
                              {
                                   strcpy(stack1[++top1],web);
                                   top2 = -1;
                                   scanf("%s",web);
                                   printf("%s\n",web);
                              }
                              else if(strcmp(command,"BACK") == 0)
                              {
                                   if(top1 >= 0)
                                   {
                                          strcpy(stack2[++top2],web);
                                          strcpy(web,stack1[top1--]);
                                          printf("%s\n",web);
                                   }
                                   else
                                   {
                                       printf("Ignored\n");
                                   }                               
                              }
                              else if(strcmp(command,"FORWARD") == 0)
                              {
                                   if(top2 >= 0)
                                   {
                                           strcpy(stack1[++top1],web);
                                           strcpy(web,stack2[top2--]);
                                           printf("%s\n",web);
                                   }
                                   else
                                   {
                                       printf("Ignored\n");
                                   }
                              }
    }
    return 0;
}
