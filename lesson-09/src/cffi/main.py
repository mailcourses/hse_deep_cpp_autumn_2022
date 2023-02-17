#! /usr/bin/env python3

import cffi

def main():
    ffi = cffi.FFI()
    lib = ffi.dlopen('./libarea.so')
    ffi.cdef('''
    struct Point {
        int x;
        int y;
    };

    int area(struct Point* p1, struct Point* p2);
    ''')
    p1 = ffi.new('struct Point *')
    p2 = ffi.new('struct Point *')
    p1.x, p1.y = (10, 15)
    p2.x, p2.y = (-5, 5)
    area = lib.area(p1, p2)
    print(area)

    ffibuilder = cffi.FFI()
    ffibuilder.cdef('''
    int sum(int* arr, int len);
    ''')

    ffibuilder.set_source('_sample',
    r'''
    #include <stdlib.h>

    int sum(int* arr, int len)
    {
        int res = 0;
        for (int i = 0; i < len; ++i)
            res += arr[i];
        return res;
    }
    ''')

    arr = [1,2,3,4,5]
    c_arr = ffi.new('int []', arr)
    ffibuilder.compile()
    from _sample import lib
    print(lib.sum(c_arr, len(arr)))

if __name__ == "__main__":
    main()
