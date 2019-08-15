## This repository is a simple project structure with test driven developement features ready to use. It is mainly built for 42 "piscine".

# Current test coverage :

- C00 ~70%
- C01 ~0%
- C02 ~0%
- C03 100%
- C04 100%

# Default commands behaviour : 

 - ./watch-tests 04 
 
 This will for example compile your day 04 and test it. Tests will be re-run at each file change (using fswatch) and send you a desktop notification according your test results.
I will update this repo with new tests, feel free to add yours too.

# Usage 
 - ./deps for installing deps
 - create your days under days_c (for example : 00/ex00/blabla.c)
 - make watch
 - keep editing your code as long as you dont have the success notification!

# Credits : 
 - minunit for the nice tests : https://github.com/siu/minunit
 - libc-test : for the upcoming str / memory functions https://github.com/PocketCluster/libc-test
 - fswatch : for file watcher
 - terminal-notifier  : for desktop notifications
 - homebrew : little package manager
