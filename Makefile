# Ce Makefile permet de générer les executables
# - pour les tests f1main et f2main du repertoire tests
#-  pour le programme pccmain du repertoire src

# les fichiezrs executables sont situés sdnas le repertoire bin


all : test_arbre_sans_doublons test_arbre_avec_doublons test_dicoliste_sans_doublons test_dicoliste_avec_doublons test_hashtable_avec_doublons test_hashtable_sans_doublons

test_arbre_sans_doublons :
		gcc test/test_arbre_sans_doublons.c src/implementation_arbre/arbre.c src/implementation_arbre/lecture_fichier_arbre.c src/list.c -g -std=c99 -o bin/test_arbre_sans_doublons

test_arbre_avec_doublons :
		gcc test/test_arbre_avec_doublons.c src/implementation_arbre/arbre.c src/implementation_arbre/lecture_fichier_arbre.c src/list.c -g -std=c99 -o bin/test_arbre_avec_doublons


test_dicoliste_sans_doublons :
		gcc test/test_dicoliste_sans_doublons.c src/implementation_dicoliste/dicoliste.c src/implementation_dicoliste/lecture_dicoliste.c src/list.c -g -std=c99 -o bin/test_dicoliste_sans_doublons

test_dicoliste_avec_doublons :
		gcc test/test_dicoliste_avec_doublons.c src/implementation_dicoliste/dicoliste.c src/implementation_dicoliste/lecture_dicoliste.c src/list.c -g -std=c99 -o bin/test_dicoliste_avec_doublons


test_hashtable_sans_doublons :
		gcc test/test_hashtable_sans_doublons.c src/implementation_hashtable/lecture_hashtable.c src/implementation_hashtable/hashtable.c src/list.c -g -std=c99 -o bin/test_hashtable_sans_doublons

test_hashtable_avec_doublons :
		gcc test/test_hashtable_avec_doublons.c src/implementation_hashtable/lecture_hashtable.c src/implementation_hashtable/hashtable.c src/list.c -g -std=c99 -o bin/test_hashtable_avec_doublons



exe_arbre_sans_doublons :
		./bin/test_arbre_sans_doublons

exe_arbre_avec_doublons :
		./bin/test_arbre_avec_doublons

exe_hashtable_sans_doublons :
		./bin/test_hashtable_sans_doublons

exe_hashtable_avec_doublons :
		./bin/test_hashtable_avec_doublons

exe_dicoliste_sans_doublons :
		./bin/test_dicoliste_sans_doublons

exe_dicoliste_avec_doublons :
		./bin/test_dicoliste_avec_doublons
