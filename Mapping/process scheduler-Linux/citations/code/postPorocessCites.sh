#!/bin/bash
 for i in `seq 0 9`;
        do
                cat *$i.out.ttl > PaperReferences$i.ttl
                zip -9 PaperReferences$i  PaperReferences$i.ttl
        done 
