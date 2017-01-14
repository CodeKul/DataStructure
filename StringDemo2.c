#include<stdio.h>

int Length(char *);
void CalAscii(char);
void Reverse(char *);
void Uppercase(char *);
void Lowercase(char *);
void CheckPalin(char *);
void toString(char *);

int main()
{
    char ch;
    //printf("enter a character\n");
    //scanf("%c",&ch);
    //CalAscii(ch);
	char str[]="moHiSh, ,HsihOM";
    char str1[]="A Man, A Plan, A Canal-Panama!";
    //char str2[]="Madam In Eden, I'm Adam";
   // char str3[]="A Santa Lived As a Devil At NASA";
   // char str4[]="Was It A Rat I Saw?";
   // char str5[]="mohoM";
    
    toString(str);
    toString(str1);
    //toString(str2);
   // toString(str3);
   // toString(str4);
   // toString(str5);
    
//    printf("%s\n",str);
}

void CalAscii(char s)
{
    printf("%d",s);
}
int Length(char *s)
{
	int i=0;
	while(*s)
	{
		i++;
		s++;
	}
	return i;
}
void Reverse(char *s)
{
	int len,i,temp;
	len=Length(s)-1;
	for(i=0;i<len;i++,len--)
	{
		temp=s[i];
		s[i]=s[len];
		s[len]=temp;
	}
	s[i+len+1]='\0';
}

void CheckPalin(char *s)
{
    printf("%s",s);
    int i=0,j,flag=0;

    j=Length(s);
    for(i=0;i<(j/2);i++)
    {
        if(s[i]!=s[j-i-1])
        {
            flag=1;
        }
    }
    if(flag==   1)
    {
		printf("the string is not a palindrome\n");
    }
    else
    {
		printf("the string is a palindrome\n");
    }
}
void Uppercase(char *s)
{
	while(*s)
	{
	    if((*s>=97) && (*s<=122))
		{
			*s=*s-32;
		}
        s++;
	}
}
void Lowercase(char *s)
{
	while(*s)
	{
	    if((*s>=65) && (*s<=90))
		{
			*s=*s+32;
		}
        s++;
	}
}

void toString(char *s)
{
    int i=0,j,len;
	len=Length(s);
	Lowercase(s);
    printf("******%s\n",s);
	while(s[i] != '\0')
	{
		if(!(s[i]>=97 && s[i]<=122))
		{
			for(j=i;j<len;j++)
			{
                s[j]=s[j+1];
			}
            continue;
		}
        i++;
	}
    printf("******%s\n",s);
    CheckPalin(s);
}


