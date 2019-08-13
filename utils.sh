!/usr/bin/env bash

GREEN='\e[32m'; CYAN='\e[36m'; NC='\e[0m';RED='\e[31m';
job1=0; job2=0;
CURRENT_LIBS=();
RETURN=0;

# Wait for file update in given $1 folders, will then start $2 function in job1 process and store its job id in job1
function watchFolders() {
    # MacOS
    if [[ "$OSTYPE" == "darwin"* ]]; then
        fswatch ${1} | (while read; do
            # Kill the previous job1
            killJob ${job1};
            # Re-create it using the sync function
            async $2;
            # Store the job id in job1
            job1=${RETURN};
         done;)
    # Linux
    elif [[ "$OSTYPE" == "linux-gnu" ]]; then
        while inotifywait -e modify ${1}; do
                # Kill the previous job1
                killJob ${job1};
                # Re-create it using the sync function
                async $2;
                # Store the job id in job1
                job1=${RETURN};
         done;
    # Other os
    else
        printf "${RED} Your OS ${NC}${CYAN}$OSTYPE${NC}${RED} is not currently supported.${NC}\n";
        exit 1;
    fi;
};

# Will start the watcher using given callback and folders name
function watch() {
    # We run the callback using async
    async $2;
    # And store its id in job1.
    job1=${RETURN};
    # We async watch for the given folders, and manage job1 when needed
    async watchFolders "$1" $2;
    # We store the watcher id in job2
    job2=${RETURN};
    # And await all jobs to finish (wait a CTRL + C)
    awaitAll;
};

# will remove previous notification so that we can instantly notify the user about a live event.
function removePreviousNotifications() {
    if pgrep -x "notify-osd" > /dev/null; then
        killall notify-osd;
    fi;
}
