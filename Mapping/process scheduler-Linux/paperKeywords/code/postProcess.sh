#!/bin/bash
 for i in `seq 0 9`;
        do
                cat *$i.out.ttl > PaperKeywords$i.ttl
                zip -9 PaperKeywords$i  PaperKeywords$i.ttl
        done 
