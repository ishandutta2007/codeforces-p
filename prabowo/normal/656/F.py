print ( __import__("functools").reduce (lambda ans, c: ans + (1 if c == "A" else 10 if c == "1" else int(c)), [0] + list(input())) )