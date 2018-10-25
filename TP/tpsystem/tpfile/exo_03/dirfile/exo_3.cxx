/**
 * @File : exo_03.cxx
 *
 * nsFctShell::FileCopy()  
 *
 * donneTailleMorceau
 **/
#include <string>
#include <exception>

#include <sys/stat.h>       // struct stat

#include "CExc.h"	    // exception
#include "nsSysteme.h"      // espace de noms nsSysteme, nsFctShell


using namespace nsSysteme;  // Fonctions Systemes
using namespace nsFctShell; // Fonction Shell
using namespace std;

namespace {
  std::size_t donneTailleMorceau(const string &comment, const string &nomFic) {
    if(comment == "char") return 1;
    if(comment == "all") {
      struct stat S;
      Stat (nomFic . c_str(), & S);
      return S.st_size;
    }
    if(comment == "block") {
      struct stat S;
      Stat (nomFic . c_str(), & S);
      return S.st_blksize;
    }
    if(comment == "diskBlock") {
      return S_BLKSIZE;
    }
    throw CExc("donneTaille()", string("mauvais choix ") + comment);
  }
}

int main (int argc, char * argv []) {
   try {
    
	if (4 != argc && 5 != argc)
        throw CExc ("ppal()", string ("Usage : ") +
                          argv [0] + " {char|all|block|diskBlock} <source> 				<destination> [sync]");

    const size_t morceau = donneTailleMorceau(argv[1],argv[2]);
    bool qSync(false);
    if(5 == argc) {
      if(string("sync") == argv[4]) {
	qSync = true;
      }
      else {
        throw CExc ("ppal()", string ("Usage : ") +
                          argv [0] + " {char|all|block|diskBlock} <source> <destination> [sync]");
      }
    }
    FileCopy (argv [3], argv [2], morceau, qSync);
    cout << "Copie par " << morceau << "\n";

    return 0;
   }
   catch (const CExc & Exc) {
        cerr <<Exc<< endl;
        return errno;
   }
   catch (const exception & Exc) {
        cerr << "Exception : " << Exc.what () << endl;
        return 1;
   }
   catch (...) {
        cerr << "Exception inconnue recue dans la fonction main()" 
             << endl;
        return 1;
   }

} // main()


