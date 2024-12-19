//769. Max Chunks To Make Sorted

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        chunks = 0
        r = 0
        l = 0
        findL = False
        for i in range(len(arr)):
            if arr[i] == l:
                findL = True
            r = max(r, arr[i])
            if r == i and findL:
                chunks += 1
                findL = False
                l = i + 1
                if i + 1 < len(arr):
                    r = arr[i + 1]


        return chunks 
