#!/bin/bash
for f in Paper*4.out;
 do echo "Processing $f file..";
  ./paperKeywordETL $f;
  sparqlify-csv  -c paperKeywords.sml -f $f.etl > $f.ttl; 
 done
