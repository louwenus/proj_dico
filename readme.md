# Dico
## Le projet
Essais de correction orographique disponible sur github [https://github.com/louwenus/proj_dico](https://github.com/louwenus/proj_dico)

## Partie Ocaml
Parsing par stream : on prend la liste de ce que chaque mot (noms/verbe, accords...), et, mot par mot, on reçoit la structure suivante,
on fait des checks, et on passe une structure modifiée à la suite (on évite de revenir faire des vérifications sur les mots précédents)

### La structure contient :

- Genre attendu: masc/fem/Nan
- Genre rencontré masc/fem/Nan
- nombre attendu: Singulier/Pluriel/Nan
- nombre rencontré : Singulier/pluriel/Nan

- dernier sujet (je/tu/il/elle/nous/vous/ils/elles/nan)
- dernier verbe (je/tu/il/nous/vous/ils/nan)

- est une question (renseigné par le pré-parser): autorise (sans obligation) le sujet à être après le verbe


### Les checks:

- Genre accordé pour sujet/verbe
- adjectifs/déterminants/noms
- adjectifs ou détérminants couplé correctement avec des verbes
