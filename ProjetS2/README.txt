Le dossier est consituté de 8 fichiers:

1)Le présent README.txt

2) projet.c: Il contient le main du projet et les fonctions permettant d'organiser les structures de données(insérer les mots du dictionnaire de prédiction et celui de la langue française dans l'arbre et l'initialiser).Comme on utilise des appels récursifs notamment dans la fonction  EcritureIntuitive(), il faut noter la présence des deux variables globales "compteur" et "p".


3) projet.h: contient l'implémentation de la structure de donnée arbre, la définition des constantes et les prototypes des fonctions de projet.c .

4) GestionPrediction.c: Ce fichier contient les fonctions qui permettent le dialogue dictionnaire-arbre et permet ainsi de modifier/supprimer des mots dans le dictionnaire,de stocker les mots du dictionnaire dans la liste chaînées associées à leur occurence, et leur date de dernière utilisation grâce aux deux fonctions date() et heure() empreintées de OpenClassroom.


5) GestionPrediction.h:contient la définition des constantes,l'implémentation de la liste chaînée permettant de stocker les mots à partir du fichier prediction.txt, et enfin les prototypes des fonctions de GestionPrediction.c .

6) prediction.txt:contient les mots choisis par l'utilisateur et leur date d'utilisation mais pas les occurences

7) MAJ.txt:contient les mots, leur occurence et leur date d'utilisation
8) dictionnaire.txt:contient les mots du dictionnaires français sans les "é" , "è" , "à","ç","ù" , et les tirets(-)


****************************************Utilisation du programme******************************************

1-Compiler avec :gcc projet.c GestionPrediction.c -g -o projet
			./projet

2-Si on choisit de saisir un mot , il faut préciser si on active le mode rapide ou pas.Dans le premier mode , une fois que l'utilisateur tape les 3 premiers mots de son mot, 3 propositions vont immédiatement s'afficher sans qu'il appuie sur la touche "entrée".Dans l'autre mode, l'utilisateur peut saisir une longueur quelconque de son mot , et ensuite appuyer sur Entrée pour faire afficher les propositions.

3-Le menu offre la possibilité de modifier/supprimer un mot dans le dictionnaire de prédiction.
Si le mot à supprimer/modifier ne figure pas dans prediction.txt , un message d'erreur apparaîtra à l'utilisateur.



**************************************************notes***************************************************

