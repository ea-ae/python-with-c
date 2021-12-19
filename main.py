"""Experimenting with C/C++ modules for Python."""

import ctypes
import item


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
    count = lib.remove_char(buffer, ord('o'), 3)  # remove first n instances of char from string
    print(count)  # 3
    print(buffer.raw)  # b'Hell wrld h ho ho\x00ho\x00'
    print(buffer.value)  # b'Hell wrld h ho ho'
