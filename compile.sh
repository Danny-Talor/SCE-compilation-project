#!/bin/bash
lex part1.l && yacc part1.y -d && cc -o part1 y.tab.c -ll -Ly && ./part1<part1.txt
