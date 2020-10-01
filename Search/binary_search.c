// Find the element location from the array using binary search
//
// Input:- Sorted Array of elements (arr) and and an element (item) to be search
// Output:- The location of the element after searching
// Data Strucutre Used:- array
//
// Start
// 1. Accept the size of the elements in n
// 2. Accept n sorted elements in arr
// 3. Accept the element to be searched in item
// 4. Repeat the process(4,5,6,7,8) untill the size of subarray is zero
// 5. Find the midpoint of the array and compare it with item
// 6. If the element is found exit out the loop
// 7. If the element is lesser than the item set the starting of the subarray to midpoint+1
// 8. If the element is greater than the item set the ending of the subarray to midpoint-1
// 9. If the loop contidion is not fullfilled print "element not found"
// Stop

// Time Complexity
// Best Case :- O(1)
// Average Case :- O(log(n))
// Worst Case :- O(log(n))

// Space Complexity
// O(1)


# include <stdio.h>
# include <stdlib.h>
int binary_search(int *p,int size,int item);
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
  int loc = binary_search(arr,n,item);
  if(loc == -1){
    printf("%d - Element not Found\n",item );
  }else{
    printf("Element %d found in position %d\n",item,loc+1 );
  }
  return 0;
}
int binary_search(int *p,int size,int item){
  int low = 0;
  size -- ;
  while (low<=size) {
    // printf("size :- %d\n",size );
    // printf("low :- %d\n",low );
    int midpoint = (low+size)/2;
    // printf("%d\n",midpoint );
    if(p[midpoint]==item){
      return midpoint;
    }if(p[midpoint]<item){
      low = midpoint + 1;
    }else{
      size = midpoint - 1;
    }
  }
  return -1;
}

// Output
// Enter the size of the array: 12
// Enter the elements in the array: 1 2 3 4 5 6 7 7 8 9 945 23
// Enter the element to search: 8
// Element 8 found in position 9

// Enter the size of the array: 12
// Enter the elements in the array: 1 2 3 4 12 12312 31231 231423 32  12 3 31
// Enter the element to search: 1
// Element 1 found in position 1

// Enter the size of the array: 12
// Enter the elements in the array: 1 2 3 4 5 6 7 8 9 10 1 33
// Enter the element to search: 33
// Element 33 found in position 12

// Enter the size of the array: 15
// Enter the elements in the array: 12 341 123 43 123 12 312 3 123  123 1 23 1 1 2
// Enter the element to search: 99
// 99 - Element not Found
