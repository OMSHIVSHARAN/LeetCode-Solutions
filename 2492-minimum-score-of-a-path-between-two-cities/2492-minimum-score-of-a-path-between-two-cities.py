class Solution:
    def minScore(self, n: int, roads: list[list[int]]) -> int:
        graph = defaultdict(list)

        for u, v, d in roads:
            graph[u].append((v, d))
            graph[v].append((u, d))

        ans = float("inf")
        visited = set()
        q = deque([1])
        visited.add(1)

        while q:
            u = q.popleft()

            for v, d in graph[u]:
                ans = min(ans, d)

                if v not in visited:
                    visited.add(v)
                    q.append(v)

        return ans