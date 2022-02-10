#include<iostream> 
using namespace std; 
  
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) 
{ 
    int i=0, j=0, k=0; 
  
    // Traverse both array 
    while (i<n1 && j <n2) 
    { 
        //Check if current element of first array is smaller than current element of second array. 
		//If yes, store first array element and increment first array index. 
		//Otherwise do same with second array.
        if (arr1[i]<arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    } 
  
    // Store remaining elements of first array 
    while (i<n1) 
        arr3[k++] = arr1[i++]; 
  
    // Store remaining elements of second array 
    while (j<n2) 
        arr3[k++] = arr2[j++]; 
} 
  
int main() 
{ 
    int arr1[] = {1, 2, 15, 57}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
  
    int arr2[] = {12, 45, 67, 84}; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 
  
    int arr3[n1+n2]; 
    mergeArrays(arr1, arr2, n1, n2, arr3); 
  
    cout << "After merging" <<endl; 
    for (int i=0; i<n1+n2; i++) 
        cout << arr3[i] << " "; 
  
    return 0; 
} 
