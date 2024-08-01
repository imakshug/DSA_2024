// number of senior citizens

class Solution:
    def countSeniors(self, details: List[str]) -> int:
        c=0
        for i in details:
            if 60<int(i[11:13]):
                c=c+1 
        return c
        
