/*
    Q : Write a menu-driven program for accepting values in two square matrix of 3x3 dimension and
generate their sum, difference and product.
*/

# include <stdio.h>
int main(){
 int mat1[3][3], mat2[3][3], mat_sum[3][3],mat_pro[3][3] , mat_diff[3][3] ;
int i = 0, j = 0 ;
printf("Enter first matrix : ");
 for(i;i<3;i++){
    j = 0 ;
    for(j;j<3;j++){
      scanf("%d",&mat1[i][j]) ;}
}
i = 0 ;
printf("Enter second matrix : ");
for(i;i<3;i++){
  j = 0 ;
for(j;j<3;j++){
  scanf("%d",&mat2[i][j]) ;
 }

}
i=0 ;
for(i;i<3;i++){
  j=0 ;
 for(j;j<3;j++){
  mat_sum[i][j] = mat1[i][j] + mat2[i][j] ;
  mat_diff[i][j] = mat1[i][j] - mat2[i][j] ;
 //  mat_pro[i][j] = mat1[i][j]*mat2[i][j] ;
}
}
//MATRIX MULTIPLICATION
//
//
//
//

i=0 ;
for(i;i<3;i++){
  j=0 ;
 for(j;j<3;j++){
  mat_pro[i][j] = ((mat1[i][0]*mat2[0][j]) + (mat1[i][1]*mat2[1][j]) +(mat1[i][2]*mat2[2][j])) ;
 //  mat_pro[i][j] = mat1[i][j]*mat2[i][j] ;
   }
   }
 //
 printf("MATRIX SUM\n") ;
i=0 ;
for(i;i<3;i++){
  j=0 ;
 for(j;j<3;j++){
 printf("%d ", mat_sum[i][j]) ;
}
printf("\n") ;
}
printf("\n\n") ;
printf("MATRIX MULTIPLICATION\n") ;
i=0 ;
for(i;i<3;i++){
  j=0 ;
 for(j;j<3;j++){
 printf("%d ", mat_pro[i][j]) ;
}
printf("\n") ;
}
printf("\n\n") ;
printf("MATRIX DIFFERENCE\n") ;
i=0 ;
for(i;i<3;i++){
  j=0 ;
 for(j;j<3;j++){
 printf("%d ", mat_diff[i][j]) ;
}
printf("\n") ;
}
printf("\n\n") ;

return 0 ;
}