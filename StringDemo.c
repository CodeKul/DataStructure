//
//  StringDemo.c
//  
//
//  Created by Varun on 11/01/17.
//
//

#include <stdio.h>
int length(char *s)
{
    int i = 0;
    while(*s)
    {
        s++;
        i++;
    }
    return i;
}
void reverse(char *s)
{
    int len,i,j,t;
    len=length(s);
    j=len-1;
    for(i=0;i<j;i++,j--)
    {
        t=s[i];
        s[i]=s[j];
        s[j]=t;
    }
}

char * stringCopy(char *s) {
    char *t;
    while(*s)
    {
        *t=*s;
        t++;
        s++;
    }
    *t='\0';
    return t;
}

int main()
{
    char str[] = "";
    char *tempStr=stringCopy(str);
    int flg = 0,i = 0;
    
    reverse(str);
    
    while (str[i]) {
        
        if (str[i] == *tempStr) {
            printf("tempStr: %c\n",*tempStr);
            printf("str: %c",str[i]);
            flg++;
        }
        i++;
        tempStr++;
    }
    if (length(str) == flg) {
        printf("String is palindrome\n");
    }
}
