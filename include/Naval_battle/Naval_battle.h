#ifndef Naval_battle_H_
#define Naval_battle_H_

#include <fstream>

#include "Griglia.h"
#include "Corazzata.h"
#include "Supporto.h"
#include "Sottomarino.h"

class Naval_battle {
private:
    bool botBattle;             //variabile che se é true dice che la battaglia non ha giocatori umani ma solo due bot
    bool log;                   //variabile che indica se é necessario o meno il logging su file
    std::ofstream log_file;     //variablie per la scrittura dei log su file (viene utilizzata solo se richiesto) altrimenti rimane non inizializzate


    //Tutti gli elementi del giocatore 1
    Griglia g1_attacco;
    Griglia g1_difesa;
    Corazzata g1_corazzata1;
    Corazzata g1_corazzata2;
    Corazzata g1_corazzata3;
    Supporto g1_supporto1;
    Supporto g1_supporto2;
    Supporto g1_supporto3;
    Sottomarino g1_sottomarino1;
    Sottomarino g1_sottomarino2;

    //Tutti gli elementi del giocatore 2
    Griglia g2_attacco;
    Griglia g2_difesa;
    Corazzata g2_corazzata1;
    Corazzata g2_corazzata2;
    Corazzata g2_corazzata3;
    Supporto g2_supporto1;
    Supporto g2_supporto2;
    Supporto g2_supporto3;
    Sottomarino g2_sottomarino1;
    Sottomarino g2_sottomarino2;


    int g1_navi();     //conta le navi attualmente in vita del giocatore 1.
    int g2_navi();     //conta le navi attualemente in vida del giocatore 2.
    void bot_g1_command();  //funzioni che gestisce i comandi del bot del giocatore1
    void bot_g2_command();  //funzione che gestisce i comandi del bot del giocatore2
    void accept_command();  //funzione che accetta i vari comandi che il giocatore inserisce
    void bot_command(int giocatore_primo);     //funzione che gestisce azioni dei bot (casuali)

public:
    Naval_battle(std::string battletype, bool log_or_not);  //serve a capire se la  partita iniziata è del tipo "giocatore vs computer" o "computer vs computer"

    void setup(int giocatore_primo);           //posiziona le navi del giocatore e "crea" le navi del bot
    void command(int giocatore_primo); //gestisce tutti i comandi (inseriti dall'utente ed automatici dei bot)
    int winner();           //se ritorna 1 vince giocatore 1, se ritorna 2 vince giocatore 2 altrimenti ritorna 0
    bool is_botBattle();    //funzione membro per capire se la battaglia è del tipo "computer vs computer"

};


#endif // Naval_battle_H_
