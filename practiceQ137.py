
from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        k = nums[0]

        if all(nums[i] == (k + i) % n for i in range(n)):
            d = (n - k) % n
            return min(d, n - d + 2)

        if all(nums[i] == (k - i) % n for i in range(n)):
            d = (n - k - 1) % n
            return 1 + min(d, n - d)

        return -1
