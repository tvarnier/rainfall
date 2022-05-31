import sys

if len(sys.argv) == 2 :
    arg = int(sys.argv[1], 16)
    if arg >= 97 :
        print((arg - 65 - 6) * 4)
    else :
        print((arg - 65) * 4)
else :
    c = 'A'
    while c <= 'z' :
        print(c*4, end="")
        c = chr(ord(c) + 1)
        if c == '[':
            c = 'a'
