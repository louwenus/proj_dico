(*Vérifie que la conjugaison du verbe correspond au sujet de la phrase.
sujet est la personne du sujet de la phrase et vb.sujet est une liste dans laquelle on trouve les diff sujets
possible pour le vb de la phrase (ex: mange peut avoir il ou je comme sujet*)

let est_bien_conjugé (vb:verbe) (sujet:pers) :bool = let rec aux liste sujet = match liste with
	|[] -> false
	|x::_ when x=pers -> true
	|t::q -> aux q pers
	in aux vb.conjugaison sujet

(*Transfome un nom en personne. Si le nom transmis est un pronom personnel, alors le
pronom personnel en question est renvoyé sinon, si c'est un nom, on considéré qu'il
s'agit de la 3ème personne du singulier ou du pluriel en fonction du nombre*)

let nom_en_pers (sujet:nom) :pers = if nom.content = "je" then Je else 
 if nom.content = "tu" then Tu else if nom.content = "nous" then Nous else
  if nom.content = "vous" then Vous else match nom.count with 
	|Plur -> Plur3
	|Sing -> Sing3
	|None -> None
