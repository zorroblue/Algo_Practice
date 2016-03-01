//14CS30027
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max_iter=10,max_level=4; //GLOBAL VARIABLES
typedef struct hashtable
{
  int s,t,n,a,b;
  char **data;
}hashtable;

hashtable insert(hashtable,char *,int ,int *); // prototype of insert

//initialise function
hashtable init(int s,int t,int n,int a,int b)
{
  hashtable table;
  table.a=a;
  table.b=b;
  table.n=n;
  table.s=s;
  table.t=t;
  table.data=(char **)malloc(s*sizeof(char *));
  return table;
}
//the hash function used ,returns the hash value of the string
int hash(char *str,int c,int t)
{
  if(str==NULL)
    {
      printf("null string!!\n");
      return -1;
    }
  else
    {
      int i;
     unsigned int x;
      x=0;
      for(i=0;i<strlen(str);i++)
	{
	  x=(65791*x+str[i]);
	}
      unsigned int ans=x*c;
      return ans>>(32-t);
    }
}
//the search function, returns 1 if found else 0
int search(hashtable table,char *str)
{
  int i=hash(str,table.a,table.t);
  int j=hash(str,table.b,table.t);
  if(table.data[i]!=NULL && strcmp(table.data[i],str)==0)
    {
      return 1;
    }
  else if(table.data[j]!=NULL && strcmp(table.data[j],str)==0)
    {
      return 1;
    }
  return 0;
}
//the rehash function...status parameter indicates whether the rehashing is correct or not ,level is the level of insert-rehash operations and type parameter is 1 for CHANGE_PARAMS AND 2 for DOUBLE_SIZE type hashings  
hashtable rehash(hashtable table,int *status,int level,int type)
{
  hashtable new_table;
  if(type==1) //CHANGE_PARAMS
    {
      new_table=init(table.s,table.t,0,table.a+2,table.b+2);
      printf("\nRehashing with changed parameters (%d,%d)\n\n",new_table.a,new_table.b);
    }
  else if(type==2)//DOUBLE_SIZE
    {
      new_table=init(table.s*2,table.t+1,0,table.a,table.b);
       printf("Rehashing with double size %d\n\n",new_table.s);
    }
  int flag=1; // becomes 0 if any one insertion fails
  int i;
  for(i=0;i<table.s;i++)
    {
      if(table.data[i]==NULL)
	continue;
      char *str=table.data[i];
      int a=0;
      int *insert_status=&a;
      printf("Entry number %d : ",i);
      new_table=insert(new_table,str,max_level+1,insert_status);
      if(*insert_status!=1) //unsuccessful
	flag=0;
      
    }
  if(flag==0) //atleast one insert has been unsuccessful
    {
      return table;
    }
  else
    {
      *status=1;
      printf("\nRehash successful!\n\n");
      //free(table.data); // free the memory in 'data' array of old table 
      return new_table;
    }
}
//the insert function...the str parameter is the string to be inserted while level is the level of insert-rehash operations ,status is a pointer to a parameter to indicate whether the insert is successful or not
hashtable insert(hashtable table,char *str,int level,int *status)
{
   int i=hash(str,table.a,table.t);
   int j=hash(str,table.b,table.t);
   if(search(table,str)==1) //if an element already exists
     {
       printf("Inserting %s (%d,%d) :  already present\n",str,i,j);
       *status=1;
       return table;
     }
   int p=0;
 
   printf("Inserting %s (%d,%d) ",str,i,j);
   while(p<max_iter)
     {
       p++;
       i=hash(str,table.a,table.t);
       j=hash(str,table.b,table.t);
       if(table.data[i]==NULL || table.data[j]==NULL)
	 {
	   if(table.data[i]==NULL)
	     {
	       table.data[i]=(char *)malloc(sizeof(char)*(strlen(str)+1));
	       strcpy(table.data[i],str);
	       printf(" in index %d...",i);
	       table.n++;
	       *status=1;//successful insert
	     }
	   else
	     {
	       table.data[j]=(char *)malloc(sizeof(char)*(strlen(str)+1));
	       strcpy(table.data[j],str);
	       printf("in index %d...",j);
	       table.n++;
	       *status=1; //successful insert
	     }
	   if((float)table.n/table.s > 0.5) //over load 
	     {
	       printf("\n\nHigh load factor=%d/%d...Rehashing...\n\n",table.n,table.s);
	       int a=0;
	       int *status_of_rehash=&a;
	       table=rehash(table,status_of_rehash,max_level+1,2);
	       if(*status_of_rehash==1) //success
		 {
		   //	    printf("Success\n");
		 }
	       else
		 {
		   // printf("Failed rehash\n");
		 }
	     }
	   else
	     printf("Success\n");
	   //return the final table
	   return table;
	 }
       else //temporary failure
	 {
	   char str1[100];
	   strcpy(str1,table.data[i]);
	   strcpy(table.data[i],str);
	   strcpy(str,str1);
	 }
    }
   //there still remains a string to be inserted
   if(level<=max_level)
     {
       int a=0;
       printf("temporary failure\n");
       int *status_of_rehash=&a;
       table=rehash(table,status_of_rehash,level,1); //CHANGE_PARAMS
       if(*status_of_rehash==0)//unsuccessful
	{
	  table=rehash(table,status_of_rehash,level,2);
	  if(*status_of_rehash==0)
	    printf("Failure!\n");
	  else
	    table=insert(table,str,level+1,status);
	}
       else //successful rehash
	 {
	 table=insert(table,str,level+1,status);
	 if(*status==0)//unsuccessful rehash
	   {
	     printf("HEEELOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	     table=rehash(table,status_of_rehash,level,2);
	     table=insert(table,str,level+1,status);
	     if(*status==0)
	       printf("Permanent failure..giving up..\n");
	   }
	 }
     }
   return table;
}
//delete function is the function to delete the str string from the table if present
hashtable delete(hashtable table,char *str)
{
  printf("Delete(%s) :",str);
  int i=hash(str,table.a,table.t);
  int j=hash(str,table.b,table.t);
  printf(" (%d,%d) : ",i,j);
  if(search(table,str)==1) //if the element is actually present
    {
      if(strcmp(table.data[i],str)==0)
	table.data[i]=NULL;
      else
	table.data[j]=NULL;
      printf("SUCCESS\n");;
    }
  else
    printf("FAILURE\n");
}
//main function
int main()
{
  int n,i;
  scanf("%d",&n);
  char name[100];
  hashtable table=init(8,3,0,1,3);
  for(i=0;i<n;i++)
    {
      int a;
      scanf("%s",name);
      table=insert(table,name,0,&a);
    }
  printf("\n\n****SEARCHING****\n\n");
  int nsearch;
  scanf("%d",&nsearch);
  for(i=0;i<nsearch;i++)
    {
      scanf("%s",name);
      printf("Search(%s) :(%d,%d) :  ",name,hash(name,table.a,table.t),hash(name,table.b,table.t));
      if(search(table,name)==0)
	printf("FAILURE\n");
      else
	printf("SUCCESS\n");
    }
  int ndel;
  scanf("%d",&ndel);
  printf("\n\n****DELETING****\n\n");
  for(i=0;i<ndel;i++)
    {
      scanf("%s",name);
      table=delete(table,name);
    }
  return 0;
}