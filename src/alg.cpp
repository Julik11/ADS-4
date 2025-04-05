// Copyright 2021 NNTU-CS
#include <algorithm>

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
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum == value) {
      int leftVal = arr[left];
      int rightVal = arr[right];

      int leftCount = 0;
      while (left < right && arr[left] == leftVal) {
        left++;
        leftCount++;
      }

      int rightCount = 0;
      while (right >= left && arr[right] == rightVal) {
        right--;
        rightCount++;
      }

      count += leftCount * rightCount;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];

    auto lower = std::lower_bound(arr + i + 1, arr + len, complement);
    auto upper = std::upper_bound(arr + i + 1, arr + len, complement);

    count += upper - lower;
  }
  return count;
}




