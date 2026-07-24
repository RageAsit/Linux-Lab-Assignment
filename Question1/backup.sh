#!/bin/bash

# Initialize counters
processed=0
duplicates=0
backed_up=0

# Clear previous report and error log
> report.txt
> errors.log

mkdir -p backup 2>>errors.log

declare -A hashes

for file in submissions/*; do
    if [ -f "$file" ]; then
        ((processed++))

        hash=$(md5sum "$file" | awk '{print $1}')

        if [[ -n "${hashes[$hash]}" ]]; then
            ((duplicates++))
            echo "$(basename "$file") is a duplicate of $(basename "${hashes[$hash]}")" >> report.txt
        else
            hashes[$hash]=$file
            cp "$file" backup/ 2>>errors.log
            ((backed_up++))
        fi
    fi
done

echo "" >> report.txt
echo "Files Processed : $processed" >> report.txt
echo "Duplicate Files : $duplicates" >> report.txt
echo "Files Backed Up : $backed_up" >> report.txt