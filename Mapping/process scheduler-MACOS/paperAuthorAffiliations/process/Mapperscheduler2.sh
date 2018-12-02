#!/bin/bash
for f in Paper*2.out;
 do echo "Processing $f file..";
  ./paperaaETL $f;
  sparqlify-csv  -c paperaa.sml -f $f.etl > $f.ttl; 
 done
