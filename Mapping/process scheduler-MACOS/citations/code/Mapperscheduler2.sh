#!/bin/bash
for f in cites*2.out;
 do echo "Processing $f file..";
  ./citeETL $f;
  sparqlify-csv  -c cite.sml -f $f.etl > $f.ttl; 
 done
