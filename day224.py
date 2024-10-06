//1813. Sentence Similarity III


class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split(' ')
        s2 = sentence2.split(' ')
        if len(s1) > len(s2):
            s1, s2 = s2, s1
            
        lcp = 0
        lcs = 0
        for w1, w2 in zip(s1, s2):
            if w1 != w2:
                break
            lcp += 1
        
        for w1, w2 in zip(s1[::-1], s2[::-1]):
            if w1 != w2:
                break
            lcs += 1
        '''
        note: s1 is smaller words.
        condition 1: 
			if (lcp + lcs) == len(s1), it means 
            [...lcp i, x....x, lcs j ...] 
            longest common prefix i
            longest common suffix j 
            and we can insert [x...x] 
        condition 2:
            if (lcp + lcs) > len(s1), it means 
            s1 have the same to s2
            it don't have [x...x] words in the middle.
        '''
        return (lcp + lcs) >= len(s1)
