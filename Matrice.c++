#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#define N 3
#define M 4
#define P 8
using namespace std;

struct facture{
int idFact;
float montant;
string objet;
string idcl;
};

struct client{
string idcl;
string nom;
string filiere;
string niveau;
};

struct facture Matfact[N][M];
struct client tabcl[P];

// Remplir Facture
void remplirFact() {
// Ligne 0
Matfact[0][0].idFact = 1;
Matfact[0][0].montant = 150000;
Matfact[0][0].objet = "Inscription";
Matfact[0][0].idcl ="CL002";

Matfact[0][1].idFact = 2;
Matfact[0][1].montant = 200000;
Matfact[0][1].objet = "Mensualite";
Matfact[0][1].idcl = "CL002";

Matfact[0][2].idFact = 3;
Matfact[0][2].montant = 250000;
Matfact[0][2].objet = "Inscription";
Matfact[0][2].idcl = "CL001";

Matfact[0][3].idFact = 4;
Matfact[0][3].montant = 600000;
Matfact[0][3].objet = "Mensualite";
Matfact[0][3].idcl = "CL001";

// Ligne 1
Matfact[1][0].idFact = 5;
Matfact[1][0].montant = 150000;
Matfact[1][0].objet = "Tenue";
Matfact[1][0].idcl = "CL002";

Matfact[1][1].idFact = 6;
Matfact[1][1].montant = 250000;
Matfact[1][1].objet = "Inscription";
Matfact[1][1].idcl = "CL003";

Matfact[1][2].idFact = 7;
Matfact[1][2].montant = 100000;
Matfact[1][2].objet = "Tenue";
Matfact[1][2].idcl = "CL003";

Matfact[1][3].idFact = 8;
Matfact[1][3].montant = 800000;
Matfact[1][3].objet = "Mensualite";
Matfact[1][3].idcl = "CL003";

// Ligne 2
Matfact[2][0].idFact = 9;
Matfact[2][0].montant = 700000;
Matfact[2][0].objet = "Mensualite";
Matfact[2][0].idcl = "CL002";

Matfact[2][1].idFact = 10;
Matfact[2][1].montant = 200000;
Matfact[2][1].objet = "Tenue";
Matfact[2][1].idcl = "CL004";

Matfact[2][2].idFact = 11;
Matfact[2][2].montant = 400000;
Matfact[2][2].objet = "Inscription";
Matfact[2][2].idcl = "CL005";

Matfact[2][3].idFact = 12;
Matfact[2][3].montant = 300000;
Matfact[2][3].objet = "Inscription";
Matfact[2][3].idcl = "CL006";

}

// Remplir client
void remplirClient() {
tabcl[0].idcl = "CL001";
tabcl[0].nom = "MOUSSA SAAR";
tabcl[0].filiere = "IR";
tabcl[0].niveau = "MASTER2";

tabcl[1].idcl = "CL002";
tabcl[1].nom = "JEAN DIOUF";
tabcl[1].filiere = "IR";
tabcl[1].niveau = "MASTER2";

tabcl[2].idcl = "CL003";
tabcl[2].nom = "DJIBRIL FALL";
tabcl[2].filiere = "MAI";
tabcl[2].niveau = "MASTER1";

tabcl[3].idcl = "CL004";
tabcl[3].nom = "OMAR SECK";
tabcl[3].filiere = "IR";
tabcl[3].niveau = "MASTER2";

tabcl[4].idcl = "CL005";
tabcl[4].nom = "AWA LY";
tabcl[4].filiere = "MAI";
tabcl[4].niveau = "MASTER2";

tabcl[5].idcl = "CL006";
tabcl[5].nom = "MARIEME FALL";
tabcl[5].filiere = "MAI";
tabcl[5].niveau = "MASTER1";

tabcl[6].idcl = "CL007";
tabcl[6].nom = "OUMY DIENG";
tabcl[6].filiere = "IR";
tabcl[6].niveau = "MASTER2";

tabcl[7].idcl = "CL008";
tabcl[7].nom = "MATY MBAYE";
tabcl[7].filiere = "IR";
tabcl[7].niveau = "MASTER2";


}

// Nombre de clients
int nbClient() {
return P;
}

// Total inscription par filière
float totalInscription(string filiere) {
float total = 0;
int i, j;
for(i = 0; i < N; i++) {
for(j = 0; j < M; j++) {
if(Matfact[i][j].objet == "Inscription" || Matfact[i][j].objet == "inscription") { 
for(int k = 0; k < P; k++) {
if(tabcl[k].idcl == Matfact[i][j].idcl && tabcl[k].filiere == filiere) {
total += Matfact[i][j].montant;
}
}
}
}
}
return total;
}

// Moyenne mensualité
float moyenneMensualite() {
float total = 0;
int count = 0;
int i, j;
for(i = 0; i < N; i++) {
for(j = 0; j < M; j++) {
if(Matfact[i][j].objet == "Mensualite") {
total += Matfact[i][j].montant;
count++;
}
}
}
if(count > 0) {
return total / count;
}
return 0;
}

// Total paiement par ID client
float totalPaiementId(string idcl) {
float total = 0;
int i, j;
for(i = 0; i < N; i++) {
for(j = 0; j < M; j++) {
if(Matfact[i][j].idcl == idcl) {
total += Matfact[i][j].montant;
}
}
}
return total;
}

// Total paiement par niveau
float totalPaiementNiveau(string niveau) {
float total = 0;
int i, j;
for(i = 0; i < N; i++) {
for(j = 0; j < M; j++) {
for(int k = 0; k < P; k++) {
if(tabcl[k].idcl == Matfact[i][j].idcl && tabcl[k].niveau == niveau) {
total += Matfact[i][j].montant;
}
}
}
}
return total;
}

// Liste paiement par nom étudiant
void listePaiement(string nomEtudiant) {
string idClient = " ";
int i, j;


for(i = 0; i < P; i++) {
    if(tabcl[i].nom == nomEtudiant) {
        idClient = tabcl[i].idcl;
        break;
    }
}

if(idClient == "") {
    cout << "\nClient non trouve!\n";
    return;
}

cout << "\n=== PAIEMENTS DE " << nomEtudiant << " ===\n";
cout << left << setw(10) << "ID Fact" << setw(15) << "Montant" << setw(15) << "Objet" << endl;
cout << "--------------------------------------------\n";

for(i = 0; i < N; i++) {
    for(j = 0; j < M; j++) {
        if(Matfact[i][j].idcl == idClient) {
            cout << left << setw(10) << Matfact[i][j].idFact 
                 << setw(15) << Matfact[i][j].montant 
                 << setw(15) << Matfact[i][j].objet << endl;
        }
    }
}


}

// Affichage par ordre croissant / objet
void affichageParObjet() {
cout << "\n=== FACTURES PAR OBJET (ORDRE CROISSANT) ===\n";


facture temp[N*M];
int count = 0;
int i, j;

for(i = 0; i < N; i++) {
    for(j = 0; j < M; j++) {
        temp[count] = Matfact[i][j];
        count++;
    }
}

for(i = 0; i < count - 1; i++) {
    for(j = i + 1; j < count; j++) {
        if(temp[i].objet > temp[j].objet) {
            facture t = temp[i];
            temp[i] = temp[j];
            temp[j] = t;
        }
    }
}

cout << left << setw(10) << "ID Fact" << setw(15) << "Montant" 
     << setw(15) << "Objet" << setw(10) << "Client" << endl;
cout << "--------------------------------------------------------\n";

for(i = 0; i < count; i++) {
    cout << left << setw(10) << temp[i].idFact 
         << setw(15) << temp[i].montant 
         << setw(15) << temp[i].objet 
         << setw(10) << temp[i].idcl << endl;
}

}

// Max montant
void maxMontant() {
float max = Matfact[0][0].montant;
string objetMax = Matfact[0][0].objet;
int i, j;

for(i = 0; i < N; i++) {
    for(j = 0; j < M; j++) {
        if(Matfact[i][j].montant > max) {
            max = Matfact[i][j].montant;
            objetMax = Matfact[i][j].objet;
        }
    }
}

cout << "\n=== MONTANT MAXIMUM ===\n";
cout << "Montant: " << max << " FCFA\n";
cout << "Objet: " << objetMax << endl; 

}

// Liste versement par ID
void listeVersement(string idcl) {
cout << "\n=== VERSEMENTS DU CLIENT "<< idcl <<" ===\n";
cout << left << setw(10) << "ID Fact" << setw(15) << " Montant" << setw(15) << " Objet" << endl;
cout << " ––––––––––––––––––––––\n";

float total = 0;
int i, j;
for(i = 0; i < N; i++) {
    for(j = 0; j < M; j++) {
        if(Matfact[i][j].idcl == idcl) {
            cout << left << setw(10) << Matfact[i][j].idFact 
                 << setw(15) << Matfact[i][j].montant 
                 << setw(15) << Matfact[i][j].objet << endl;
            total += Matfact[i][j].montant;
        }
    }
}
cout << "--------------------------------------------\n";
cout << "TOTAL: " << total << " FCFA" << endl;

}

// Trier tableau client par nom
void trierTableauClient() {
int i, j;
for(i = 0; i < P - 1; i++) {
for(j = i + 1; j < P; j++) {
if(tabcl[i].nom > tabcl[j].nom) {
client temp = tabcl[i];
tabcl[i] = tabcl[j];
tabcl[j] = temp;
}
}
}
cout << " \nClients tries par nom avec succes!\n" ;
}

// Trier facture par montant
void trierFacture() {
int i, j, k, l;
for(i = 0; i < N; i++) {
for(j = 0; j < M; j++) {
for(k = 0; k < N; k++) {
for(l = 0; l < M; l++) {
if((i < k) || (i == k && j < l)) {
if(Matfact[i][j].montant > Matfact[k][l].montant) {
facture temp = Matfact[i][j];
Matfact[i][j] = Matfact[k][l];
Matfact[k][l] = temp;
}
}
}
}
}
}
cout << " \nFactures triees par montant avec succes!\n";
}

// Afficher tous les clients
void afficherClients() {
cout << " \n=== LISTE DES CLIENTS ===\n";
cout << left << setw(10) << " ID" << setw(20) << "Nom"
<< setw(10) << "Filiere" << setw(10) << "Niveau" << endl;
cout << "––––––––––––––––––––––––––\n";

for(int i = 0; i < P; i++) {
    cout << left << setw(10) << tabcl[i].idcl 
         << setw(20) << tabcl[i].nom 
         << setw(10) << tabcl[i].filiere 
         << setw(10) << tabcl[i].niveau << endl;
}


}

// Afficher toutes les factures
void afficherFactures() {
cout << "\n=== LISTE DES FACTURES ===\n";
cout << left << setw(10) << "ID Fact"<< setw(15) << "Montant"
<< setw(15) << "Objet" << setw(10) << "Client" << endl;
cout << "––––––––––––––––––––––––––\n";


for(int  i= 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
        cout << left << setw(10) << Matfact[i][j].idFact 
             << setw(15) << Matfact[i][j].montant 
             << setw(15) << Matfact[i][j].objet 
             << setw(10) << Matfact[i][j].idcl << endl;
    }
}


}

// Menu principal
void afficherMenu() {
cout << "\n========================================\n";
cout << "SYSTEME DE GESTION DES FACTURES\n";
cout << "========================================\n";
cout << "1.  Nombre de clients\n";
cout << "2.  Total inscription par filiere\n";
cout << "3.  Moyenne des mensualites\n" ;
cout << "4.  Total paiement par client (ID)\n";
cout << "5.  Total paiement par niveau\n";
cout << "6.  Liste paiements d’un etudiant\n";
cout << "7.  Afficher factures par objet\n";
cout << "8.  Montant maximum\n";
cout << "9.  Liste versements par ID client\n";
cout << "10. Trier clients par nom\n";
cout << "11. Trier factures par montant\n";
cout << "12. Afficher tous les clients\n";
cout << "13. Afficher toutes les factures\n";
cout << "0.  Quitter\n";
cout << "========================================\n";
cout << "Votre choix: ";
}

int main() {
remplirFact();
remplirClient();


cout << "Donnees chargees avec succes!\n";

int choix;
string input;

do {
    afficherMenu();
    cin >> choix;
    cin.ignore();
    
    switch(choix) {
        case 1:
            cout << "\nNombre de clients: " << nbClient() << endl;
            break;
            
        case 2:
            cout << "Entrez la filiere (IR/MAI): ";
            cin >> input;
            cout << "Total inscription pour " << input << ": " 
                 << totalInscription(input) << " FCFA" << endl;
            break;
            
        case 3:
            cout << "Moyenne des mensualites: " 
                 << fixed << setprecision(2) 
                 << moyenneMensualite() << " FCFA" << endl;
            break;
            
        case 4:
            cout << "Entrez l'ID du client (ex: CL001): ";
            cin >> input;
            cout << "Total paiement pour " << input << ": " 
                 << totalPaiementId(input) << " FCFA" << endl;
            break;
            
        case 5:
            cout << "Entrez le niveau (MASTER1/MASTER2): ";
            cin >> input;
            cout << "Total paiement pour " << input << ": " 
                 << totalPaiementNiveau(input) << " FCFA" << endl;
            break;
            
        case 6:
            cout << "Entrez le nom complet de l'etudiant: ";
            getline(cin, input);
            listePaiement(input);
            break;
            
        case 7:
            affichageParObjet();
            break;
            
        case 8:
            maxMontant();
            break;
            
        case 9:
            cout << "Entrez l'ID du client (ex: CL001): ";
            cin >> input;
            listeVersement(input);
            break;
            
        case 10:
            trierTableauClient();
            break;
            
        case 11:
            trierFacture();
            break;
            
        case 12:
            afficherClients();
            break;
            
        case 13:
            afficherFactures();
            break;
            
        case 0:
            cout << "\nMerci d'avoir utilise le systeme!\n";
            break;
            
        default:
            cout << "\nChoix invalide! Reessayez.\n";
    }
    
    if(choix != 0) {
        cout << "\nAppuyez sur Entree pour continuer...";
        cin.get();
    }
    
} while(choix != 0);

return 0;

}