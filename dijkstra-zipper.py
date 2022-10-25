import sys

def do(argv):
    p(int(argv[1]), int(argv[2]))

def dz(n, m):
    if n == 0 and m == 0:
        return 0
    else:
        return (m & 1) + ((n & 1) << 1) + (dz(n >> 1, m >> 1) << 2)

def p(n, m):
    print('\n'.join([" ".join(["{:8}".format(dz(i, j))
                               for j in range(0, m)])
                     for i in range(0, n)]))

if __name__ == "__main__":
    do(sys.argv)
