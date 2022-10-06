class Solution(object):
    def equalFrequency(self, word):
	
        counter = Counter(word)
        for c in word:
            counter[c] -= 1
            
            if counter[c] == 0:
                counter.pop(c)
            
            if len(set(counter.values())) == 1:
                return True

            counter[c] += 1
        return False