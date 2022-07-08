# Diff Tool Task

Write a program that compares (at least) two text files.
- The files to compare shall be specified _on the command line_.
- The output should be per different line, _on stdout_.
- You are _encouraged to make changes_ to the provided skeleton.
- You are _expected to write additional tests_ to
  cover larger files and potential edge-cases.

<br>

## Skeleton Contents
  - [`main.c`](src/main.c) with an example `main()` function;
  - [`include/`](include/) with some headers suggesting modules
    that you may want to implement in `src/`;
  - [`tests/`](tests/) with sample input files & expected output,
    divided into solution stages;
  - [`run_tests.py`](run_tests.py) so you don't spend more time
    in the terminal than in your editor.
  - [`Makefile`](bld/Makefile) to build the project.

### Building & Testing
#### Linux:
  - `cd bld && make; cd ..` (or enter the commands separately)
  - `./run_tests.py 0` (where `0` is the stage you're testing)
    - If your build is broken: `make clean` from `bld/`
#### Windows:
  - `cd bld; mingw32-make.exe; cd ..`
  - `python.exe run_tests.py 0` (where `0` is the stage you're testing)
    - If your build is broken: `mingw32-make.exe clean` from `bld\`

You may want to add extra compiler options in `CFLAGS` or specify
extra source and include directories in the makefile.

----

<br>

## Solution Stages
###### _Not all diffs are created equal._
You are **strongly** encouraged to implement the program
in increasing levels of functionality and sophistication.

The skeleton **suggests** the following stages:

### Stage-0
Check files for strict equality. Meaning _any_ difference
is considered a negative, and _no_ difference - a positive.
#### Suggested output:
"`Files are identical.`" or "`Files are different.`"

### Stage-1
Count the number of non-identical lines. For each line,
compare only its counterpart (so don't take added or deleted
lines into account).
#### Suggested output:
"`Files are identical.`", "`1 line differs.`", or "`15 lines differ.`"

### Stage-2
Print the lines of each file that differ. If one file is
longer than the other, also show the extra lines.
#### Suggested output:
`Left  3: hello`  
`Right 3: hi`  
`Right 4: there`

### Stage-3
_Your own design and tests. This is what will be evaluated._
