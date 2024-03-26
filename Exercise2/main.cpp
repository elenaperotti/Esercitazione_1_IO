#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Funzione per mappare i valori dall'intervallo [1, 5] all'intervallo [-1, 2]
double funzionevalori(double numero)
{
    return ((numero - 1)/4)*3 -1;  // prima sposto il mio valore di -1, dall'intervallo [1,5] all'intervallo [0,4], faccio una proporzione x : 4 = y: 3,
        // ricavo y nell'intervallo [0,3] e sposto ancora una volta il mio valore di -1 all'intervallo [-1,2]
}

int main() {
    const string nomefileinput = "data.csv";
    ifstream inFile(nomefileinput);

    if (!inFile.is_open()) {
        cerr << "Errore: il file " << nomefileinput << " non si apre. " << endl;
        return -1;
    }

    const string nomefileoutput = "result.csv";
    ofstream outFile(nomefileoutput);

    double somma = 0.0;
    double numero;
    double media = 0;
    int N = 0;

    outFile << "# N Mean\n";
    string riga;
    while (getline(inFile, riga)) {
        istringstream lista(riga);
        if (!(lista >> numero)) {
            std::cerr << "Errore.\n";
            return 1;
        }
        //Cambio l'intervallo della lista di valori
        somma = somma + funzionevalori(numero);
        //Calcolo la loro media
        media = somma/(N+1);
        N++;
        // Stampo la media ottenuta fino al valore raggiunto
        outFile << N << " " << media << scientific <<  "\n";
    }

    inFile.close();
    outFile.close();

    return 0;
}
