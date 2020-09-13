/*
PS : Find the 2nd max & 2nd min element from an array
*/

# include <stdio.h>

void Second_Max_Min(int arr[],int n){
   int mx = -999999999 , smx = -999999999 ;
   int mn = 999999999 , smn = 999999999 ;
   int  i = 0;
   for(i;i<n;i++){
       if(arr[i] > mx){
           smx = mx ;
           mx = arr[i] ;
       }
       if(arr[i] < mn){
           smn = mn ;
           mn = arr[i] ;
       }
       if(arr[i] > smx && arr[i] < mx){
           smx = arr[i] ;
       }
       if(arr[i] < smn && arr[i]>mn){
           smn = arr[i] ;
       }
   }
   
   printf("SECOND MAXIMUM ELEMENT OF ARRAY : %d\n",smx) ;
   printf("SECOND MINIMUM ELEMENT OF ARRAY : %d\n",smn) ;

}
int main(){
   
    // printf("Hello World") ;
    printf("Enter size of array : ") ;
    int n  ;
    scanf("%d",&n) ;
    printf("Enter array \n") ;
    int arr[n] ;
    int i = 0 ;
    for(i;i<n;i++){
        scanf("%d",&arr[i]) ;
    }

    Second_Max_Min(arr,n) ;


    return 0 ;
}
