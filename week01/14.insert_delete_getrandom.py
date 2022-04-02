#O(1) space

class RandomizedSet:

    def __init__(self):
        self.randomizedSet = set()

    def insert(self, val: int) -> bool:
        if val not in self.randomizedSet:
            self.randomizedSet.add(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.randomizedSet:
            self.randomizedSet.remove(val)
            return True
        return False

    def getRandom(self) -> int:
        return random.choice(list(self.randomizedSet))


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()