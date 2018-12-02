Prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
Prefix swrc: <http://swrc.ontoware.org/ontology#>
Prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#>
Prefix dcterms: <http://purl.org/dc/terms/>
Prefix dc: <http://purl.org/dc/elements/1.1/>
Prefix d2rq: <http://www.wiwiss.fu-berlin.de/suhl/bizer/D2RQ/0.1#>
Prefix owl: <http://www.w3.org/2002/07/owl#>
Prefix xml: <http://www.w3.org/XML/1998/namespace>
Prefix skos: <http://www.w3.org/2004/02/skos/core#>
Prefix foaf: <http://xmlns.com/foaf/0.1/>
Prefix xsd: <http://www.w3.org/2001/XMLSchema#>
Prefix dblp: <http://dblp.l3s.de/d2r/resource/>
Prefix skg: <https://w3id.org/skg#>

Create View Template confttl As
  Construct {
    ?s
      dc:title ?n ;
      rdfs:label ?l ;
      dcterms:Identifier ?i ;
      rdf:type swrc:conference ;
      rdf:type skg:conference .
  }
  With
    ?s = uri(concat("https://w3id.org/skg/" ,"conferences/" , ?1))
    ?i = plainLiteral(?1)
    ?l = plainLiteral(?2)
    ?n = plainLiteral(?3)