#!/bin/bash
 for i in `seq 0 9`;
        do
                cat *$i.out.ttl > PaperAuthorAffiliations$i.ttl
                zip -9 PaperAuthorAffiliations$i  PaperAuthorAffiliations$i.ttl
        done 
