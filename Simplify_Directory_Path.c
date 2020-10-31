/*Simplify_Directory_Path
You are given an absolute path for a file(Unix-style) and your task is to simplify it.

You might be knowing that In a UNIX-style file system, a period (.) refers to the current directory. A double period (..) denotes the parent directory.

Note: Every directory name in the path is a small-case alphabet.

Example
Input
/a/./b/../../c/

Output
/c   */

#include <stdio.h>
#include <stdlib.h>
char stack[100001];
 int top=-1;
int pop(){
	if(top==-1){
		return 0;
	}
	else
		return stack[top--];
}
void push(char x){
	stack[++top]=x;
}

void out(char arr[]){
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]=='/')
			continue;

		else if(arr[i]=='.'){
		   if(arr[i+1]=='.')
		    pop();
		}
		else if(arr[i]=='.')
			continue;
		else
			push(arr[i]);



	}
    int i=0;

    if(top==-1)
    printf("/");
	while(i!=top+1){
		printf("/");
		printf("%c",stack[i++]);

	}

}
int main() {
	char arr[100001];
     scanf("%s",arr);
     out(arr);

	return 0;
}
