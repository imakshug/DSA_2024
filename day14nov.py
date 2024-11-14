#2064. Minimized Maximum of Products Distributed to Any Store
class Solution:
    def isItPossible(self,n,quantities,mid):
        stores = 0
        for prod in quantities:
            stores+=prod//mid
            stores+=1 if prod%mid else 0
            if stores>n:
                return False
        return True
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        l = 1
        r = sum(quantities)
        ans = 0
        while l<=r:
            mid = (l+r)//2
            res = self.isItPossible(n,quantities,mid)
            if res:
                ans = mid
                r = mid-1
            else:
                l = mid+1
        return ans  
