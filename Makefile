# Ce Makefile permet de générer les executables
# - pour les tests f1main et f2main du repertoire tests
#-  pour le programme pccmain du repertoire src

# les fichiezrs executables sont situés sdnas le repertoire bin


all : test_arbre test_dicoliste test_hashtable

test_arbre :
		gcc test/test_arbre.c src/implementation_arbre/arbre.c src/implementation_arbre/lecture_fichier_arbre.c src/list.c -g -std=c99 -o bin/test_arbre

test_dicoliste :
		gcc test/test_dicoliste.c src/implementation_dicoliste/dicoliste.c src/implementation_dicoliste/lecture_dicoliste.c src/list.c -g -std=c99 -o bin/test_dicoliste

test_hashtable :
		gcc test/test_hashtable.c src/implementation_hashtable/lecture_hashtable.c src/implementation_hashtable/hashtable.c -g -std=c99 -o bin/test_hashtable



exe_arbre : test_arbre
		./bin/test_arbre

exe_hashtable : test_hashtable
		./bin/test_hashtable

exe_dicoliste : test_dicoliste
		./bin/test_dicoliste
