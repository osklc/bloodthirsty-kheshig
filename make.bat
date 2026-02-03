@echo off
cd /d "%~dp0"
windres src/resource.rc -o src/resource.o
gcc -Wall -g -o bin/Bloodthirsty-Kheshig.exe main.c src/BLACKSMITHMENU_.c src/MARKETMENU_.c src/WARMENU_.c src/INNMENU_.c src/resource.o

