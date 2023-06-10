#!/bin/bash
lex part2.l && yacc part2.y -d && cc -o part2 y.tab.c -ll -Ly && ./part2<part2.txt
