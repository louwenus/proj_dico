type genre = Masc | Fem | None;;
type nb = Sing | Plur | None;;
type pers = Je | Tu | Sing3 | Nous | Vous | Plur3 | None;;

type verbe = { content: string; sujet: pers; };;
type nom = { content: string; gender: genre; count: nb }
type determinant = { content: string; gender: genre; count: nb };;
type adjectif = { content: string; gender: genre; count: nb};;

type phrase_verif = {
    (* gender_wanted: genre; // Le genre suivant de la phrase souhaité // A retirer ? *)
    gender_saw: genre; (* Le genre qui a été lu le dernier *)
    nb_wanted: nb; (* Pluriel qui a été lu le dernier*)
    nb_saw: nb;
    last_subject: pers;
    last_verb: pers;
    is_question: bool;
};;