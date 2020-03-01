@echo off
echo Build data.c from data folder
folder2c data data
sdcc -c -mz80 --std-sdcc99 data.c
pause

