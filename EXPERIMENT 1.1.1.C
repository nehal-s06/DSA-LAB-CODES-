#include<stdio.h>

int main() {
	int n, key, pos = -1;

	//Read size of an array
	scanf("%d" , &n);

	int arr[n];

	//Read arrasy elements
	for (int i = 0; i < n; i++) {
		scanf("%d" , &arr[i]);
	}

	//Read search element
	scanf("%d" , &key);

	// Linear search 
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			pos = i;  // 0-indexed position
			break;
		}
	}
	//Output
	if (pos != -1) {
		printf("found at position %d\n" , pos);
	} else {
		printf("%d not found\n" , key);
	}
	return 0;
}
