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

Create View Template articlttl As
  Construct {
    ?s
      foaf:name ?n ;
      rdfs:label ?l ;
      dcterms:partOf ?c ;
      dcterms:Identifier ?i ;
      dcterms:issued  ?y ;
      rdf:type swrc:article ;
      rdf:type skg:article .
  }
  With
    ?s = uri(concat("https://w3id.org/skg/" ,"articles/" , ?1))
    ?n = plainLiteral(?2)
    ?i = plainLiteral(?1)
    ?l = plainLiteral(?3)
    ?y = plainLiteral(?4)
    ?c = uri(concat("https://w3id.org/skg/" ,"conferences/" , ?5))
