// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value)
{
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      ++count;
      int l_val = arr[left];
      int r_val = arr[right];
      while (left < right && arr[left] == l_val) ++left;
      while (left < right && arr[right] == r_val) --right;
    }
    else if (sum < value) {
      ++left;
    }
    else {
      --right;
    }
  }
  return count;
}

int binarySearch(int* arr, int start, int end, int target)
{
  int left = start, right = end - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int countPairs3(int* arr, int len, int value)
{
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    int complement = value - arr[i];
    if (complement < 0)
      continue;
    int index = binarySearch(arr, i + 1, len, complement);
    if (index != -1)
      ++count;
  }
  return count;
}
