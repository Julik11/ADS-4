// Copyright 2021 NNTU-CS
#include <algorithm>
#include <unordered_map>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  std::sort(arr, arr + len);
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int leftCount = 1, rightCount = 1;
        while (left + 1 < right && arr[left] == arr[left + 1]) {
          left++;
          leftCount++;
        }
        while (right - 1 > left && arr[right] == arr[right - 1]) {
          right--;
          rightCount++;
        }
        count += leftCount * rightCount;
        left++;
        right--;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  std::unordered_map<int, int> freq;
  int count = 0;

  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    if (freq.find(complement) != freq.end()) {
      count += freq[complement];
    }
    freq[arr[i]]++;
  }

  return count;
}





