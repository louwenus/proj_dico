type genre = Masc | Fem | Nan;;
type nb = Sing | Plur | None;;
type pers = Je | Tu | Sing3 | Nous | Vous | Plur3 | Nil;;

type verbe = { content: string; sujet: pers; };;
type nom = { content: string; gender: genre; count: nb }
type determinant = { content: string; gender: genre; count: nb };;
type adjectif = { content: string: gender: genre; count: nb};;

type phrase_verif = {
    gender_wanted: genre;
    gender_saw: genre;
    nb_wanted: nb;
    nb_saw: nb;
    last_subject: pers;
    last_verb: pers;
    is_question: bool;
};;