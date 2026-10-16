class Solution(object):
    def sumCounts(self, nums):
        MOD = 10**9 + 7
        n = len(nums)
        last = {}
        tree = [0] * (4 * n)
        lazy = [0] * (4 * n)

        def update(node, start, end, l, r, val):
            if l > end or r < start:
                return

            if l <= start and end <= r:
                tree[node] += val * (end - start + 1)
                lazy[node] += val
                return

            mid = (start + end) // 2
            if lazy[node]:
                for child in (node * 2, node * 2 + 1):
                    length = (mid - start + 1) if child == node * 2 else (end - mid)
                    tree[child] += lazy[node] * length
                    lazy[child] += lazy[node]
                lazy[node] = 0

            update(node * 2, start, mid, l, r, val)
            update(node * 2 + 1, mid + 1, end, l, r, val)
            tree[node] = tree[node * 2] + tree[node * 2 + 1]

        def query(node, start, end, l, r):
            if l > end or r < start:
                return 0
            if l <= start and end <= r:
                return tree[node]

            mid = (start + end) // 2
            if lazy[node]:
                for child in (node * 2, node * 2 + 1):
                    length = (mid - start + 1) if child == node * 2 else (end - mid)
                    tree[child] += lazy[node] * length
                    lazy[child] += lazy[node]
                lazy[node] = 0

            return (
                query(node * 2, start, mid, l, r)
                + query(node * 2 + 1, mid + 1, end, l, r)
            )

        ans = 0
        sum_distinct = 0

        for i, x in enumerate(nums):
            prev = last.get(x, -1)
            update(1, 0, n - 1, prev + 1, i, 1)

            sum_distinct = query(1, 0, n - 1, 0, i)
            ans = (ans + sum_distinct * sum_distinct) % MOD
            last[x] = i

        return ans