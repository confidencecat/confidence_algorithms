int lower_bound(int list[], int len, int key) {
	int start = 0, end = len - 1;
	int ans_index = len - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (list[mid] > key) {
			end = mid - 1;
			ans_index = mid;
		}
		else if(list[mid] < key) {
			start = mid + 1;
		}
		else {
			ans_index = mid;
			break;
		}
	}
	return ans_index;
}
