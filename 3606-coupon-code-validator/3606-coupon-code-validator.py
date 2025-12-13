class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        result = []
        for cd, business, active in zip(code, businessLine, isActive):
            if not cd:
                continue
            if active is False:
                continue
            if business not in ["electronics", "grocery", "pharmacy", "restaurant"]:
                continue
            is_invalid_code = all(c.isalnum() or c == '_' for c in cd)
            if not is_invalid_code:
                continue
            result.append((business, cd))
        
        result.sort()

        return [b for a,b in result]
        