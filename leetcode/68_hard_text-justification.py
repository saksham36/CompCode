class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        self.words = words
        self.max_width = maxWidth

        i = 0
        result = []
        while i < len(words):
            current_line = self.get_words(i)
            i += len(current_line)
            result.append(self.create_line(current_line, i))
        return result
    def get_words(self, i):
        words_in_line = []
        current_length = 0
        while i < len(self.words) and current_length + len(self.words[i]) <= self.max_width:
            words_in_line.append(self.words[i])
            current_length += len(self.words[i]) + 1
            i += 1
        return words_in_line
    
    def create_line(self, words_in_line, i):
        # every word except last word in line accounts for len(w) + 1 
        base_length = -1
        for w in words_in_line:
            base_length += len(w) + 1
        
        extra_spaces = self.max_width - base_length
        num_buckets = len(words_in_line) - 1

        if num_buckets == 0 or i == len(self.words):
            return " ".join(words_in_line) + " " * extra_spaces

        spaces_per_bucket = extra_spaces // num_buckets
        remainder_spaces = extra_spaces % num_buckets

        for j in range(remainder_spaces):
            words_in_line[j] += " "
        
        for j in range(num_buckets):
            words_in_line[j] += " " * spaces_per_bucket
        
        return " ".join(words_in_line)
