#include <iostream>
#include <cmath>
using namespace std;

// Randomized quicksort without built-in random function

long int seed = 1234;
long int a = 1664525;
long int c = 1013904223;
long int m = pow(2, 32);
 
void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
 
int partition(int* arr, int lo, int hi) {
   int pivot = arr[hi];
   int i = lo - 1;
   int j = lo;
   while (j < hi) {
       if (arr[j] <= pivot) {
           i++;
           swap(&arr[i], &arr[j]);
       }
       j++;
   }
   swap(&arr[i + 1], &arr[hi]);
   return i + 1;
}
 
int partitionRandom(int* arr, int lo, int hi) {
   // Linear congruential generator
   // This yields a sequence of pseudo-randomized numbers
   cout << "Seed = " << seed << endl;
   long int r = (a * seed + c) % m;
   seed = r;
   r = lo + (r % (hi - lo));
   cout << "Random index, r = " << r << endl;
   swap(&arr[r], &arr[hi]);
   return partition(arr, lo, hi);
}
 
void quicksort(int* arr, int lo, int hi) {
   if (lo < hi) {
       int partitionIdx = partitionRandom(arr, lo, hi);
       quicksort(arr, lo, partitionIdx - 1);
       quicksort(arr, partitionIdx + 1, hi);
   }
}
 
int main() {
   int n;
   cout << "Enter number of elements in the array: ";
   cin >> n;
   cout << "Enter the elements of the array: ";
   int *arr = new int[n];
   for (int i = 0; i < n; i++) {
       cin >> arr[i];
   }
   quicksort(arr, 0, n - 1);
   cout << "Sorted array: ";
   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
   return 0;
}
