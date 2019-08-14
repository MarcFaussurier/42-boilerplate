#!/bin/sh
source utils.sh;


goToLibs;#============================================================================================================#
#  DEPS                                                                                                         ~
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#/

# minunit (unit testing)	  		                                                                                 #
install minunit     master          https://github.com/siu/minunit.git;

# Homebrew (deps mgr)                                                                                				 #
install homebrew    master          https://github.com/Homebrew/brew.git;

CCPATH=$(pwd);
echo "export PATH=${CCPATH}/homebrew/bin:\$PATH" >> ~/.bash_profile;

source ~/.bash_profile;

# MacOS
if [[ "$OSTYPE" == "darwin"* ]]; then
    brew install        terminal-notifier;
    brew install        fswatch;

# Linux
elif [[ "$OSTYPE" == "linux-gnu" ]]; then
    sudo apt install    inotify-tools;
else
    printf "${RED} Your OS ${NC}${CYAN}$OSTYPE${NC}${RED} is not currently supported.${NC}\n";
    exit 1;
fi;



checkForRemovedDependencies; #  ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~   ~

