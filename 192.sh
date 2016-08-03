#/bin/bash

#192. Word Frequency
#Write a bash script to calculate the frequency of each word in a text file words.txt.
#For simplicity sake, you may assume:
#
#	words.txt contains only lowercase characters and space ' ' characters.
#	Each word must consist of lowercase characters only.
#	Words are separated by one or more whitespace characters.
#
#For example, assume that words.txt has the following content:
#
#	the day is sunny the the
#	the sunny is is
#
#Your script should output the following, sorted by descending frequency:
#	the 4
#	is 3
#	sunny 2
#	day 1

declare -A arr 

while read line
do
	for word in $line; do
		let arr[$word]+=1;
	done
done < words.txt 

prev=999999
for (( i = 0; i < ${#arr[*]}; i++ )); do
	let bigest=0
	for e in ${!arr[@]}; do
		if [ ${arr[$e]} -gt $bigest -a ${arr[$e]} -lt $prev ]; then
			key=$e
			bigest=${arr[$e]}
		fi
	done

	echo $key $bigest
	prev=$bigest
done
