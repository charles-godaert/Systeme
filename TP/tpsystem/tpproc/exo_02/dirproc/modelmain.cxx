/**
 *
 * @File : 
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : modelmain
 **/

#include <string>
#include <exception>
#include <iostream>    
#include <sys/types.h>      // pid_t 
#include <signal.h>	    //strsignal()

#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set

#include "nsSysteme.h"
#include "CExc.h"

using namespace nsSysteme;
using namespace std;

namespace {
	void Derout(int NumSig) {
		cout << "Signal : " << strsignal(NumSig) << " recu par : " 
			 << "pid : " << getpid() << endl;
	}

}
	
	

int main(int argc, char * argv [])
{

  try {
		//nsFctShell::DerouterSignaux(Derout);
		Derout(SIGTSTP);
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
