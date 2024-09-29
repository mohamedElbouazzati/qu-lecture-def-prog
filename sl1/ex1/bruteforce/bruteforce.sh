#! /bin/bash

bruteforce() {
	A="${1}${2}${3}${4}${5}${6}${7}${8}"
	if ./pw_checker_naive "$A" &>/dev/null; then
		printf "%s\n" "$A"
		success=1
	fi

	[ "$success" = "1" ] && kill $$
}

set -f
ASCIISEQ=( $(python3 -c 'print("\n".join([chr(c) for c in range(32, 127)]))') )

for a in $(shuf -e "${ASCIISEQ[@]}"); do
	for b in $(shuf -e "${ASCIISEQ[@]}"); do
		for c in $(shuf -e "${ASCIISEQ[@]}"); do
			for d in $(shuf -e "${ASCIISEQ[@]}"); do
				for e in $(shuf -e "${ASCIISEQ[@]}"); do
					for f in $(shuf -e "${ASCIISEQ[@]}"); do
						for g in $(shuf -e "${ASCIISEQ[@]}"); do
							for h in $(shuf -e "${ASCIISEQ[@]}"); do
								bruteforce "$a" "$b" "$c" "$d" "$e" "$f" "$g" "$h" &
							done
						done
						printf "%s\n" "$a$b$c$d$e$f$g$h"
					done
				done
			done
		done
	done
done