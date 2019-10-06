/* There are two sorted arrays nums1 and nums2 of size m and n respectively.

   Find the median of the two sorted arrays. The overall run time complexity
   should be O(log (m+n)).

   You may assume nums1 and nums2 cannot be both empty.
*/
#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int
							  nums2Size);

int main()
{
	{
		int nums1[] = {1, 2};
		int nums2[] = {3, 4};
		printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 2));
	}
	{
		int nums1[] = {1, 3};
		int nums2[] = {2};
		printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 1));
	}
	{
		int nums1[] = {1, 3, 6, 9};
		int nums2[] = {4, 6, 22};
		printf("%f\n", findMedianSortedArrays(nums1, 4, nums2, 3));
	}
	{
		int nums1[] = {1};
		int nums2[] = {1};
		printf("%f\n", findMedianSortedArrays(nums1, 1, nums2, 1));
	}	
	return 0;
}

/*
Example:
nums1 = {1, 3, 5, 9}
nums2 = {4, 6, 22}

1 < 4 -> 1
i++
3 < 4 -> 3
i++
5 > 4 -> 4
j++
5 < 6 -> 5
i++
9 > 6 -> 6
j++
9 < 22 -> 9
i++ yields overflow

nums1 = {1, 2}
nums2 = {3, 4, 5}

1 < 3 -> 1
i++
2 < 3 -> 2
i++ yields overflow -> nums1Done = 1
3, 4, 5

nums1 = {1, 3}
nums2 = {2}

1 < 2 -> 1
i++
3 > 2 -> 2
j++ yields overflow -> nums2Done = 1


*/


double findMedianSortedArrays(int *nums1, int nums1Size,
							  int *nums2, int nums2Size)
{
	double median(int *, int);
	int combinedSize = nums1Size + nums2Size;
	int combinedNums[combinedSize];
		
	if (nums1Size == 0) {
		return median(nums2, nums2Size);
	}
	else if (nums2Size == 0) {
		return median(nums1, nums1Size);
	}
	else {
		int i, j, k;
	
		i = j = k = 0;
//		printf("i: %d\t\tj: %d\n", i, j);			

		int nums1Done = 0, nums2Done = 0;
		while (k < nums1Size + nums2Size && i < nums1Size && j < nums2Size) {
			int a = nums1[i], b = nums2[j];
			printf("i: %d\t\tj: %d\t\ta: %d\t\tb: %d\t\t", i, j, a, b);

			if (nums1Done) {
				printf("\t1\t");
				combinedNums[k] = b;
				j++;
			}
			else if (nums2Done) {
				printf("\t2\t");				
				combinedNums[k] = a;
				i++;
			}
			else if (a < b) {
				printf("\t3\t");				
				combinedNums[k] = a;
				if (i == nums1Size - 1) {
					nums1Done = 1;
				}
				else {
					i++;
				}
			}
			else {
				printf("\t4\t");			
				combinedNums[k] = b;
				if (j == nums2Size - 1) {
					nums2Done = 1;
				}
				else {
					j++;
				}
			}
			printf("k: %d\t\tv[k]: %d\n", k, combinedNums[k]);			
			k++;
		}
	}
	return median(combinedNums, combinedSize);
}

double median(int *v, int s)
{
	for (int i = 0; i < s; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
	if (s % 2 == 0) {
		return ((double) (v[s / 2 - 1] +
						  v[s / 2])) / 2.0;
	}
	return v[s / 2];
}







/* double findMedianSortedArrays(int *nums1, int nums1Size, */
/* 							  int *nums2, int nums2Size) */
/* { */
/* 	double median(int *, int); */
/* 	int combinedSize = nums1Size + nums2Size; */
/* 	int combinedNums[combinedSize]; */
/* 	if (nums1Size == 0) { */
/* 		return median(nums2, nums2Size); */
/* 	} */
/* 	else if (nums2Size == 0) { */
/* 		return median(nums1, nums1Size); */
/* 	} */
/* 	else { */
/* 		int i, j, k; */
	
/* 		i = j = k = 0; */
/* //		printf("i: %d\t\tj: %d\n", i, j);			 */
/* 		combinedNums[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++]; */

/* 		int nums1Done = 0, nums2Done = 0; */
/* 		while (k < nums1Size + nums2Size) { */
/* 			printf("i: %d\t\tj: %d\t\t", i, j); */
/* 			int a = nums1[i], b = nums2[j]; */


/* 			if (nums1Done) { */
/* 				combinedNums[k] = b; */
/* 				j++; */
/* 			} */
/* 			else if (nums2Done) { */
/* 				combinedNums[k] = a; */
/* 				i++; */
/* 			} */
/* 			else if (i == nums1Size - 1 && a < b) { */
/* 				printf("  1  "); */
/* 				combinedNums[k] = a; */
/* 				nums1Done = 1; */
/* 			} */
/* 			else if (j == nums1Size - 1 && b < a) { */
/* 				printf("  2  "); */
/* 				combinedNums[k] = b; */
/* 				nums2Done = 1; */
/* 			} */
/* 			else if (a < b) { */
/* 				printf("  3  "); */
/* 				combinedNums[k] = a; */
/* 				if (i == nums1Size) { */
/* 					nums1Done = 1; */
/* 				} */
/* 				else { */
/* 					i++; */
/* 				} */
/* 			} */
/* 			else { */
/* 				printf("  4  "); */
/* 				combinedNums[k] = b; */
/* 				if (j == nums2Size) { */
/* 					nums2Done; */
/* 				} */
/* 				else { */
/* 					j++; */
/* 				} */
/* 			} */
/* 			printf("k: %d\t\tv[k]: %d\n", k, combinedNums[k]);			 */
/* 			k++; */
/* 		} */
/* 	} */
/* 	return median(combinedNums, combinedSize); */
/* } */

/* double median(int *v, int s) */
/* { */
/* 	for (int i = 0; i < s; i++) { */
/* 		printf("%d ", v[i]); */
/* 	} */
/* 	printf("\n"); */
/* 	if (s % 2 == 0) { */
/* 		return ((double) (v[s / 2 - 1] + */
/* 						  v[s / 2])) / 2.0; */
/* 	} */
/* 	return v[s / 2]; */
/* } */
