/**
 *
 * @File : exo_01_a.cxx
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : Heritage des signaux entre 
 *            le processus pere et le processus fils
 *
 **/

#include <string>
#include <exception>
#include <iostream>   
#include <iomanip>          //setw
#include <sys/types.h>      // pid_t 
#include <signal.h>	    //strsignal()

#include "nsSysteme.h"
#include "CExc.h"

using namespace nsSysteme;
using namespace nsFctShell;
using namespace std;

namespace
{
    bool Pere;
    void Derout (int NumSig)
    {   cout<<endl;
        cout << "Signal " << strsignal(NumSig)<<" "<<NumSig << " recu par le " 
             << (Pere ? "pere " : "fils ") << " de pid = " 
             << setw (5) << ::getpid ()    << endl;

    } // Derout()

	

} // namespace anonyme


int main(int argc, char * argv [])
{
  try {
    if (1 != argc)
        throw CExc ("main()",string ("Usage : ") + argv [0]);


    //DerouterSignaux deroute tous les signaux deroutables 
    //vers le traitant de signal Derout
   

    DerouterSignaux(Derout);


    // Creation d'un pere et d'un fils
    // Le père est arrêté par SIGINT, le fils par SIGQUIT

    pid_t PidFils;

    if ((PidFils=Fork())) { // pere
		Pere=true;
		Signal(SIGINT,SIG_DFL);

		cout<<"Je suis le pere de pid "<<::getpid()
		<<" et j'ai un fils de pid "<<PidFils<<endl;
		cout<<"Je suis arrete par SIGINT  (Ctrl + C) \n";
		
     }

     else	{ //fils
		Pere=false;
		Signal(SIGTSTP, SIG_DFL);
		cout<<"Je suis le processus fils de pid  "<< ::getpid() <<
		" et mon pere est "<<::getppid()<<endl;
        	cout<<"Je suis arrete par SIGTSTP(Ctrl + Z)\n"  << endl;	

     }
    

    //attente des signaux pour verifier leur heritage

    for (;;);

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


}  //  main()
