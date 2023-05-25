# Simple Shell - Simple shell team project

This is the solution for the STACKS, QUEUES - LIFO, FIFO  project for ALX low level programming language [ALX SWE](https://alxafrica.com). A team project to improve collaborations and problem solving skills amongst ALX students.

## Table of contents

- [Overview](#overview)
  - [The requirements](#the-requirements)
  - [The challenge](#the-challenge)
    - [Functions and descriptions](#functions-and-descriptions)
    - [Compilation](#compilation)
    - [Testing](#testing)
  - [My process](#our-process)
    - [Built with](#built-with)
    - [What I learned](#what-i-learned)
    - [Continued development](#continued-development)
    - [Useful resources](#useful-resources)
  - [Author](#author)
  - [Acknowledgments](#acknowledgments)

## Overview

### The requirements

The general requirements for the project tasks were:

- All files were compiled on Ubuntu 20.04 LTS using `gcc`, using the options `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
- Outputs were printed on stdout
- Error messages were printed on stderr
- All files ended with a new line
- A `README.md` file, at the root of the folder of the project was created
- Code used the Betty style
- A maximum of one global variable was used
- No more than 5 functions per file
- C standard libraries were used
- The prototypes of all functions were included in the header file called `monty.h`
- All header files were 'include guarded'
- A README with the description of the project was written

### The challenge

The project was to achieve the following:

- Implement the push and pall opcodes.
  - The opcode `pall` is expected to prints all the values on the stack, starting from the top of the stack.
  - Usage `pall`
  - Nothing is printed, if the stack is empty
- Implement the pint opcode
  - The opcode `pint` prints the value at the top of the stack, followed by a new line.
  - Usage: `pint`
  - The error message `L<line_number>: can't pint, stack empty` is printed if the stack is empty, followed by a new line, and exit with the status `EXIT_FAILURE`
- Implement the pop opcode
  - The opcode `pop` removes the top element of the stack.
  - Usage: `pop`
  - The error message `L<line_number>: can't pint, stack empty` is printed if the stack is e\mpty, followed by a new line, and exit with the status `EXIT_FAILURE`
- Implement the swap opcode
  - The opcode `swap` swaps the top two elements of the stack.
  - Usage: `swap`
  - The error message `L<line_number>: can't pint, stack empty` is printed if the stack is e\mpty, followed by a new line, and exit with the status `EXIT_FAILURE`- Handle errors
- Implement the add opcode
  - The opcode `add` adds the top two elements of the stack.
  - Usage: `add`
  - The error message `L<line_number>: can't pint, stack empty` is printed if the stack is e\mpty, followed by a new line, and exit with the status `EXIT_FAILURE`- Handle errors.
  - The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    - The top element of the stack contains the result
    - The stack is one element shorter
- Implement the nop opcode
  - The opcode nop doesn’t do anything.
  - Usage: `nop`

### Functions and descriptions

The several functions used to making the simple shell project in its entirety and their descriptions are thus:

| Function          | Description                                                         |
| ----------------- | ------------------------------------------------------------------- |
| main              | The entry point of the main program                                 |
| __push       | Pushes an element to the stack |
| __pall | Prints all the values on the stack starting from top of the stack      |
| \_\_find_commands | This finds the mocked commands and run them appropraitely           |
| \_\_fork_command  | This creates a child process and forks an execution thread          |
| \_\_error_puts    | This writes an error message to the STDERR                          |
| \_realloc         | This reallocate a block of memory                                   |

Quite a number of functions were used to get the program to work appropraitely

### Compilation

The code(s) was compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

### Testing

```
odopeter@root:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                     pall    $
push 4$
      push 5    $
	push    6        $
pall$
```

## My process

### Built with

The project, was built with C language.

### What we learned

**\*\***....... What we both learned in the course of the tasks goes here, we will keep updating (this part individually, probably after each task) as time goes by .......**\*\*\*\***

### Continued development

What we hope to do after completing this tasks, eg, implementing more of the functionalities of a regular UNIX shell, etc...
**\*\***....... (We will also update this with suitable ideas in due time) .......**\*\*\*\***

### Useful resources

[Code Blocks](https://docs.readme.com/rdmd) - The rdmd docs from this site helped us to write a well structured readme for this project, alongside proper formatting of inline codes and code blocks

[Stack Overflow](https://stackoverflow.com/) - This aided us to help find questions and appropraite answers to bugs we faced while doing the project. (we can come add more to this later)

[GitHub Docs](https://docs.github.com/en/get-started/) - GitHub Docs was used to create nicely formatted tables for writing functions and their descriptions.

[Geeks For Geeks](https://geeksforgeeks.org) - Geeks for geeks, a great place for well detailed technical articles encompassing several programming languages, this helped in getting several informations on how some of the functions works.

[Youtube Channels](https://youtube.com) - Combinations of several channels and videos was used to aid the completion of this project, I will suggest that anyone wanting to top their developing game, should use Youtube more often.

[Google](https://google.com) - Google was the icing on the cake, as almost everything, started and ended with Google, a timely and accurate search can salvage one hours of debugging problems.

## Authors

This project was done by:
- Peter Odo

## Acknowledgments

Super grateful for the opportunity ALX is offering to young Africans as regards growing the technological atmosphere of the continent, we sure, will keep this flag flying high, ALX to the world.