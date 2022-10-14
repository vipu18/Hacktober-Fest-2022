//github - akrishna5

#include<stdio.h>
int main()
{
   int arr[5][2];
   arr[0][0] = 5; arr[0][1] = 6;
   arr[1][0] = 7; arr[1][1] = 8;
   arr[2][0] = 9; arr[2][1] = 6;
   arr[3][0] = 6; arr[3][1] = 5;
   arr[4][0] = 8; arr[4][1] = 7;

   for(int i=0; i<5; i++){
      for(int j=i+1; j<5; j++){
         if(arr[i][0]==arr[j][1] && arr[i][1]==arr[j][0])
           printf("(%d, %d) ", arr[i][0], arr[i][1]);
      }
   }
   return 0;
}
