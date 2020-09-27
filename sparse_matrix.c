// Write a program to enter two matrices in normal form.
// Write a function to convert two matrices to tuple form and display it.
// Also find the transpose of the two matrices represented in tuple form and display it.
// Find the sum of the two matrices in tuple form and display the sum in tuple form

// Matrices -> Sparse -> Transpose -> Sum

// Input:- Two Matrix
// Output:- Transpose and Sum
// Data Strucutre Used:- Array

// Start
// 1. Accept the two matrix in normal form and R is the Resultant Matrix
// 2. Traverse throught the matrix such that i starts from 1
// 3. find non zero values
// 4. Store it's row in R[i][0] and coloumn in R[i][1] and value in R[i][2]
// 5.   R[k].coeff = P[i].coeff+Q[j++].coeff
// 6.   R[k++].exp = P[i++].exp
// 7. Store R[0][0] = num of rows
// 8. Store R[0][1] = num of cols
// 9. Store R[0][0] = i (Number of Non-zerors)
// 10.Print the resultant Sparse Representation


// 11. Function Transpose(int sp[][3])
// 12. check whether sp[0][2] is 0: then return "No elements"
// 13. copy sp[0][0] in spt[0][0]
// 14. copy sp[0][1] in spt[0][1]
// 15. copy sp[0][2] in spt[0][2]
// 16. k = 1
// 17. loop till i=0 to number of cols
// 18. Iterate till the non zero value numbers
// 19. if i == a[j][i]
// 20. Insert to Retrun Array
// 21. k++
// 22. Return Resultant Array


// 23. Function Addition(int sp1[][3],int sp2[][3])
// 24. if matrixes doesn't match in size(rows and coloumn are equal) "Invalid Operation"
// 25. while(k1<to_no_non_zeros_1 and k1<to_no_non_zeros_2)
// 26. if row_1 < row_2
// 27.  copy the data of row_1 to Resultant
// 28. if row_1 > row_2
// 29.  copy the data of row_2 to Resultant
// 30 else
// 31  if col_1 > col_2
// 32   copy the data of col_1 to Resultant
// 33  if col_1 < col_2
// 34   copy the data of col_2 to Resultant
// 35  else
// 36    Add the values and insert to Resultant
// 37  Print the added Representation
// Stop

// Time Complexity
// Sparse Mat Conv
// Best Case :- O(n*m) ; n row and m coloumn
// Average Case :- O(n*m); n row and m coloumn
// Worst Case :- O(n*m); n row and m coloumn

// Space Complexity
// O(n*m)

// Transpose
// Worst Case :- O(col*no.non zeros) ;

// Space Complexity
// O(no.non zeros*3)

// Addition
// Worst Case :- O(n+m); Sum of count of non-zeros

// Space Complexity
// O(n+m)


#include <stdio.h>
# define MAX 5
# define SP_MAX 20
void acceptMatrix(int *p,int *t,int M[][MAX]){
    printf("Enter the number of rows: ");
    scanf("%d",p);
    printf("Enter the number of cols: ");
    scanf("%d",t);
    printf("Enter the elements: ");
    for (int i = 0; i < *p; i++) {
        for (int j = 0; j < *t; j++) {
            scanf("%d",&M[i][j]);
        }
    }
}
// void convertToSparse(int row,int col,int *m,int sp[][3]){
//     sp[0][0] = row;
//     sp[0][1] = col;
//     int k = 1;
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             if(*(m+(col*i)+j) != 0){
//                 sp[k][0] =i;
//                 sp[k][1] =j;
//                 sp[k][2] =*(m+(col*i)+j);
//                 k++;
//             }
//         }
//     }
//     sp[0][2] = k-1;
//     printf("%d\n", sp[0][2]);
// }
void printSparse(int sp[][3]){
    printf("Row:- %d\tCol:- %d\tNon-Zero:- %d\t\n",sp[0][0],sp[0][1],sp[0][2]);
    for(int i=1;i<=sp[0][2];i++){
        printf("%d\t%d\t%d\t\n",sp[i][0],sp[i][1],sp[i][2]);
    }
    printf("\n");
}
void transpose(int sp[][3]){
  int n = sp[0][2];
  if(n==0){
    printf("%s\n","Invalid Operation Size of Non-Zero Elem is 0" );
    return;
  }
  int spt[SP_MAX][3];
  int k =1;
  spt[0][1] = sp[0][0];
  spt[0][0] = sp[0][1];
  spt[0][2] = sp[0][2];
  for (int i = 0; i < sp[0][1]; i++) {
      for (int j = 1; j <= n; j++) {
          if(sp[j][1] == i){
              spt[k][0] =i;
              spt[k][1] =sp[j][0];
              spt[k][2] =sp[j][2];
              k++;
          }
      }
  }
  printSparse(spt);
}
void addition(int sp1[][3],int sp2[][3]){
  if(sp1[0][0]!=sp2[0][0] && sp1[0][1]!=sp2[0][1]){
    printf("%s\n","Invalid Operation Matrix of Diff Size");
    return;
  }
  int added[2*SP_MAX][3];
  int count = 1;
  int i = 1;
  int j = 1;
  added[0][0] = sp1[0][0];
  added[0][1] = sp1[0][1];
  while(i<=sp1[0][2] && j<=sp2[0][2]){
    if(sp1[i][0]<sp2[j][0]){
      added[count][0] = sp1[i][0];
      added[count][1] = sp1[i][1];
      added[count][2] = sp1[i][2];
      i++;
      count++;
    }
    else if(sp1[i][0]>sp2[j][0]){
      added[count][0] = sp2[j][0];
      added[count][1] = sp2[j][1];
      added[count][2] = sp2[j][2];
      j++;
      count++;
    }
    else {
      if(sp1[i][1]<sp2[j][1]){
        added[count][0] = sp1[i][0];
        added[count][1] = sp1[i][1];
        added[count][2] = sp1[i][2];
        i++;
        count++;
      }
      else if(sp1[i][1]>sp2[j][1]){
        added[count][0] = sp2[j][0];
        added[count][1] = sp2[j][1];
        added[count][2] = sp2[j][2];
        j++;
        count++;
      }else{
        added[count][0] = sp2[j][0];
        added[count][1] = sp2[j][1];
        added[count][2] = sp2[j][2] + sp1[i][2];
        j++;
        i++;
        count++;
      }
    }
  }
  while(i<=sp1[0][2]){
    added[count][0] = sp1[i][0];
    added[count][1] = sp1[i][1];
    added[count][2] = sp1[i][2];
    i++;
    count++;
  }
  while(j<=sp2[0][2]){
    added[count][0] = sp2[j][0];
    added[count][1] = sp2[j][1];
    added[count][2] = sp2[j][2];
    j++;
    count++;
  }
  added[0][2] = --count;
  printSparse(added);
}
int main(){
    int m1[MAX][MAX],m2[MAX][MAX];
    int row1,row2,col1,col2;
    acceptMatrix(&row1,&col1,m1);
    acceptMatrix(&row2,&col2,m2);
    int sp[SP_MAX][3],sp2[SP_MAX][3];
    // convertToSparse(row1,col1,(int *)m1,sp1);
    // convertToSparse(row2,col2,m2,sp2);
    sp[0][0] = row1;
    sp[0][1] = col1;
    int k = 1;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            if(m1[i][j] != 0){
                sp[k][0] =i;
                sp[k][1] =j;
                sp[k][2] =m1[i][j];
                k++;
            }
        }
    }
    sp[0][2] = k-1;
    sp2[0][0] = row2;
    sp2[0][1] = col2;
    k = 1;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            if(m2[i][j] != 0){
                sp2[k][0] =i;
                sp2[k][1] =j;
                sp2[k][2] =m2[i][j];
                k++;
            }
        }
    }
    sp2[0][2] = k-1;
    printf("Sparse Matrix 1\n");
    printSparse(sp);
    printf("Sparse Matrix 2\n");
    printSparse(sp2);
    printf("Sparse Matrix 1 Transpose\n");
    transpose(sp);
    printf("Sparse Matrix 2 Transpose\n");
    transpose(sp2);
    printf("Sparse Matrix Sum\n");
    addition(sp,sp2);
    return 0;
}


// Output - 1
// Enter the number of rows: 3
// Enter the number of cols: 3
// Enter the elements: 1 2 3 4 5 6 7 8 9
// Enter the number of rows: Enter the number of cols: ^C
// C:\Users\niran>D:\PROJECTS\C++\Sorts\sparse_matrix.exe
// Enter the number of rows: 3
// Enter the number of cols: 3
// Enter the elements: 0 1 2 0 1 2 0 1 3
// Enter the number of rows: 3
// Enter the number of cols: 3
// Enter the elements: 0 0 0 0 0 1 0 1 2
// Sparse Matrix 1
// Row:- 3 Col:- 3 Non-Zero:- 6
// 0       1       1
// 0       2       2
// 1       1       1
// 1       2       2
// 2       1       1
// 2       2       3
//
// Sparse Matrix 2
// Row:- 3 Col:- 3 Non-Zero:- 3
// 1       2       1
// 2       1       1
// 2       2       2
//
// Sparse Matrix 1 Transpose
// Row:- 3 Col:- 3 Non-Zero:- 6
// 1       0       1
// 1       1       1
// 1       2       1
// 2       0       2
// 2       1       2
// 2       2       3
//
// Sparse Matrix 2 Transpose
// Row:- 3 Col:- 3 Non-Zero:- 3
// 1       2       1
// 2       1       1
// 2       2       2
//
// Sparse Matrix Sum
// Row:- 3 Col:- 3 Non-Zero:- 6
// 0       1       1
// 0       2       2
// 1       1       1
// 1       2       3
// 2       1       2
// 2       2       5


// Output - 2
// Enter the number of rows: 4
// Enter the number of cols: 4
// Enter the elements: 1 2 3 4
// 1 0 0 0
//  0 0 0 3
// 1 0 9 0
// Enter the number of rows: 1
// Enter the number of cols: 1
// Enter the elements: 9
// Sparse Matrix 1
// Row:- 4 Col:- 4 Non-Zero:- 8
// 0       0       1
// 0       1       2
// 0       2       3
// 0       3       4
// 1       0       1
// 2       3       3
// 3       0       1
// 3       2       9
//
// Sparse Matrix 2
// Row:- 1 Col:- 1 Non-Zero:- 1
// 0       0       9
//
// Sparse Matrix 1 Transpose
// Row:- 4 Col:- 4 Non-Zero:- 8
// 0       0       1
// 0       1       1
// 0       3       1
// 1       0       2
// 2       0       3
// 2       3       9
// 3       0       4
// 3       2       3
//
// Sparse Matrix 2 Transpose
// Row:- 1 Col:- 1 Non-Zero:- 1
// 0       0       9
//
// Sparse Matrix Sum
// Invalid Operation Matrix of Diff Size


// Output - 3
// Enter the number of rows: 1
// Enter the number of cols: 2
// Enter the elements: 1 1
// Enter the number of rows: 3
// Enter the number of cols: 4
// Enter the elements: 1 2 3 4
// 9 0 0 0
// 0 0 0 0
// Sparse Matrix 1
// Row:- 1 Col:- 2 Non-Zero:- 2
// 0       0       1
// 0       1       1
//
// Sparse Matrix 2
// Row:- 3 Col:- 4 Non-Zero:- 5
// 0       0       1
// 0       1       2
// 0       2       3
// 0       3       4
// 1       0       9
//
// Sparse Matrix 1 Transpose
// Row:- 1 Col:- 2 Non-Zero:- 2
// 0       0       1
// 1       0       1
//
// Sparse Matrix 2 Transpose
// Row:- 3 Col:- 4 Non-Zero:- 5
// 0       0       1
// 0       1       9
// 1       0       2
// 2       0       3
// 3       0       4
//
// Sparse Matrix Sum
// Invalid Operation Matrix of Diff Size

// Output - 4
// Enter the number of rows: 4
// Enter the number of cols: 4
// Enter the elements: 1 2 3 4
// 0 0 0 0
//  0 0 0 0
// 0 0 0 0
// Enter the number of rows: 4
// Enter the number of cols: 4
// Enter the elements:  1 0 0 0
//  0 0 3 0
// 0 1 0 2
// 0 0 0 0
// Sparse Matrix 1
// Row:- 4 Col:- 4 Non-Zero:- 4
// 0       0       1
// 0       1       2
// 0       2       3
// 0       3       4
//
// Sparse Matrix 2
// Row:- 4 Col:- 4 Non-Zero:- 4
// 0       0       1
// 1       2       3
// 2       1       1
// 2       3       2
//
// Sparse Matrix 1 Transpose
// Row:- 4 Col:- 4 Non-Zero:- 4
// 0       0       1
// 1       0       2
// 2       0       3
// 3       0       4
//
// Sparse Matrix 2 Transpose
// Row:- 4 Col:- 4 Non-Zero:- 4
// 0       0       1
// 1       2       1
// 2       1       3
// 3       2       2
//
// Sparse Matrix Sum
// Row:- 4 Col:- 4 Non-Zero:- 7
// 0       0       2
// 0       1       2
// 0       2       3
// 0       3       4
// 1       2       3
// 2       1       1
// 2       3       2
