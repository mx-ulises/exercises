
def push_and_check(stack, element):
    print "Push operation with element '{0}'".format(element)
    stack += [element]
    return (stack, True)

def pop_and_check(stack, element):
    print "Pop operation with element '{0}'".format(element)
    if not stack:
        print "ERROR: Empty stack, invalid operation"
        return (stack, False)
    top_element = stack.pop()
    if top_element != element:
        print "ERROR: Unexpected element '{0}'".format(top_element)
        return (stack, False)
    return (stack, True)

PARENTHESES_MAP = {"(": (push_and_check, "("),
                   "{": (push_and_check, "{"),
                   "[": (push_and_check, "["),
                   ")": (pop_and_check, "("),
                   "}": (pop_and_check, "{"),
                   "]": (pop_and_check, "["),
                  }

def bal_parentheses(entry):
    stack = []
    for c in entry:
        (operation, element) = PARENTHESES_MAP[c]
        (stack, ret) = operation(stack, element)
        if not ret:
            print "Unbalanced parentheses"
            return False
    if stack:
        print "ERROR: Non-empty stack after the end of the string"
        print "Unbalanced parentheses"
        return False
    print "Balanced parentheses"
    return True

entries = ["({[]})", "({[((()))]})", "", "]", "())", "{]"]

for entry in entries:
    print ""
    print "ENTRY: '{0}', BALANCED: '{1}'".format(entry, bal_parentheses(entry))
