#!/usr/bin/env python
# -*- coding: utf-8
from __future__ import print_function

import io
import sys
import random

def main(argv=None):
    if not argv: argv = []

    if len(argv) < 3:
        print('usage: {0} <file to create> <size in MBs>'.format(argv[0]), file=sys.stderr)
        sys.exit(1)

    fpath = argv[1]
    size  = int(argv[2])

    with open(fpath, 'w') as f:
        while f.tell() < 1024 * 1024 * size:
            print('{0:.15f}'.format(random.random()), file=f)

if __name__ == '__main__':
    main(sys.argv)
