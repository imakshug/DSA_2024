//2696. Minimum String Length After Removing Substrings

class Solution:
    def minLength(self, s: str) -> int:
        i, j = 0, 2
        while True:
            flag = False  
            while j <= len(s):
                if s[i:j] == 'AB' or s[i:j] == 'CD':
                    flag = True  # Found 'AB' or 'CD'
                    s = s[:i] + s[j:]
                    i, j = 0, 2
                else:
                    i += 1
                    j += 1
            if not flag:
                break
            i, j = 0, 2

        return len(s)  
        
