//1574. Shortest Subarray to be Removed to Make Array Sorted

int findLengthOfShortestSubarray(int* arr, int arrSize) {
    int l = 0, r = arrSize - 1;
    while (r > 0 && arr[r] >= arr[r - 1]) {
        r--;
    }
    int rmvLength = r;
    while (l < r && (l == 0 || arr[l] >= arr[l - 1])) {
        while (r < arrSize && arr[l] > arr[r]) {
            r++;
        }
        rmvLength = (rmvLength < r - l - 1) ? rmvLength : r - l - 1;
        l++;
    }
    return rmvLength;
}
