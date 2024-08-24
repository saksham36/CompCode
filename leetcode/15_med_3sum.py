from collections import defaultdict
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        negative_dict = defaultdict(int)
        positive_dict = defaultdict(int)
        zero_counter = 0

        for elem in nums:
            if elem < 0: 
                negative_dict[elem] += 1
            elif elem > 0:
                positive_dict[elem] += 1
            else:
                zero_counter += 1
        
        results = []
        if zero_counter:
            if zero_counter > 2:
                results.append((0,0,0))
            for neg in negative_dict:
                if -neg in positive_dict:
                    results.append((neg, 0, -neg))

        # If there is only negative or positive numbers, can't have other solutions
        if len(negative_dict) == 0 or len(positive_dict) == 0:
            return results

        for first_dict, second_dict in ((negative_dict, positive_dict), (positive_dict,negative_dict)):
            first_dict_list = list(first_dict.items())
            for idx, (first_num, first_count) in enumerate(first_dict_list):
                for second_num, second_count in first_dict_list[idx:]:
                    if(first_num == second_num and first_count > 1) or first_num != second_num:
                        if -first_num - second_num in second_dict:
                            results.append((first_num, second_num, -first_num - second_num))
        
        return results



            



        