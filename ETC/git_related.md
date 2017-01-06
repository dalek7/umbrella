# Automatic merge failed
## 문제
$ git pull origin master
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.

## 해결책
$ git fetch origin
$ git reset --hard origin/master
--> HEAD is now at ..
This basically just takes the current branch and points it to the HEAD of the remote branch.
from from http://stackoverflow.com/a/15129293
