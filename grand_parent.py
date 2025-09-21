# Simple family relationship using dictionary

family = {
    "John": {"parent": None, "children": []},
    "Mary": {"parent": None, "children": []},
    "Joe": {"parent": None, "children": []}
}

# Function to set parent-child relationship
def set_parent(parent, child):#john mary    mary joe
    family[child]["parent"] = parent
    print("parent ",parent)
    family[parent]["children"].append(child)
    print("family ",family)

# Function to find grandparent
def find_grandparent(name):
    parent = family[name]["parent"]
    print("parent of joe ",parent)
    if parent is None:
        return None
    grandparent = family[parent]["parent"]
    return grandparent

# Setting relationships
set_parent("John", "Mary")
set_parent("Mary", "Joe")

print("Joe's grandparent is:", find_grandparent("Joe"))
