#include <iostream>
#include <cstring>
using namespace std;

int StateCode(char cod[2]){
  if(strcmp(cod,"IT") == 0) return 22;
  else if(strcmp(cod,"IE") == 0) return 23;
  else if(strcmp(cod,"DE") == 0) return 19;
  else if(strcmp(cod,"BE") == 0) return 21;
  else if(strcmp(cod,"HU") == 0) return 27;
  else return 0;
}

/*int Sconto(int total){
  if(total < 1000) return 1;
  else if (total < 5000) return 3;
  else if (total < 7000) return 7;
  else if (total < 10000) return 10;
  else if(total < 50000) return 15;
}
*/

int main(){
  int numArticoli, price;
  double totprice = 0, iva;
  char exit;
  char codiceStato[2];
  do{
    cout << "Inserire il numero di articoli: " << endl;
    cin >> numArticoli;
    do{
      cout << "Inserire il codice stato: " << endl;
      cin >> codiceStato;
      iva = StateCode(codiceStato);
    }while(iva==0);
    cout << "Inserire il prezzo unitario: " << endl;
    cin >> price;
    totprice += price*numArticoli;
    cout << "Il prezzo totale è: " << totprice << endl << "Il numero di articoli è: " << numArticoli
    << endl << "Il prezzo unitario è: " << price << endl << "L'IVA è: " << iva << endl;
    cout << "Inserire un carattere diverso da Q per inserire un altro articolo" << endl;
    cin >> exit;
  }while(exit!='Q');
  cout << "Prezzo Totale senza IVA: " << totprice << endl;
  totprice += iva/100*totprice;
  cout << "Il prezzo totale iva compresa: " << totprice << endl;
  return 0;
}
/*Short User Stories Pros:
  Più semplici da modificare
  Più leggere da testare
  Pezzi di codice già pronti alla fine di ogni sprint grazie alla semplicità di sviluppo  di ognuna

Problema:

Inserire:
  -numero articoli
  -prezzo unitario
  -codice nazione
Dati:
  Per ogni stato esiste una percentuale IVA
  Sconti
*/
