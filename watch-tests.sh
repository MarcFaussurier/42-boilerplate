# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    watch-tests.sh                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/08/14 22:55:15 by mfaussur     #+#   ##    ##    #+#        #
#    Updated: 2019/08/15 13:57:54 by mfaussur    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/bin/sh

source async.sh;
source utils.sh;

# Configuration
ico=$(pwd)/images/test.png;          	# Icon of the image used for notifications
success=$(pwd)/images/success.png;   	# Tests success icon
fail=$(pwd)/images/fail.png;        	# Tests failed icon
dirs="./days_c/ ./includes/ ./tests/";  # Folders to watch
cur_dir=$(pwd);
source ~/.bash_profile;
export PATH=${cur_dir}/libs/homebrew/bin:$PATH;

recompile_tests_title="Now compiling tests...";
recompile_tests_msg="Please wait few seconds or minute according your project size (from ${dirs}).";

tests_success_title="TEST PASSED !!";
tests_success_desc="Congratulation, sir!";

tests_failed_title="TEST FAILED !!";
tests_failed_desc="Please fix your code before pushing it, sir!";

cday=$1;
errorcnt=0;
# Function called at each folder source code update
function buildAndTest() {
    # We run tests
    removePreviousNotifications;
    echo "Compiling and running tests."
    if [[ "$OSTYPE" == "darwin"* ]]; then
		terminal-notifier -title "${recompile_tests_title}" -message "${recompile_tests_msg}"  -appIcon "${ico}"
    else
        notify-send -i "${ico}" "${recompile_tests_title}" "${recompile_tests_msg}";
    fi;
    rm -f ./a.out;
	make $cday && ./a.out;
	errorcnt=$?;
    if [[ $errorcnt == "0" ]]; then
    	removePreviousNotifications;
    	if [[ "$OSTYPE" == "darwin"* ]]; then
			terminal-notifier -title "${tests_success_title}" -message "${tests_success_desc}"  -appIcon "${success}"
        elif [[ "$OSTYPE" == "linux-gnu" ]]; then
            notify-send -i "${success}" "${tests_success_title}" "${tests_success_desc}";
        fi;
    else
       	removePreviousNotifications; 
	if [[ "$OSTYPE" == "darwin"* ]]; then
		terminal-notifier -title "${tests_failed_title}" -message "${tests_failed_desc} ($errorcnt errors)"  -appIcon "${fail}"
        elif [[ "$OSTYPE" == "linux-gnu" ]]; then
			notify-send -i "${fail}" "${tests_failed_title}" "${tests_failed_desc} ($errorcnt errors)";
        fi;
    fi;
};

# Start watcher
watch "${dirs}" buildAndTest;
