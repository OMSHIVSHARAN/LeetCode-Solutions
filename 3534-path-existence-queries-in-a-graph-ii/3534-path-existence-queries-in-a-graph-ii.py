class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        order = sorted(range(n), key=lambda i: nums[i])
        vals = [nums[i] for i in order]

        pos = [0] * n
        for i, idx in enumerate(order):
            pos[idx] = i

        reach = [0] * n
        j = 0
        for i in range(n):
            while j < n and vals[j] - vals[i] <= maxDiff:
                j += 1
            reach[i] = j - 1

        LOG = n.bit_length()
        up = [reach]

        for _ in range(1, LOG):
            prev = up[-1]
            up.append([prev[prev[i]] for i in range(n)])

        ans = []

        for u, v in queries:
            a = pos[u]
            b = pos[v]

            if a == b:
                ans.append(0)
                continue

            if a > b:
                a, b = b, a

            if reach[a] >= b:
                ans.append(1)
                continue

            if reach[a] == a:
                ans.append(-1)
                continue

            cur = a
            steps = 0

            for k in range(LOG - 1, -1, -1):
                nxt = up[k][cur]
                if nxt < b and nxt != cur:
                    steps += 1 << k
                    cur = nxt

            cur = reach[cur]
            steps += 1

            if cur >= b:
                ans.append(steps)
            else:
                ans.append(-1)

        return ans