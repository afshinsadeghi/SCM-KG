#!/bin/bash
for f in paper*3.out;
 do echo "Processing $f file..";
  ./paperETL $f;
  sparqlify-csv  -c papers.sml -f $f.etl > $f.ttl; 
 done
