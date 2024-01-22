# Dico
## Le projet
essais de correction ortographique disponible sur github [https://github.com/louwenus/proj_dico](https://github.com/louwenus/proj_dico)

## Partie Ocaml
Parsing par stream: on prend la liste de qu'est ce que chaque mot (noms/verbe,accords...), et, mot par mot, on recoit la structure suivante,
on fait des checks, et on passe une structure modifié a la suite (on évite de revenir faire des vérifications sur les mots précédents)

### La structure contient:

- Genre attendu: masc/fem/Nan
- Genre rencontré masc/fem/Nan
- nombre attendu: Singulier/Pluiriel/Nan
- nombre rencontré: Singulier/pluriel/Nan

- dernier sujet (je/tu/il/elle/nous/vous/ils/elles/nan)
- dernier verbe (je/tu/il/nous/vous/ils/nan)

- est une question (renseigné par le pré-parser): autorise (sans obligation) le sujet a être après le verbe


### Les checks:

- Genre accordé pour sujet/verbe
- adjectifs/déterminants/noms
- adjéctifs ou détérminants couplé correctement avec des verbes
