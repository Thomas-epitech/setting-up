# {EPITECH} Setting up Project

## Description

"Setting up" Project is an Epitech first-year project included in the CPE (Elementary Programming in C) Unit.<br/>
The goal of the project is to create a program that finds the largest possible square on a board while avoiding obstacles.

## Usage

You must first execute the Makefile:
```bash
make all
```
This will create a binary file called "setting_up".

A board is optainable in two ways:<br/>
-1:<br/>
The first way is through a file that will be passed as a parameter, here are the rules to follow for a file to be valid:<br/>
• The first line of the file must only contain the number of line on the board.<br/>
• Only two characters can be on the other lines: '.' (representing an empty space) and 'o' (representing an obstacle).<br/>
• All of the line must be the same length.<br/>
• It must contain at least one line.<br/>
• Each line is terminated by '\n'.<br/>
Not following these rules will lead to a "Invalid file" error message.

Example of execution:
```bash
./setting_up path_to_file
```

-2:
The second way is by generate it based on given parameters:<br/>
• The first parameter will be a number, representing both the width and height of the board.<br/>
• The second parameter will be a patern of '.' and 'o' that will be repeated line by line along the board.

Example of execution:
```bash
./setting_up 7 "o.o..o"
```

In order to represent the largest square, '.' characters will be replaced by 'x' characters.<br/>
If there are several solution, only the highest square (on the left) will be shown.<br/>
The solved board will be printed in the standard output regardless of the execution method.
