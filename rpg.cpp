#include <iostream>
#include <string>

using namespace std;

void usarPocao(int &pocaoCura, int &vidaHeroi)
{

    if (pocaoCura <= 0)
    {
        cout << "Sem poções restantes!" << endl;
        return;
    }
    pocaoCura -= 1;
    vidaHeroi += 25;
    cout << "Usando Poção..." << endl;

    if (vidaHeroi > 100)
    {
        vidaHeroi = 100;
        cout << "Limite de vida atingido (100)!" << endl;
    }
}

void lutarGoblin(int &vidaHeroi) {

    cout << "Voce encontrou um Goblin!" << endl;
    cout << "O Goblin atacou!" << endl;
    cout << "O Goblin causou 15 de dano!" << endl;

    vidaHeroi -= 15;

    if(vidaHeroi <  0) {
        vidaHeroi = 0;
        cout << "Voce Morreu!" << endl;
    }
    
}

void atacarGoblin(int &vidaGoblin, int &pocaoCura) {

    cout << "Voce atacou o Goblin" << endl;


    vidaGoblin -= 10;

    if(vidaGoblin <= 0) {
        cout << "Goblin Derrotado!" <<  endl;
        pocaoCura++;
        cout << "Voce encontrou uma pocao!" << endl;
    }
}

int main()
{

    int vidaHeroi = 50;
    int vidaGoblin = 30;
    int pocaoCura = 3;
    int escolha;

    while (true)
    {
        cout << "=========================" << endl;
        cout << "    MEU PRIMEIRO RPG" << endl;
        cout << "=========================" << endl;
        cout << "1 - Mostrar Vida Atual" << endl;
        cout << "2 - Usar Pocao de Cura" << endl;
        cout << "3 - Lutar contra Goblin" << endl;
        cout << "4 - Atacar" << endl;
        cout << "5 - Sair do jogo" << endl;
        cout << "=========================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;
        cout << endl;

        if (escolha == 5)
        {
            cout << "Saindo do jogo... Obrigado por jogar" << endl;
            break;
        }

        switch (escolha)
        {
        case 1:
            cout << "Status Inicial -> Vida: " << vidaHeroi << " | Pocoes: " << pocaoCura << endl;
           
            break;

        case 2:
            usarPocao(pocaoCura, vidaHeroi);
            cout << "Status Inicial -> Vida: " << vidaHeroi << " | Pocoes: " << pocaoCura << endl;
            break;

        case 3:
            lutarGoblin(vidaHeroi);
            cout << "Levou Dano -> Vida Atual: " << vidaHeroi << endl;     
            break;

        case 4:
            atacarGoblin(vidaGoblin, pocaoCura);
            cout << "Vida Restante: " << vidaGoblin <<  pocaoCura << endl;
            break;

        default:
            cout << "Opcao invalida";
        }
    }
    return 0;
}
