/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void print_sp(int i,int n){
    
    for(int j=1;j<=n-i;j++){
        printf(" ");
        
    }
    
    
}

void print_num(int n){
    
    for(int j=1;j<=n;j++){
        
        printf("%d ",n);
        
    }
    
    
}



int main()
{
   int rows = 6;
   for(int i=1;i<=rows;i++){
       print_sp(i,rows);
       print_num(i);
       printf("\n");
       
   }
   
    return 0;
}

