	This repository is a simple test driven environement developement made for use at 42 school. Fell free to create your repos for your days under days_c/xx/ and enjoy tests !

Deefault commands behaviour : 

make   => norminette and compiles the test suite for all days then software will ask you for days to test 

make main   => compiles but without norminette (when you are at home) 

make mainall => compiles without norminette and run all tests

make watch => will wait for source code change, then will recompile your project and send you a notification if your tests passed, or not.


./a.out => will ask you for days to test 

./a.out all => will run all days 

./a.out 00 01 09 => will test days 00 01 09
