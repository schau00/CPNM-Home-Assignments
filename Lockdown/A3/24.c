/*
Q : . Write a C program that prints the following patterns for the input of n=4. The value of n is input by
the user.
*/

# include <stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int i , j, k;
    /*
    Pattern 1 :
    1
    1 2
    1 2 3 
    1 2 3 4
    */
   printf("PATTERN 1 : \n");
   for(i = 1; i <= n; i++){
       for(j = 1; j <= i; j++){
           printf("%d ", j);
       }
       printf("\n");
   }

   /*
   Pattern 2 :
         1     
       1 2
     1 2 3
   1 2 3 4
   */
  printf("\nPATTTERN 2 : \n");
  for(i = 1; i <= n; i++){
      k = 0;
      while(k != n-i){
          printf("  ");
          k ++ ;
      }
      for(j = 1; j <= i; j++){
          printf("%d ",j);
      }
      printf("\n");
  }

  /*
  Pattern 3 :
        1
      1 2 1
    1 2 3 2 1
  1 2 3 4 3 2 1
    */
   printf("\nPATTTERN 3 : \n");
   for(i = 1; i <= n; i++){
      k = 0;
      while(k != n-i){
          printf("  ");
          k ++ ;
      }
      for(j = 1; j <= i; j++){
          printf("%d ", j);
      }
      for (j = i-1; j >= 1; j--){
          printf("%d ", j);
      }
      printf("\n");
  }

   /*
   Pattern 4 :
         1   
        1 1
       1 2 1
      1 2 2 1
     1 2 3 2 1
    1 2 3 3 2 1
   1 2 3 4 3 2 1
   */
  printf("\nPATTTERN 4 : \n");
  for(i = 1; i <= 7; i++){
      k = 0;
      while(k != n*2 -i-1){
          printf(" ");
          k ++ ;
      }
      if(i & 1 == 1){

          for(j = 1; j <= (i/2)+1; j++){
              printf("%d ", j);
          }
          for(j = (i/2); j >= 1; j--){
              printf("%d ", j);
          }
      }
      else{
          for(j = 1; j <= (i/2); j++){
              printf("%d ", j);
          }
          for(j = (i/2); j >= 1; j--){
              printf("%d ", j);
          }
      }
      printf("\n");
  }

  /*
  Pattern 5 :
  4 3 2 1 0
  3 2 1
  2
   */
  printf("\nPATTTERN 5 : \n");
  k = n;
  for(i = n+1; i >= 1; i-=2){
      for(j = k; j > k-i; j--){
          printf("%d ", j);
      }
      k --;
      printf("\n");
  }



   /*
 Pattern 6 :
    +
   +++
  +++++ 
 +++++++
  +++++
   +++
    +
   */
  printf("\nPATTTERN 6 : \n");
  for(i = 1; i < 2*n; i++){
      k = 0;
      int x;
      if(i <= n){
          x = i;
      }
      else{
          x = (2*n)-i;
      }
      while(k != n-x){
          printf(" ");
          k ++ ;
      }
      for(j = 1; j <= (2*x -1); j++){
          printf("+");
      }
      printf("\n");
  }

 

  /*
  Pattern 7 :
     1
    121
   12321  
  1234321
   12321
    121
     1
    */
   printf("\nPATTTERN 7 : \n");
   for(i = 1; i < 2*n; i++){
      k = 0;
      int x;
      if(i <= n){
          x = i;
      }
      else{
          x = (2*n)-i;
      }
      while(k != n-x){
          printf(" ");
          k ++ ;
      }
      for(j = 1; j <= (2*x -1); j++){
        
        if(j <= x){
            printf("%d", j);
        }
        else{
            printf("%d", x - (j%x));
        }          
      }
      printf("\n");
  }

   /*
   Pattern 8 :
   +++++++++
   ++++ ++++
   +++   +++
   ++     ++
   +       +
   ++     ++
   +++   +++
   ++++ ++++
   +++++++++
   */
  printf("\nPATTTERN 8 : \n");
  k = n;
  for(i = 1; i <= 2*n +1; i++){
      if(i == 1 || i == 2*n +1){
          for(j = 1; j <= 2*n +1; j++){
              printf("+");
          }
      }
      else{
          for(j = 1; j <= k; j++){
              printf("+");
          }
          for(j = 1; j <= 2*n +1 - 2*k; j++){
              printf(" ");
          }
          for(j = 1; j <= k; j++){
              printf("+");
          }

          if(i >= n + 1){
              k ++;
          }
          else{
              k --;
          }
      }
      printf("\n");
  }

  /*
  Pattern 9 : 

      +
     + +
    +   +
   +     +
    +   +
     + +
      +
   */
  printf("\nPATTTERN 9 : \n");
  for(i = 1; i < 2*n; i++){
      k = 0;
      int x;
      if(i <= n){
          x = i;
      }
      else{
          x = (2*n)-i;
      }
      while(k != n-x){
          printf(" ");
          k ++ ;
      }
      for(j = 1; j <= (2*x -1); j++){
          if(j == 1 || j == 2*x -1){
              printf("+");
          }
          else{
              printf(" ");
          }
      }
      printf("\n");
  } 

  return 0;
    
}