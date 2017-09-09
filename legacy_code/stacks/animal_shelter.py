'''
Created on 19/07/2016

@author: pollo
'''

class AnimalShelter(object):

    def __init__(self):
        self.cat = []
        self.dog = []
        self.index = 0


    def enqueue(self, animal):
        if animal == "cat":
            self.cat.append(self.index)
            self.index += 1
        elif animal == "dog":
            self.dog.append(self.index)
            self.index += 1
        else:
            raise Exception("Invalid animal")


    def dequeue_any(self):
        if not self.cat and not self.dog:
            raise Exception("No animals")
        elif not self.cat:
            return self.dog.pop(0)
        elif not self.dog:
            return self.cat.pop(0)
        else:
            if self.dog[0] < self.cat[0]:
                return self.dog.pop(0)
            else:
                return self.cat.pop(0)


    def dequeue_cat(self):
        if self.cat:
            return self.cat.pop(0)
        else:
            raise Exception("No cats")


    def dequeue_dog(self):
        if self.dog:
            return self.dog.pop(0)
        else:
            raise Exception("No dogs")
