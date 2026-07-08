class Solution:
    def sumAndMultiply(self, s: str, queries: list) -> list:
        MOD = 1_000_000_007
        m = len(s)
        digits = [ord(c) - 48 for c in s]
        
        
        nz = [1 if d else 0 for d in digits]
        sum_contrib = [d for d in digits] 
        
        prefix_cnt = [0] * (m + 1)
        prefix_sum = [0] * (m + 1)
        prefix_val = [0] * (m + 1)
        
       
        pc = list(accumulate(nz))
        ps = list(accumulate(sum_contrib))
        prefix_cnt[1:] = pc
        prefix_sum[1:] = ps
        
        
        val = 0
        pv = prefix_val
        for i in range(m):
            d = digits[i]
            if d:
                val = (val * 10 + d) % MOD
            pv[i + 1] = val
        
        
        maxcnt = pc[-1] if pc else 0
        pow10 = [1] * (maxcnt + 1)
        for i in range(1, maxcnt + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD
        
        ans = [0] * len(queries)
        for idx, (l, r) in enumerate(queries):
            r1 = r + 1
            cnt = prefix_cnt[r1] - prefix_cnt[l]
            if cnt == 0:
                continue
            x = (pv[r1] - pv[l] * pow10[cnt]) % MOD
            dsum = prefix_sum[r1] - prefix_sum[l]
            ans[idx] = (x * dsum) % MOD
        
        return ans