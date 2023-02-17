cdef float x = 0.5

cpdef int mult(int x):
    cdef int res = 1
    cdef int i
    for i in range(1, x+1):
        res *= i
    return res

cpdef fibonacci(int n):
    if n < 2:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

