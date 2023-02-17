#! /usr/bin/env python3

import time
import ctypes

import cffi

import utils
import cython.cyutils

def py_fibonacci(n):
    if n < 2:
        return 1
    return py_fibonacci(n-1) + py_fibonacci(n-2)


MAX_NUM = 35

def main():
    start_ts = time.time()
    res_py = [py_fibonacci(n) for n in range(MAX_NUM)]
    end_ts = time.time()
    print(f"Time of execution of python fibonacci is {end_ts - start_ts:.3} seconds")

    ctypes_utils = ctypes.CDLL('./ctypes/libutils.so')
    # Если закомментировать следующие две строки, то
    # ошибки не будет.
    ctypes_utils.fibonacci.argstype = [ctypes.c_int]
    ctypes_utils.fibonacci.restype = ctypes.c_int
    start_ts = time.time()
    res_ctypes = [ctypes_utils.fibonacci(n) for n in range(MAX_NUM)]
    end_ts = time.time()
    print(f"Time of execution of ctypes fibonacci is {end_ts - start_ts:.3} seconds")

    ffi = cffi.FFI()
    cffi_lib = ffi.dlopen('./cffi/libarea.so')
    ffi.cdef('''
    int fibonacci(int n);
    ''')

    start_ts = time.time()
    res_cffi = [cffi_lib.fibonacci(n) for n in range(MAX_NUM)]
    end_ts = time.time()
    print(f"Time of execution of cffi fibonacci is {end_ts - start_ts:.3} seconds")

    start_ts = time.time()
    res_capi = [utils.fibonacci(n) for n in range(MAX_NUM)]
    end_ts = time.time()
    print(f"Time of execution of capi fibonacci is {end_ts - start_ts:.3} seconds")

    start_ts = time.time()
    res_cython = [cython.cyutils.fibonacci(n) for n in range(MAX_NUM)]
    end_ts = time.time()
    print(f"Time of execution of cython fibonacci is {end_ts - start_ts:.3} seconds")
    assert(res_py == res_ctypes == res_cffi == res_capi == res_cython)

if __name__ == "__main__":
    main()
