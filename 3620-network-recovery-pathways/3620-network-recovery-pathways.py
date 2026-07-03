class Solution:
    def findMaxPathScore(self, edges, online, k):
        n = len(online)

        graph = [[] for _ in range(n)]
        indegree = [0] * n
        mx = 0

        for u, v, c in edges:
            graph[u].append((v, c))
            indegree[v] += 1
            mx = max(mx, c)

       
        q = deque(i for i in range(n) if indegree[i] == 0)
        topo = []

        while q:
            u = q.popleft()
            topo.append(u)

            for v, _ in graph[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)

        def check(limit):
            dp = [inf] * n
            dp[0] = 0

            for u in topo:
                if dp[u] == inf:
                    continue

                if u != 0 and u != n - 1 and not online[u]:
                    continue

                for v, cost in graph[u]:
                    if cost < limit:
                        continue

                    if v != n - 1 and not online[v]:
                        continue

                    if dp[u] + cost < dp[v]:
                        dp[v] = dp[u] + cost

            return dp[n - 1] <= k

        if not check(0):
            return -1

        ans = 0
        lo, hi = 0, mx

        while lo <= hi:
            mid = (lo + hi) // 2

            if check(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans