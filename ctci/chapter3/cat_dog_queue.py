#!/bin/python

class Node:
    def __init__(self, x):
        self.next = None
        self.next_type = None
        self.value = x

class CatDogQueue:
    def __init__(self):
        self.head = None
        self.head_cat = None
        self.head_dog = None
        self.tail = None
        self.tail_cat = None
        self.tail_dog = None


    def enqueue_cat(self, cat_name):
        cat_name = "cat_{0}".format(cat_name)
        cat = Node(cat_name)
        if self.head == None:
            self.head = cat
        else:
            self.tail.next = cat
        self.tail = cat
        if self.head_cat == None:
            self.head_cat = cat
        else:
            self.tail_cat.next_type = cat
        self.tail_cat = cat


    def enqueue_dog(self, dog_name):
        dog_name = "dog_{0}".format(dog_name)
        dog = Node(dog_name)
        if self.head == None:
            self.head = dog
        else:
            self.tail.next = dog
        self.tail = dog
        if self.head_dog == None:
            self.head_dog = dog
        else:
            self.tail_dog.next_type = dog
        self.tail_dog = dog


    def dequeue(self):
        animal = self.head.value
        if self.head == self.head_cat:
            self.head_cat = self.head_cat.next_type
            if self.head_cat == None:
                self.tail_cat = None
        if self.head == self.head_dog:
            self.head_dog = self.head_dog.next_type
            if self.head_dog == None:
                self.tail_dog = None
        self.head = self.head.next
        if self.head == None:
            self.tail = None
        return animal


    def dequeue_cat(self):
        cat = self.head_cat.value
        if self.head == self.head_cat:
            self.head = self.head.next
            if self.head == None:
                self.tail = None
        if self.tail_dog != None and self.tail_dog.next == self.head_cat:
            self.tail_dog.next = self.head_cat.next
        self.head_cat = self.head_cat.next_type
        if self.head_cat == None:
            self.tail_cat = None
        return cat


    def dequeue_dog(self):
        dog = self.head_dog.value
        if self.head == self.head_dog:
            self.head = self.head.next
            if self.head == None:
                self.tail = None
        if self.tail_cat != None and self.tail_cat.next == self.head_dog:
            self.tail_cat.next = self.head_dog.next
        self.head_dog = self.head_dog.next_type
        if self.head_dog == None:
            self.tail_dog = None
        return dog


    def print_queue(self):
        current = self.head
        q = []
        while current != None:
            q.append(current.value)
            current = current.next
        print "{0}".format(q)

    def print_cats(self):
        current = self.head_cat
        q = []
        while current != None:
            q.append(current.value)
            current = current.next_type
        print "{0}".format(q)

    def print_dogs(self):
        current = self.head_dog
        q = []
        while current != None:
            q.append(current.value)
            current = current.next_type
        print "{0}".format(q)

    def print_all(self):
        print "=================================="
        self.print_queue()
        self.print_cats()
        self.print_dogs()


q = CatDogQueue()
q.enqueue_cat(1)
q.enqueue_dog(1)
q.enqueue_cat(2)
q.enqueue_cat(3)
q.enqueue_dog(2)
q.print_all()

q.dequeue()
q.dequeue()
q.dequeue_dog()
q.dequeue()
q.print_all()
q.dequeue_cat()
q.print_all()

for i in xrange(5):
    q.enqueue_cat(i)
for j in xrange(5):
    q.enqueue_dog(j)

q.print_all()
for _ in xrange(5):
    q.dequeue_dog()
    q.print_all()
