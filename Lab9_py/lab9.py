from tkinter.tix import Tree


class Name():
    def __init__(self, name = None):
        self.name = name

    def display(self):
        print(self.name)

class Plant(Name):
    def __init__(self, name = None, size = None):    
        Name.__init__(self, name)
        self.size = size
    
    def display(self):
        Name.display(self)
        print(self.size)

    def checkWeed(self):
        if (self.name == "Weed"): return True;
        return False;

    def __eq__(self, obj: object) -> bool:
        if(self.name == obj.name): return True;
        return False;

    def __lt__(self, obj: object) -> bool:
        if (self.name < obj.name): return True;
        return False;

    def __gt__ (self, obj: object) -> bool:
        if (self.name > obj.name): return True;
        return False;

class TreeNode(Plant):
    def __init__(self, name: str = None, size: int = None):
        Plant.init(self, name, size)
        self.left: TreeNode = None
        self.right: TreeNode = None

    def getLeft(self) -> object:
        return self.left
    
    def setLeft(self, left: object):
        self.left = left;
    
    def getRight(self) -> object:
        return self.right

    def setRight(self, right: object):
        self.right = right;


class BST:
    def __init__ (self):
        self.root: TreeNode = None

    def insert(self, root: TreeNode, inserting: TreeNode):
        if root is None:
            return inserting;
        else:
            if (inserting > root or inserting == root):
                root.setRight(insert(root.getRight(), inserting))

    

    


class Garden():
    def __init__(self, plants = None):
        self.plants = plants
        self.number = len(plants)
        self.capacity = 12
                

    def display(self):
        for p in self.plants:
            p.display()
        print("Capacity is:", self.capacity, "Currently have", self.number, "plants")

    def checkCapacity(self):
        if (self.number <= self.capacity):
            return True;
        return False;
    
    def removeWeeds(self):
        count = 0
        foundAny = True
        while (foundAny):
            foundAny = False
            for p in self.plants:
                if (p.checkWeed()):
                    self.plants.remove(p)
                    self.number -= 1
                    count += 1
                    foundAny = True
        return count

def main():
    plants = "Flower", "Tree", "Bush", "Shrub", "Weed", "Weed"
    allPlants = []
    for p in plants:
        size = int
        if (p == "Flower" or "Weed"): size = 1
        elif (p == "Shrub" or p == "Bush"): size = 2
        elif (p == "Tree"): size = 3
        else: size = 4
        allPlants.append(Plant(p, size))

    myGarden = Garden(allPlants)
    myGarden.display()
    print(myGarden.checkCapacity())
    print("Removed", myGarden.removeWeeds(), "weeds.")
    myGarden.display()

    return

if __name__ == "__main__":
    main()


