## This repository is a simple test driven environement developement made for use at 42 school. Fell free to create your repos for your days under days_c/xx/ and enjoy tests !


# Default commands behaviour : 

 - make   => norminette and compiles the test suite for all days then software will ask you for days to test 
 - make main   => compiles but without norminette
 - make mainall => compiles without norminette and run all tests
 - make watch => will wait for source code change, then will recompile your project and send you a desktop notification if your tests passed, or not.


 - ./a.out => will ask you for days to test 
 - ./a.out all => will run all days 
 - ./a.out 0 1 9 => will test days 0 1 9 ..

For now, only the basics functions of day 00 are tests covered. functions such as combinaisons one are painful to test without writing the answer and very easy to check using the subject. 

I might update this repo with new tests, feel free to add yours too.

# Credits : 
minunit for the nice tests : https://github.com/siu/minunit
libc-test : for the upcoming str / memory functions https://github.com/PocketCluster/libc-test
