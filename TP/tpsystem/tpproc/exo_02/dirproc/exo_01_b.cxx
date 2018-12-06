/**
 *
 * @File : exo_01_b.cxx
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : Heritage des descripteurs de fichiers ouverts entre 
 *            le processus pere et le processus fils
 *
 **/

#include <string>
#include <exception>
#include <iostream>    
#include <iomanip>          //setw
#include <sys/types.h>      // pid_t

#include <fcntl.h>      // O_RDONLY

#include "nsSysteme.h"
#include "CExc.h"

using namespace nsSysteme;
using namespace nsFctShell;
using namespace std;

namespace
{
} // namespace anonyme


int main(int argc, char * argv [])
{
  try {
    if (1 != argc)
        throw CExc ("main()",string ("Usage : ") + argv [0]);

    cout<<"Le pere ouvre trois fichiers a part 0,1,2"<<endl;
    Open ("exo_01_c.txt", O_RDONLY);
    Open ("exo_01_c.txt", O_RDONLY);
    Open ("exo_01_c.txt", O_RDONLY);
    cout<< "le pere ferme le stderr "<<endl;
    Close (2);
    
    TestFdOuverts ();
    

    // Creation d'un pere et d'un fils

    pid_t PidFils;

    if ((PidFils=Fork())) { // pere
		
		cout<<"je suis le pere de pid "<<::getpid()
		<<"et j'ai un fils de pid "<<PidFils<<endl;
		
		
     }

     else	{ //fils
		sleep(5);
		
		cout<<" je suis le processus fils de pid  "<< ::getpid() <<
		"et mon pere est "<<::getppid()<<endl;
		 cout<< "le fils ferme le stdin "<<endl;
   		 Close (0);

		
		TestFdOuverts ();	
    }


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
