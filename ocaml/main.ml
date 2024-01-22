type genre = Masc | Fem | None;;
type nb = Sing | Plur | None;;
type pers = Je | Tu | Sing3 | Nous | Vous | Plur3 | None;;
type classe = Nom | Verbe | Determinant | Adjectif;;

type verbe = { content: string; conjugaison: pers list; };; (* S'il est à l'impératif, None sera compris dans la liste, liste vide s'il est à l'infinitif *)
type nom = { content: string; gender: genre; count: nb }
type determinant = { content: string; gender: genre; count: nb };;
type adjectif = { content: string; gender: genre; count: nb};;
type autre = { content: string };;

type mot = Verbe of verbe | Nom of nom | Determinant of determinant | Adjectif of adjectif | Autre of autre;;

type phrase_verif = {
    (* gender_wanted: genre; // Le genre suivant de la phrase souhaité | A retirer car inutile ? *)
    gender_saw: genre; (* Le genre qui a été lu le dernier *)
    (* nb_wanted: nb; // Pluriel qui a été lu le dernier | A retirer car inutile ?*)
    nb_saw: nb;
    last_subject: pers;
    last_verb: pers;
    is_question: bool;
};;