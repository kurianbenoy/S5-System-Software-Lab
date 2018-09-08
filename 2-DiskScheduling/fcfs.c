#include <stdio.h>
#include <math.h>
void main()
{
  int n, i, A[50], st[50], sum = 0; 
  printf("Enter the number of positions: ");
  scanf("%d", &n);
  A[0] = 0;               
  for (i = 0; i <= n; i++) 
    st[i] = 0;
  printf("\nEnter the positions\n"); 
  for (i = 1; i <= n; i++)           
  {
    scanf("%d", &A[i]);            
    st[i] += abs(A[i] - A[i - 1]); 
  }
  for (i = 1; i <= n; i++)
  {
    sum += st[i]; //Finding the sum.
  }

  printf("The average number of movements is %d\n", sum / n);
  printf("The total number of movements is %d\n", sum);
}
