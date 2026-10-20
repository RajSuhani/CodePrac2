class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        ans = 0

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            possible = True

            for start in range(0, n, k):
                arr = nums[start:start + k]
                sorted_arr = sorted(arr)

                if not any(
                    arr[i:] + arr[:i] == sorted_arr
                    for i in range(k)
                ):
                    possible = False
                    break

            if possible:
                ans += k

        return ans