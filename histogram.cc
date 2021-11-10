#include <iostream>
#include <fstream>
#include <vector>

int main() {
    using namespace std;
    vector<int> zaehler(11);

    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");

    int zahl;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> zahl;
        zaehler[zahl] += 1;
    }
    fin.close();

    for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) 
    {
      cout << k << ":" << zaehler [ k ] <<  endl ;
      fout << k<< "\t" << zaehler [ k ] << endl;
    }
    fout.close();
}