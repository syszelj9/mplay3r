MMMM   MMMM  PPPPPP   LL     AAAAAAAAA  YY     YY    33333    RRRRRRR
MM MM MM MM  PP   PP  LL     AA     AA   YY   YY   33     33  RR    RR
MM  MMM  MM  PPPPPP   LL     AAAAAAAAA    YYYYY        3333   RRRRRR
MM       MM  PP       LL     AA     AA     YYY     33     33  RR   RR
MM       MM  PP       LLLLL  AA     AA     YYY       33333    RR    RR
A lightweight bare-bones command line mp3 player made in C.

###COMMANDS###

_____________
Starting out
-------------
1. Once you have built the package, simply do `./player <name of the directory where the music is stored>`
The player will immediately start playing the first song.

_____________________
KEYBINDS AND CONTROL
---------------------
1. To pause the music, press `s`. Yes, I know it says stopped but it actually just pauses it.
    ________
    Looping
    --------
    1. To create a loop point A, press `o` once, then press it again to create the second loop point and that loop will play.
    2. To cancel the loop and continue playing the song as normal, press `o` a third time.

2. Pressing `L` shows you the current playlist/folder you are in, and the current track that is playing.
3. If the program has nothing to play, it will just exit.

______________
COMMON ERRORS
--------------
1. `Failed to execute mpg123` or `Fork failed`, you are missing the MPG123 package.
2. `Invalid choice, please try again`, there is something wrong with the file you are trying to play, or it just doesn't exist.
3. `Failed to open directory`, failed to open the given directory..

##Developer's note
The program is quite small.
Given it's size, there aren't many things that can go wrong.
It's either your computer, or your brain.