// Find the element location from the array
//
// Input:- Array of elements (arr) and and an element (item) to be search
// Output:- The location of the element after searching
// Data Strucutre Used:- array
//
// Start
// 1. Accept the size of the elements in n
// 2. Accept n elements in arr
// 3. Accept the element to be searched in item
// 4. Iterate till the end of the array
// 5. if the element is equal to the value in item print the location+1 and exit out
// 6. else search the next elements
// 7. if the element is not found even after searching the whole array print "element not found"
// Stop

// Time Complexity
// Best Case :- O(1)
// Average Case :- O(n/2)
// Worst Case :- O(n)

// Space Complexity
// O(1)

# include <stdio.h>
# include <stdlib.h>
int linear_search(int *p,int size,int item);
int main(){
  int *arr;
  int n,item;
  printf("%s","Enter the size of the array: " );
  scanf("%d",&n );
  arr = (int *)malloc((n)*sizeof(int));
  printf("Enter the elements in the array: ");
  for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
  }
  printf("%s","Enter the element to search: " );
  scanf("%d",&item );
  int loc = linear_search(arr,n,item);
  if(loc == -1){
    printf("%d - Element not Found\n",item );
  }else{
    printf("Element %d found in position %d\n",item,loc+1 );
  }
  return 0;
}
int linear_search(int *p,int size,int item){
  for (int i = 0; i < size; i++) {
    if(p[i]==item){
      return i;
    }
  }
  return -1;
}


// Output
// Enter the size of the array: 9
// Enter the elements in the array: 12 432 127 123 5345 1232 434 112 102
// Enter the element to search: 123
// Element 123 found in position 4
