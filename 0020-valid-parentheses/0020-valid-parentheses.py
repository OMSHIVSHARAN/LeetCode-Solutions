class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mp = {')': '(', ']': '[', '}': '{'}

        for c in s:
            if c not in mp:
                stack.append(c)
            elif not stack or stack.pop() != mp[c]:
                return False

        return not stack