#LISTS

list1=['albin','joseph','jacob','jose','jacob']
list1[3]=3
print(list1)

list2=[1,2,3,4,5,6,7,8,9,10,('a','b','c','d','e')]
print(list2)

print(type(list1),type(list2))


list3=[1,2,3,4,5,6,7,8,9,10]
print(list3)

list4=list3.copy()

print(list4)


#TUPLES

tuple1=('albin','joseph','jacob','jose','jacob')
print(tuple1)

#tuple is unchangable
#tuple is ordered

#DICTIONARY

dict1={
    'name':'albin',
    'age':21,
    'mark':{'maths':23,'science':34,'social':45},
    }
print(dict1)

# Accessing a value using its key
print(dict1['name'])  # Output: albin

# Accessing a value in a dictionary using its key
print(dict1['mark']['maths'])  # Output: 23

# Accessing a value using the get() method
print(dict1.get('name'))  # Output: albin

# Updating a value in a nested dictionary
dict1['mark']['science'] = 50
print(dict1['mark']['science'])  # Output: 50

#adding new key value pair
dict1['location']='kerala'
print(dict1['location'])

#SETS

# A set is a collection of unordered and unindexed elements. In Python, sets are written with curly brackets.

set1={1,2,3,4,5,6,7,8,9,10}
print(set1)

set1.pop()

print(set1)

set1.remove(3)

print(set1)

set2={1,2,3,4,5}
set3={'a','b','c','d',21,22,23,'a',22}
print(set2)
print(set3)