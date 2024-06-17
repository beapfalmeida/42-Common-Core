# PIPEX
This is a project handling shell pipes.

## MANDATORY PART
The mandatory version works with only one pipe.

### You should run the program like this:
./pipex infile cmd1 cmd2 outfile

### The output is expected to behave the same way as the following command:
< infile cmd1 | cmd2 > outfile

##### The infile must exist. 
##### cmd1 and cmd2 are shell commands such as grep, ls, cat or any other.
##### The outfile will be created if it does not exist yet.

## BONUS PART
The bonus part works with multiple pipes like this:
./pipex_bonus infile cmd1 ... cmdn outfile

The bonus part also handle heredocs. This means that you provide the input in the terminal instead of giving an input file.
### This is how you can use my program with here doc:
./pipex_bonus here_doc LIMITER cmd1 ... cmdn outfile

LIMITER is the word after which the terminal stops asking for input.

### The output is supposed to behave the same as:
cmd1 << LIMITER | cmd2 | ... | cmdn >> outfile
