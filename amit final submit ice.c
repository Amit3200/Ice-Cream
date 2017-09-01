#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct ice
{
	int id;
	char name[30],fla[30],ty[30];
	float pr;
}s1;
FILE *fp,*fpt,*fpp,*emp,*fp2;
int addice();
int disp();
int search();
int delice();
int update();
int sort();
int bill();
int main()
{
int n;
printf("\t\tWelcome to TUSHARamit ice-cream management system\n");
     char use[10],ch;	
     int i;
	 printf("\nEnter the login id-  ");
	 gets(use);
	 if(stricmp(use,"tushar01")==0)
	 {
	 printf("\nEnter the password-  ");	
	char a[]="tusharamit06";
	char b[13];
	for(i=0;i<12;i++)
	{
		b[i]=getch();
		putchar('*');
	}
	b[12]='\0';
	{
		if(strcmp(a,b)==0)
		{
	    printf("\n\n\n\t\t\t LOGIN SUCESSFULL\n\n");
	    printf("\t\t\tWELCOME TUSHARAMIT\n");
	    A:
printf("\nSelect an option\n\n1.ADD ICE CREAM\n\n2.DISPLAY ICE CREAM\n\n3.SEARCH ICE CREAM\n\n4.DELETE ICE CREAM DATA\n\n5.UPDATE ICE CREAM PRICE\n\n6.VIEW ICE CREAM ACCORDING TO PRICE\n\n7.GENERATE BILL\n\n8.Exit\n\n");
scanf("%d",&n);
printf("\n\n\n");
switch(n)
{
case 1:
addice();
printf("\n\n\t\tFOR MAIN MENU PRESS Y or FOR EXIT PRESS ANY KEY\n");
	ch=getch();
	{
	if(ch=='y'||ch=='Y')
	goto A;
	else
	goto B;
    }
	B:	
	break;	
case 2:
disp();
printf("\n\n\t\tFOR MAIN MENU PRESS Y or FOR EXIT PRESS ANY KEY\n");
	ch=getch();
	{
	if(ch=='y'||ch=='Y')
	goto A;
	else
	goto C;
    }
	C:
	break;	
case 3:
search();
printf("\n\n\t\tFOR MAIN MENU PRESS Y or FOR EXIT PRESS ANY KEY\n");
	ch=getch();
	{
	if(ch=='y'||ch=='Y')
	goto A;
	else
	goto D;
    }
	D:
	break;	
case 4:
delice();
printf("\n\n\t\tFOR MAIN MENU PRESS Y or FOR EXIT PRESS ANY KEY\n");
	ch=getch();
	{
	if(ch=='y'||ch=='Y')
	goto A;
	else
	goto E;
    }
	E:
	break;	
case 5:
update();
printf("\n\n\t\tFOR MAIN MENU PRESS Y or FOR EXIT PRESS ANY KEY\n");
	ch=getch();
	{
	if(ch=='y'||ch=='Y')
	goto A;
	else
	goto F;
    }
	F:
	break;	
case 6:
sort();
printf("\n\n\t\tFOR MAIN MENU PRESS Y or FOR EXIT PRESS ANY KEY\n");
	ch=getch();
	{
	if(ch=='y'||ch=='Y')
	goto A;
	else
	goto G;
    }
	G:
	break;		
case 7:
bill();
printf("\n\n\t\tFOR MAIN MENU PRESS Y or FOR EXIT PRESS ANY KEY\n");
	ch=getch();
	{
	if(ch=='y'||ch=='Y')
	goto A;
	else
	goto H;
    }
	H:
	break;	
case 8:
exit(0);
break; 	
}
}
else
printf("\n\n\n\t\t\tUNAUTHORIZED USER");
}	
}
else
printf("\n\t\t\tincorrect id name\n");
}
int addice()
{
	system("cls");
	int i,n;
	fp=fopen("ice","a");
	printf("Enter the no. of icecream u want to enter in the system\n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("\n\t\t\tEnter the data\n");
    printf("\tEnter the Id : ");
    scanf("%d",&s1.id);
    printf("\tEnter the Name : ");
    scanf("%s",&s1.name);
	printf("\tEnter the Flavour : ");
    scanf("%s",&s1.fla);
	printf("\tEnter the Type : ");
    scanf("%s",&s1.ty);
	printf("\tEnter the Price : ");
    scanf("%f",&s1.pr);
    fwrite(&s1,sizeof(s1),1,fp);
	printf("\n\t\tDATA ADDED SUCCESSFULLY\n");	
	}
	fclose(fp);
}
int disp()
{
	system("cls");
	int n,f;
	fp=fopen("ice","r");
	if(fp==NULL)
	{
	printf("Can't open file\n");
    }
	else
	{
	printf("\n\nPRESS 1 .FOR ALL DATA ELSE PRESS 2 FOR PARTICULAR DATA\n");
	scanf("%d",&n);
	if(n==1)
	{
	printf("\n\nThe icecream data is: \n");
	printf("Id\t|\tName\t|\tFlavour\t|\tType\t|\tPrice\t|\t|");	
	printf("------------------------------------------------------------------------\n");
	while(fread(&s1,sizeof(s1),1,fp))
	{
    printf("%d\t|\t%s\t|\t%s\t|\t%s\t|\t%f\t|",s1.id,&s1.name,&s1.fla,&s1.ty,s1.pr);	
    printf("------------------------------------------------------------------------|\n");
	}
    }
    else if(n==2)
	{
	printf("\nEnter the icecream id u want to search\n");
	scanf("%d",&f);
	while(fread(&s1,sizeof(s1),1,fp))	
	{
	if(s1.id==f)
	{
		break;
    }
    }
    if(s1.id==f)
	{
    printf("\tThe Id : %d\n",s1.id);
    printf("\tThe Name : %s\n",&s1.name);
	printf("\tThe Flavour : %s\n",&s1.fla);
	printf("\tThe Type : %s\n",&s1.ty);
	printf("\tThe Price : %f\n",s1.pr);	
    }
	else
	{
	printf("Invalid id\n");	
	}
    }
    }
	fclose(fp);
}
int search()
{
	system("cls");
	int f;
	fp=fopen("ice","r");
	if(fp==NULL)
	{
	printf("can't open the file\n");
	}
	else
	{
	printf("Enter the icecream id u want to search\n\n");
	scanf("%d",&f);
	while(!feof(fp))
	{
    fread(&s1,sizeof(s1),1,fp);
	if(s1.id==f)
	{
	break;
    }   
    }
    if(s1.id==f)
	{
	printf("\t\t\tSearch Complete! Data Found\n\n");	
	printf("\tThe Id : %d\n",s1.id);
    printf("\tThe Name : %s\n",&s1.name);
	printf("\tThe Flavour : %s\n",&s1.fla);
	printf("\tThe Type : %s\n",&s1.ty);
	printf("\tThe Price : %f\n",s1.pr);		
	}
	else
	{
	printf("Invalid id\n");	
	}
   }
	fclose(fp);
}
int delice()
{
	fp=fopen("ice","r");
	fpt=fopen("ice1","w");
	if(fp==NULL)
	{
	printf("can't open the file\n");
	}
	else
	{
	int f,l;
	if(fp==NULL)
	{
		printf("can't open the file\n");
	}
	else
	{
		printf("\n\nThe icecream data is: \n");
	printf("Id\t|\tName\t|\tFlavour\t|\tType\t|\tPrice\t|\t|");	
	printf("------------------------------------------------------------------------\n");
	while(fread(&s1,sizeof(s1),1,fp))
	{
    printf("%d\t|\t%s\t|\t%s\t|\t%s\t|\t%f\t|",s1.id,&s1.name,&s1.fla,&s1.ty,s1.pr);	
    printf("------------------------------------------------------------------------|\n");
    }
    rewind(fp);
    printf("Enter the icecream id u want to delete\n\n");
	scanf("%d",&f);
	while(fread(&s1,sizeof(s1),1,fp))
	{
		if(s1.id==f)
		{
     	l++;
	    }
	    else
	    {	
	    fwrite(&s1,sizeof(s1),1,fpt);	
		}
    }
    }
    fclose(fpt);
    fclose(fp);
    fpt=fopen("ice1","r");
    fp=fopen("ice","w");
     while(fread(&s1,sizeof(s1),1,fpt))
    {
    fwrite(&s1,sizeof(s1),1,fp);
    }
    printf("\t\t\tRECORD IS DELETED\n\n");
    }
    fclose(fpt);
    fclose(fp); 
}
int update()
{
	system("cls");
	int f;
	fp=fopen("ice","r");
	fpp=fopen("ice2","w");
	if(fp==NULL)
	{
	printf("can't open the file\n");
	}
	else
	{
	printf("\n\nThe icecream data is: \n");
	printf("Id\t|\tName\t|\tFlavour\t|\tType\t|\tPrice\t|\t|");	
	printf("------------------------------------------------------------------------\n");
	while(fread(&s1,sizeof(s1),1,fp))
	{
    printf("%d\t|\t%s\t|\t%s\t|\t%s\t|\t%f\t|",s1.id,&s1.name,&s1.fla,&s1.ty,s1.pr);	
    printf("------------------------------------------------------------------------|\n");
    }
    rewind(fp);
	printf("Enter the icecream id u want to update\n");
	scanf("%d",&f);
	while(fread(&s1,sizeof(s1),1,fp))
    {	
    
	if(s1.id!=f)
	{

	fwrite(&s1,sizeof(s1),1,fpp);
    }
    else
	{	
	printf("\tENTER THE NEW PRICE :  ");
	scanf("%f",&s1.pr);
	printf("\n\tNEW DETAILS ARE : \n\n");
    printf("\tThe Id : %d\n",s1.id);
    printf("\tThe Name : %s\n",&s1.name);
	printf("\tThe Flavour : %s\n",&s1.fla);
	printf("\tThe Type : %s\n",&s1.ty);
	printf("\tThe Price : %f\n",s1.pr);
	printf("\n\t\tupdated\n");
    fwrite(&s1,sizeof(s1),1,fpp);  
    }
    }
    rewind(fp);
    rewind(fpp);
    fclose(fp);
    fclose(fpt);
    fpp=fopen("ice2","r");
    fp=fopen("ice","w");
    while(fread(&s1,sizeof(s1),1,fpp))
    {
    
	fwrite(&s1,sizeof(s1),1,fp);
    }
     fclose(fp);
     fclose(fpt);
    }
}
int sort()
{
	system("cls");
	int n=0,i=0,j,sum=0,a[30];
	fp=fopen("ice","r");
	if(fp==NULL)
	{
		printf("can't open the file\n");
	}
	else
	{
	printf("Id\t|\tName\t|\tFlavour\t|\tType\t|\tPrice\t|\n");	
	printf("--------------------------------------------------------------------------\n");
	while(fread(&s1,sizeof(s1),1,fp))
	{
	a[i]=s1.pr;
    sum=sum+a[i];
	i=i+1;
    }
    rewind(fp);
    for(i=0;i<=sum;i++)
    {
    for(j=0;j<30;j++)
    {
    if(a[j]==i)
    {
    n=j+1;
    rewind(fp);
    while(fread(&s1,sizeof(s1),1,fp))
    {
    if(s1.id==n)
    {
    printf("%d\t|\t%s\t|\t%s\t|\t%s\t|\t%f\t|",s1.id,&s1.name,&s1.fla,&s1.ty,s1.pr);	
   printf("------------------------------------------------------------------------|\n");
    }
    }
    }
    }
    }
    printf("\n\t\t\t\tSorted\n");
    }
    fclose(fp);
}
int bill()
{
	system("cls");
	int j,f,n;
	float sum=0;
	char ch;
	fp=fopen("ice","r");
	emp=fopen("empty","r+");
	fp2=fopen("bill","w");
	while(fread(&s1,sizeof(s1),1,emp))
	{
	fwrite(&s1,sizeof(s1),1,fp2);	
	}
	fclose(fp2);
	fclose(emp);
	if(fp==NULL)
	{
		printf("can't open the file\n");
	}
	else
	{
	printf("\nTHE MENU IS :\n");
	printf("Id\t|\tName\t|\tFlavour\t|\tType\t|\tPrice\t|\n");	
	printf("------------------------------------------------------------------------\n");
	while(fread(&s1,sizeof(s1),1,fp))
	{
    printf("%d\t|\t%s\t|\t%s\t|\t%s\t|\t%f\t|",s1.id,&s1.name,&s1.fla,&s1.ty,s1.pr);	
    printf("------------------------------------------------------------------------|\n");	
	}	
	rewind(fp);
	T:
	printf("\n\nEnter the icecream id which is bought\n\n");
	scanf("%d",&f);
	printf("\n\nEnter How many icecreams are bought\n\n");
	scanf("%d",&n);
    while(fread(&s1,sizeof(s1),1,fp))
	{
	for(j=0;j<n;j++)
	{
	if(s1.id==f)
	sum=sum+s1.pr;
	}
    }
    rewind(fp);
    while(fread(&s1,sizeof(s1),1,fp))
	{
	if(s1.id==f)
	{
	fp2=fopen("bill","a");
	fwrite(&s1,sizeof(s1),1,fp2);
	fclose(fp2);	
    }
    }
    rewind(fp);
    printf("\n\n\t\tFOR MORE PRESS Y or FOR BILL PRESS ANY OTHER KEY\n\n");
    ch=getch();
    if(ch=='y'||ch=='Y')
    {
    goto T;
	}
	else
	{
	fp2=fopen("bill","r");
	printf("------------------------------------------------------------------------\n");
	printf("|\t\t\t|\tTUSHARAMIT\t|\t\t\t|\n");
	printf("------------------------------------------------------------------------\n");
	printf("|\t\t\t\t|BILL|\t\t\t\t\t|\n");
	printf("------------------------------------------------------------------------\n");
	printf("\nId|\tName\t|\tFlavour\t|\tType\t|\tPrice\t\t|\n");	
	printf("------------------------------------------------------------------------\n");
	while(fread(&s1,sizeof(s1),1,fp2))
	{
	printf("%d|\t%s\t|\t%s\t|\t%s\t|\t%f\t|\n",s1.id,&s1.name,&s1.fla,&s1.ty,s1.pr);	
    printf("------------------------------------------------------------------------\n");		
	}
    printf("\n\n\t|\t\tTHE TOTAL BILL IS : %f\t\t|\n\n\n\t\t\t\tTHANK YOU\n\n",sum);
    fclose(fp2);
	}
    }
    fclose(fp);
}
