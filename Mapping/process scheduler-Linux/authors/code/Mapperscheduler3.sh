#!/bin/bash
for f in Author*3.out;
 do echo "Processing $f file..";
  ./authorETL $f;
  sparqlify-csv  -c authors.sml -f $f.etl > $f.ttl; 
 done
