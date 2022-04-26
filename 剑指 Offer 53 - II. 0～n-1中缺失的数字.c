int missingNumber(int* nums, int numsSize){
    int low, mid, high;
    low = 0, high = numsSize-1;
    while(low < high){
        mid = (low+high)/2;
        if(nums[mid] > mid)
            high = mid - 1;
        else if(nums[mid] == mid)
            low = mid + 1;
    }
    if(nums[low] != low)
        return low;
    else
        return high+1;
}
