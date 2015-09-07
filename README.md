delaycalc
=========

delaycalc is a simple console delay calculator for Linux.

LICENSE
-------
GNU/GPL copying rules apply, see COPYING

COMPILATION
-----------
Go into fretcalc source directory and type 'make'.
It should compile without errors.

INSTALLATION
------------
Currently running make will produce a single binary in the source directory. You may put it anywhere you want. 

RUNNING
-------
    $ delaycalc -b <bpm>
    
    OPTIONS: 
     Options:
        -b <bpm>                  beats per minute
        -h, --help                print this help
        -o, --output              write output to delay.out
        -p <num_decimal_places>   precision of calculation display (1-5, default 3)
        -V, --verbose             be verbose
        -v, --version             print version number
        -w, --warranty            show warranty and copyright
