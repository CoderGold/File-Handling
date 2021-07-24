//Write a C program to display the contents of the file in reverse order. Also copy the contents from one file to another file. 
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
 main()
{
	int i,count=0;
	char c,temp,*ch;
	FILE *p;
	p=fopen("Unreversed_text.txt","r");
	while(c!=EOF)        //getting the length of characters in file
	{
		c=getc(p);
		count++;	
	}
	fclose(p);
	p=fopen("Unreversed_text.txt","r");
	ch=(char*)malloc((count-1)*sizeof(char));    //dynamically allocating memory      
	for(i=0;i<(count-1);i++)
	{
		c=getc(p);
		ch[i]=c;
	}
	fclose(p);
	p=fopen("Copied.txt","w");      //creating new file
	for(i=0;i<(count-1);i++)
	{
		fprintf(p,"%c",ch[i]);
	}
	for(i=(count-2);i>=0;i--)
	{
		if((count-2)-i==i)
		{
			break;
		}
		else
		{
		    temp=ch[(count-2)-i];
		    ch[(count-2)-i]=ch[i];
		    ch[i]=temp;
	    }
	}
	for(i=0;i<(count-1);i++)
	{
		printf("%c ",ch[i]);
	}
}
