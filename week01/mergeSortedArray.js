var merge = function (nums1, m, nums2, n) {
  let totalIndex = m + n - 1;
  m = m - 1;
  n = n - 1;

  while (m >= 0 && n >= 0) {
    if (nums1[m] > nums2[n]) {
      nums1[totalIndex] = nums1[m];
      m--;
    } else {
      nums1[totalIndex] = nums2[n];
      n--;
    }
    totalIndex--;
  }

  while (n >= 0) {
    nums1[totalIndex] = nums2[n];
    totalIndex--;
    n--;
  }
};
