// filling bookcases shelves

class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        situations = [(books[0][0], books[0][1], 0)] # (cur_width, cur_height, above_height)

        for i in range(1, len(books)):
            new_situations = []
            cur_min_height = inf
            for s in situations:
                cur_min_height = min(cur_min_height, s[1]+s[2])
                if s[0] + books[i][0] <= shelfWidth:
                    new_situations.append((s[0]+books[i]…                                                                                                                   
            new_situations.append((books[i][0], books[i][1], cur_min_height))
            situations = new_situations
                                                                                                                                                            
        return min([s[1]+s[2] for s in situations])
                                                         
