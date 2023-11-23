#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[20];
    int tos;
} Stack;

void push(Stack *s, char ch){
  
        char c=s->str[++s->tos]=ch;
        printf("Pushed %c\n",c);

    }
char pop(Stack *s){
    char ch= s->str[s->tos--];
    printf("Popped %c\n",ch);
    return ch;
}

char Top(Stack *s) {
    return s->str[(s->tos)];
}

int Prec(char ch){
    switch(ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
   }



int main(){
    int i,j=0;
    char expr[20], ans[20],temp;
    printf("Enter the infix expression ");
    scanf("%s",expr);
    Stack s;
    s.tos=-1;
    
    int prec1=0,prec2=0;

    i = 0;
    while(expr[i]!='\0'){
        if((expr[i]>='a'&& expr[i]<='z') || (expr[i]>='A'&& expr[i]<='Z')){
            ans[j++]=expr[i];
        }
     else if (expr[i] == '(') {
            push(&s,'(');
        }
        else if (expr[i] == ')') {
            while (Top(&s) != '(') {
                ans[j++] = pop(&s);
            }
            temp=pop(&s);
    }
    else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/'|| expr[i]=='^'){
        while(Prec(expr[i]) <= Prec(Top(&s))){
            ans[j++]=pop(&s);
            //push(&s,expr[i]);
        }
       
            push(&s,expr[i]);
        
    }
    i++;
}
 while (s.tos >= 0) {
        ans[j++] = pop(&s);
    }
    ans[j] = '\0';
    int len = (int)strlen(ans);
    printf("Prefix expression is: ");
    //for(i=0;i<len;i++) {
        printf("%s",ans);
   // }
    }