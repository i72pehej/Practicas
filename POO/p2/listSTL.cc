// Standard Template Library example

#include <iostream>
#include <list>
using namespace std;
 
// Simple example uses type int
 
main()
{
   list<int> L;
   L.push_back(0);              // Insert a new element at the end
   L.push_front(4);             // Insert a new element at the beginning
   L.insert(++L.begin(),2);     // Insert "2" before position of first argument
                                // (Place "2" before the second list element)
   L.push_back(5);
   L.push_back(6);
 
   list<int>::iterator i;      // "i" is an iterator for the list L
 
   for(i=L.begin(); i != L.end(); ++i) cout << *i << " "; // L.begin() is the pointer to the first list element
   cout << endl;                                          // if "i" is equial to L.end(), "i" is after the last list element
   return 0;
}

