#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int p1 = 0, p2 = 0;
    int m = 0,l = 0,k = 0;
    int arr[nums1Size + nums2Size];
    int q;
    double n;
    while (p1 < nums1Size || p2 < nums2Size)
    {
         if (p1 == nums1Size) 
        {
           q = nums2[p2++];
        } 
        else if (p2 == nums2Size) 
        {
            q = nums1[p1++];
        } 
        else if (nums1[p1] < nums2[p2]) 
        {
            q = nums1[p1++];
        } 
        else 
        {
            q = nums2[p2++];
        }
        arr[p1 + p2 - 1] = q;
    }
    m = nums1Size + nums2Size;
    if(m == 1) return arr[m-1];
    else
    {
        if(m%2 == 0)
        {
            n = (arr[m/2] + arr[m/2-1])/2.0;
        }
        else 
        {
            n = arr[m/2];
        }
    }
    return n;
}


int main()
{
    int arr1[] = {1,3};
    int arr2[] = {2,4};
    int sz1 = sizeof(arr1)/sizeof(arr1[0]);
    int sz2 = sizeof(arr2)/sizeof(arr2[0]);
    double mid = findMedianSortedArrays(arr1,sz1,arr2,sz2);
     printf("%f",mid);
    return 0;
}

