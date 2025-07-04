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

	{
		int nums1[] = {};
		int nums2[] = {1};
		printf("%f\n", findMedianSortedArrays(nums1, 0, nums2, 1));
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
	int combinedSize = nums1Size + nums2Size;
	int combinedNums[combinedSize];
	int k;
	int nums1Done = 0, nums2Done = 0;

	if (nums1Size == 0) {
		nums1Done = 1;
	}
	else if (nums2Size == 0) {
		nums2Done = 1;
	}

	int i, j;
	
	i = j = k = 0;
	while (k < combinedSize / 2 + 1) {
		int a, b;


		if (nums1Done) {
			combinedNums[k] = nums2[j];
			j++;

		}
		else if (nums2Done) {
			combinedNums[k] = nums1[i];
			i++;
		}
		else {
			a = nums1[i];
			b = nums2[j];
		
			if (a < b) {
				combinedNums[k] = a;
				if (i == nums1Size - 1) {
					nums1Done = 1;
				}
				else {
					i++;
				}
			}
			else {
				combinedNums[k] = b;
				if (j == nums2Size - 1) {
					nums2Done = 1;
				}
				else {
					j++;
				}
			}
			printf("k: %d\n", combinedNums[k]);
			k++;
		}
	}
	k--;
	return (combinedSize % 2) ? combinedNums[k] : ((double) combinedNums[k] + combinedNums[k-1]) / 2.0;
}
