int lower_bound(int list[], int len, int key) {
    int start = 0, end = len - 1;
    int ans_index = len;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (list[mid] >= key) {
            end = mid - 1;
            ans_index = mid;
        } else {
            start = mid + 1;
        }
    }
    return ans_index;
}
