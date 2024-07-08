#!/bin/sh
black=#1a1b26
green=#9ece6a
white=#a9b1d6
grey=#24283b
blue=#7aa2f7
red=#f7768e
darkblue=$grey

clock() {
    printf " $(playerctl metadata -f '{{title}}') |"
	printf " $(date '+  %D | 󱑆  %H:%M') "
}


while true; do
    xsetroot -name "$(clock)"
    sleep 60
done
