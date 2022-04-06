class RandomizedSet:

    def __init__(self):
        
        self.number_map = dict()
        self.number_list = []

    def insert(self, val):
        if  val in self.number_map:
            return False
        
        self.number_list.append(val)
        self.number_map[val] = len(self.number_list)-1
        return True
                 

    def remove(self, val) :
        if val  not in self.number_map:
            return False
        pos=  self.number_map[val]
        last_value = self.number_list[-1]
        self.number_list[pos] = last_value
        self.number_map[last_value] = pos
        del self.number_map[val]
        self.number_list.pop()
        
        return True
    
    def getRandom(self) -> int:
        return random.choice(self.number_list)
        