"""Experimenting with C/C++ modules for Python."""

import ctypes
import item
from item import sys_call


if __name__ == '__main__':
    n = 1_000_000_000

    print('Python version')

    i, j, k = 0, 1, 2
    while i < times:
        i = k
        k += j
        j = i
    print(k)

    print('C version')
    lib = ctypes.CDLL('./ctypes_test')
    result = lib.iterate(n)
    print(result)

    print('C pointers')
    buffer = ctypes.create_string_buffer(b'Hello world ho ho ho')
    count = lib.remove_char(buffer, ord('o'), 3)  # remove first n instances of char from string
    print(count)  # 3
    print(buffer.raw)  # b'Hell wrld h ho ho\x00ho\x00'
    print(buffer.value)  # b'Hell wrld h ho ho'

    print('C extension')
    print(help(item))
    item.create('hello')  # (1, 'hello')
    item.create()  # (2, 'default!')
    it = item.Item('name')
    print(it.value)  # 0
    it.add(7)
    print(it.value)  # 7

    # sys_call('ls -al >> output.txt')
    sys_call('dir > output.txt')

    with open('output.txt', 'r') as f:
        print(f.read())
