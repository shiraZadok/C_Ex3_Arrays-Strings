#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 256
#define WORD 30


int getLine(char s[]){
    int count =0;
     char *c = fgets(s,LINE, stdin);
     while(*c !='\0'){
        c++;
        count++;
     }
     return --count;      
}

char* getword(char w[]){
    char c = '\0';
    int flag = 1;
    char *s ;
    while(flag){
        scanf("%c", &c);
        if(c!= ' ' && c != '\t' && c!='\n'){
            s = strncat(w, &c, 1);

        }
        else{
            flag=0;
        }
    }

    return s;

}

int substring(char *str1, char* str2){
    int flag = 1;
    char *temp = str2;
    
    while((*str1)!='\0'){
        if((*str1)==(*str2)){
            while ((*str1)!='\0' && (*str2)!= '\0' && flag){
                    if((*str1)!=(*str2)){
                        flag = 0;
                    }
                    else
                    {
                        str2++;
                        str1++;
                    }
                    
            }
            if(flag && (*str2)=='\0'){
                return 1;
            } 
            else
            {
                str2=temp;
                flag=1;
            }
             
        }
        str1++;
   }
   return 0;
}

int similar(char *s, char *t, int n){
    int diffrent=0;
    while (*s!='\0'){
        if(*s != *t){
            diffrent++;
        }
        else{

           t++;
        }
        s++;
    }

    if(diffrent<=n && *t=='\0'){
        return 1;
    }
    return 0; 
}

void print_lines(char *str){
    char s[LINE];
    char *line;
    while ((line = fgets(s,LINE, stdin))!= NULL)
    {
       if(substring(line, str)==1){
           printf("%s", line);
       }
    }
}

void print_similar_words(char *str){
    char w[30];
    while(scanf("%s",w)==1){
        int ans = similar(w,str,1);
        if (ans == 1)
        {
            printf("%s\n", w);
        }
    }

}


int main(){
    char str[30];
    char op;
    int i=0;
    while(i<3){
        if(i==0){
            scanf("%s",str);
        }
        else if(i==1){
            scanf("%c",&op);
        }else
        {
            scanf("%c",&op);
        }
        
        i++;
    }  
        if (op=='a')
        {
            print_lines(str);
        }
        else if (op=='b')
        {
            print_similar_words(str);        }
        else
        {
    printf("ERR: Shira Win!!");        
}
        
return 0;
}





