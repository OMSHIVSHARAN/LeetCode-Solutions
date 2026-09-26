class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        return (lambda d: "".join(d.get(w, "?") if i & 1 else w for i, w in enumerate(s.replace(")", "(").split("("))))(dict(knowledge))