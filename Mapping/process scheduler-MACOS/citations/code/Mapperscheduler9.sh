#!/bin/bash
for f in cites.csv?*9.out;
 do echo "Processing $f file..";
  sparqlify-csv  -c cite.sml -f $f > $f.ttl 
 done
