#!/bin/python

def division(expression):
    terms = expression.split('/')
    total = float(terms.pop(0))
    for term in terms:
        total /= float(term)
    return total

def multiplication(expression):
    terms = expression.split('*')
    total = 1
    for term in terms:
        total *= division(term)
    return total

def substraction(expression):
    terms = expression.split('-')
    total = multiplication(terms.pop(0))
    for term in terms:
        total -= multiplication(term)
    return total

def calculate(expression):
    terms = expression.split('+')
    total = 0
    for term in terms:
        total += substraction(term)
    return total

print calculate("2*3+5/6*3+15")
