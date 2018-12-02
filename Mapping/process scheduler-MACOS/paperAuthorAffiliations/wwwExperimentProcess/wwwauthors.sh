#!/bin/bash
FILE=wwwPaperIds.txt
while read paperID; do
    cat PaperAuthorAffiliations.txt | grep "$paperID" > wwwpaperAuthorIds.txt
done < "$FILE"
