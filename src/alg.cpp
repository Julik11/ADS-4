// Copyright 2021 NNTU-CS

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
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int l_val = arr[left], r_val = arr[right];
      int l_count = 1, r_count = 1;

      while (left + 1 < right && arr[left + 1] == l_val) {
        l_count++;
        left++;
      }
      while (right - 1 > left && arr[right - 1] == r_val) {
        r_count++;
        right--;
      }
      if (l_val == r_val) {
        count += (l_count * (l_count - 1)) / 2;
      } else {
        count += l_count * r_count;
      }
      
      left++;
      right--;
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
    if (complement < 0) continue;
    int left = i + 1;
    int right = len - 1;
    
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] < complement) left = mid + 1;
      else right = mid - 1;
    }
    
    while (left < len && arr[left] == complement) {
      count++;
      left++;
    }
  }
  return count;
}



