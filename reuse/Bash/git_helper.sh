#!/usr/bin/env bash


:<<COMMENT
git push script
COMMENT
set -x
set -e


git add .
git commit -m "$(git status -s)"
git push origin master


:<<COMMENT
count the total diff line
COMMENT
git diff HEAD --no-ext-diff --unified=0 --exit-code -a --no-prefix | egrep "^\+" | wc.exe -m


:<<COMMENT
show commit-id new added line
COMMENT
git show <commit-id> | grep '^\+'
