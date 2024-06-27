#!/bin/sh
black=#1a1b26
green=#9ece6a
white=#a9b1d6
grey=#24283b
blue=#7aa2f7
red=#f7768e
darkblue=$grey

clock() {
	printf "$(date '+  %D | 󱑆  %H:%M:%S') "
}


while true; do
    xsetroot -name "$(clock)"
    sleep 1
done
