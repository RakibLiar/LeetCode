class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        return [k for _, k in sorted([(business, cd) for cd, business, active in zip(code, businessLine, isActive) if cd and active is True and business in ["electronics", "grocery", "pharmacy", "restaurant"] and all(c.isalnum() or c == '_' for c in cd)])]
        