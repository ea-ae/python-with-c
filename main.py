"""Experimenting with C/C++ modules for Python."""

import ctypes


if __name__ == '__main__':
    times = 1_000_000_000

    print('Python version')

    i, j, k = 0, 1, 2
    while i < times:
        i = k
        k += j
        j = i
    print(k)

    print('C version')
    lib = ctypes.CDLL('./ctypes_test')
    result = lib.iterate(times)
    print(result)

    print('C pointer magic')
    buffer = ctypes.create_string_buffer(b'Hello world ho ho ho')
    count = lib.remove_char(buffer, ord('o'), 3)
    print(count)
    print(buffer.raw)
    print(buffer.value)
