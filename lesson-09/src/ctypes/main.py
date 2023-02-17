#! /usr/bin/env python3

import ctypes

def example():
    libc = ctypes.CDLL('libc.so.6')
    #char* strstr(char *text, char *pattern)
    libc.strstr.argstype = [ctypes.c_char_p, ctypes.c_char_p]
    libc.strstr.restype = ctypes.c_char_p
    #abda
    res = libc.strstr(b"ababda", b"abd")
    print(res)

def own_lib():
    utils_lib = ctypes.CDLL('./libutils.so')

    utils_lib.func1.argstype = [ctypes.c_int]
    utils_lib.func1.restype = ctypes.c_int

    utils_lib.func2.argstype = [ctypes.c_char_p, ctypes.c_int]
    utils_lib.func2.restype = ctypes.c_void_p

    print("====== Calling func1 ======")
    for i in range(10):
        print(utils_lib.func1(i))

    print("====== Calling func2 ======")
    utils_lib.func2(b"Hello, world", 10)

def main():
    example()
    own_lib()

if __name__ == "__main__":
    main()
