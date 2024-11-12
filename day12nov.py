#2070. Most Beautiful Item for Each Query

class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        # Step 1: Sort items by price
        items.sort()  # Sorts the items based on their price in ascending order
        
        # Step 2: Prepare queries with their original indices
        # This allows us to restore the original order of results after sorting queries
        queries = sorted([(q, i) for i, q in enumerate(queries)])
        
        # Step 3: Initialize result array and variables
        res = [0] * len(queries)  # Result array to store maximum beauty for each query
        max_beauty = 0  # Variable to track the maximum beauty seen so far
        j = 0  # Pointer for iterating through items
        
        # Step 4: Process each query
        for q, i in queries:
            # While there are items that can be afforded (price <= query price)
            while j < len(items) and items[j][0] <= q:
                # Update max_beauty if the current item's beauty is greater
                max_beauty = max(max_beauty, items[j][1])
                j += 1  # Move to the next item
            
            # Store the maximum beauty found for this query in the correct index
            res[i] = max_beauty

        return res  # Return the list of maximum beauties for each query
