#include <iostream>
#include <cstring>
#include <ostream>
#include <istream>
using std::ostream;
using std::istream;

class Student {
    
        int matrikelnr;
        char prename [10];
        char surname [10];
        char birthday [9];

    public: 
        
        friend bool operator== (const Student &a, const Student &b);
        friend bool operator< (const Student &a, const Student &b);

        friend bool operator!= (const Student &a, const Student &b);
        friend bool operator> (const Student &a, const Student &b); 
        friend bool operator<= (const Student &a, const Student &b);
        friend bool operator>= (const Student &a, const Student &b);

        void write(ostream& ostr)const;
        void read(istream& istr);

        Student();
        int GetMatrikelNr();
        void SetMatrikelNr(int matrikelnr);
        char * GetPrename();
        void SetPrename(char* prename);
        char * GetSurname();
        void SetSurname(char* surname);
        char * GetBirthday();
        void SetBirthday(char* birthday);
};


