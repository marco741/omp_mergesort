# Contest OMP
## General Instructions

To build the executable both for tests and source code run\
`make`

To clean the .o files in the build directories run\
`make clean`

To build and execute test cases run\
`make test`

To generate measures (TAKES A LOT OF TIME! Our measures are already included so you should skip this step) run\
`make measures`

To generate a file with random numbers run\
`make generate_file [N=N[:10000]] [MAX=MAX[:2147483647]] [MIN=MIN[:-MAX]] [FILENAME=path/to/inputfile[:input/in.txt]]`

To build and execute the source code run\
`make run [FILENAME=path/to/inputfile[:input/in.txt]] [TASK_SIZE=TASK_SIZE[:100]]`

To build and execute *SILENTLY* the source code run\
`make -s run [FILENAME=path/to/inputfile[:input/in.txt]] [TASK_SIZE=TASK_SIZE[:100]]`

To generate a file with random numbers and execute a single run of the mergesort run\
`make generate_file run [N=N[:10000]] [MAX=MAX[:2147483647]] [MIN=MIN[:-MAX]] [FILENAME=path/to/inputfile[:input/in.txt]] [TASK_SIZE=TASK_SIZE[:100]]`

## Notes

Results can be found in the `measures` directory, divided by problem size, gcc optimization option and task size.

The speedup curves are generated taking the relative serial execution as reference.