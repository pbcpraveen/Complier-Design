#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
struct Node {
  char identifier[50];
  char type[10];
  int size;
  int address;
  char value[100];
};
typedef struct Node node;

char keyword[32][20] = {"auto" , "break" , "case" , "char" , "const" , "continue" , "default" , "do" , "double" , "else" , "enum" , "extern" , "float",
			"for" , "goto" , "if" , "int" , "long" , "register" , "return" , "short" , "signed" , "sizeof" , "static" , "struct" , "switch",
			"typedef" , "union" , "unsigned" , "void" , "volatile" , "while"};

int isKey(char a[]){
  int flag = 0 ;
  for(int i = 0; i < 32 ;i++)
    {
      if(strcmp(a,keyword[i])==0)
	{
	  flag = 1;
	  break;
	}
    }
  return flag;
}
int main(){
  int f = open("code.c",O_RDONLY);
  char code[5000];
  int n = read(f,code,4999);
  char *line;
  char *restline = code;
  while((line = strtok_r(restline,"\n",&restline))!=NULL){
    if ( line[0] == '#'){
      printf("%s : Preprocessor directive\n",line);
    }
    else if( strstr(line,"printf")!=NULL){
      int p = strlen(line);
      line[p-1] = '\0';
      printf("%s : function call\n",line);
	  }  
    else{
      char *word;
      char *rest = line;
      
      while((word = strtok_r(rest," ",&rest))!=NULL)
	{
	  if(isKey(word)==1){
	    printf("%s : KeyWord\n",word); 
	  }
	  else if( strstr(word,"()")!=NULL){
	    printf("%s : function call\n",word);
	  }
	 
	}
      
    }
    
  }
  
}
