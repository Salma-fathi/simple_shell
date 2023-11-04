Simple Shell Project Documentation
Authors:

Amna Ahmed
Salma Mohammed
Project Deadline: Nov 16, 2023

Table of Contents
Introduction
Project Description
Project Requirements
Project Structure
Building and Running
Functionality
Project Implementation
Testing
Known Issues
Future Improvements
References
Introduction
This document provides an overview and documentation for the Simple Shell project. The Simple Shell project is a UNIX command-line interpreter created as part of the ALX SE curriculum.

Project Description:
The Simple Shell project is a basic shell that allows users to interact with the system by running simple commands. It supports executing commands, managing environment variables, handling built-in commands like exit and env, and more.

Project Requirements:
The project requirements, as outlined in the task list, include:

Writing a simple shell with a prompt.
Handling command lines with arguments.
Implementing the exit and env built-in commands.
Handling the PATH.
Handling logical operators ;, &&, and ||.
Implementing the cd built-in command.
Implementing the setenv and unsetenv built-in commands.
Handling variables like $$ and $?.
Handling comments.
Reading commands from a file.
Project Structure
The project structure consists of several C source code files. Here are the main files and directories:

src: This directory contains the source code for the Simple Shell.
include: Header files used in the project.
tests: Test cases for the shell.
README.md: A file with project information.
AUTHORS: A file listing the authors of the project.
Building and Running
To build the Simple Shell project, you can use the provided Makefile. Simply run make to compile the code:

shell
$ make
To run the shell, execute the generated simple_shell binary:

shell
$ ./simple_shell
Functionality
The Simple Shell project provides the following functionality:

Displaying a prompt and waiting for user input.
Handling simple commands and executing them.
Managing environment variables.
Handling bmands like exit, env, cd, and more.
Managing variables like $$ and $?.
Handling logical operators ;, &&, and ||.
Reading commands from a file.
Project Implementation:
The project is implemented in C and follows the requirements outlined in the tasks. It uses system calls like fork, execve, chdir, getenv, and others to manage processes, execute commands, and handle environment variables.

Testing:
The project includes a set of test cases in the tests directory. You can run the tests using the provided test script:

shell
$ ./run_tests.sh
These tests cover various aspects of the shell's functionality, ensuring that it behaves as expected.

Known Issues
List any known issues or limitations in your shell.
Future Improvements
Mention any possible improvements or enhancements you plan to make in the future.
References:
List any external resources or references you used while working on the project.
