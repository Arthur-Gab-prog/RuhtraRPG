#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


void usarPocao(int &pocaoCura, int &vidaHeroi)
{

    if (pocaoCura <= 0)
    {
        std::cout << "Sem poções restantes!\n";
        return;
    }
    pocaoCura -= 1;
    vidaHeroi += 25;
    std::cout << "Usando Poção...\n";

    if (vidaHeroi > 100)
    {
        vidaHeroi = 100;
        std::cout << "Limite de vida atingido (100)!\n";
    }
}

void lutarGoblin(int &vidaHeroi) {

    std::cout << "Voce encontrou um Goblin!\n";
    std::cout << "O Goblin atacou!\n";
    
    int danoGoblin = (rand() % 11) + 10;

    vidaHeroi -= danoGoblin;

    if(vidaHeroi <  0) {
        vidaHeroi = 0;
        std::cout << "Voce Morreu!\n";
    }
    
}

void atacarGoblin(int &vidaGoblin, int &pocaoCura) {

    std::cout << "Voce atacou o Goblin\n";

    int danoHeroi = (rand() % 8) + 8;

    
    int chanceCritico = (rand() % 5) + 1;
    if(chanceCritico == 1) {
        danoHeroi = danoHeroi * 2;
        std::cout << "ATAQUE CRITICO!";
    }

    std::cout << "Voce causou " << danoHeroi << " de dano ao Goblin\n";

    if(vidaGoblin <= 0) {
        std::cout << "Goblin Derrotado!\n";
        pocaoCura++;
        std::cout << "Voce encontrou uma pocao no corpo do Goblin!\n";

        vidaGoblin = 30;
        std::cout << "[Um novo Goblin surgiu na masmorra com 30 de vida!]\n";
    }
}

void iniciarCombate(int &vidaHeroi, int &vidaGoblin, int &pocaoCura) {
    std::cout << "-------------------------------------------\n";
    std::cout << "   VOCE ENCONTROU UM GOBLIN ENFURECIDO!";
    std::cout << "-------------------------------------------\n";

    while(vidaHeroi > 0 && vidaGoblin > 0) {
        std::cout << "\n[Seu Turno]: Voce avanca para atacar!\n";
        int danoHeroi = (rand() % 8) + 8;
        int chanceCritico = (rand() % 5) + 5;

        if(chanceCritico == 1) {
            danoHeroi *= 2;
            std::cout << " CRITICO! ";
        }
        std::cout << "Voce causou " << danoHeroi << " de dano.\n";
        vidaGoblin -= danoHeroi;

        if(vidaGoblin <= 0) {
            std::cout << "\n Goblin Derrotado!\n";
            pocaoCura++;
            std::cout << " Voce saqueou o corpo e encontrou +1 Pocao!\n";
            vidaGoblin = 30;
            break;
        }

        std::cout << "Vida do Goblin: " << vidaGoblin << "\n";

        std::cout << "\n[Turno do Goblin]: O Goblin revida com as garras!n";
        int danoGoblin = (rand() % 11) + 10;
        std::cout << "O Goblin causou " << danoGoblin << " de dano em voce.\n";
        vidaHeroi -= danoGoblin;

        if(vidaheroi <= 0) {
            vidaHeroi = 0;
            std::cout << "\n Voce foi brutalmente derrotado... FIM DE JOGO.\n";
            break;
        }

        std::cout << "Sua vida Atual: " << vidaHeroi << "\n";
        std::cout << "--------------------------------------------\n";

        std::cout << "Pressione ENTER para o proximo turno...";
        std::cin.ignore();
        std::cin.get();
    }
}
int main()
{
    srand(time(0));

    int vidaHeroi = 50;
    int vidaGoblin = 30;
    int pocaoCura = 3;
    int escolha;

    while (true)
    {
        std::cout << "=========================\n";
        std::cout << "    MEU PRIMEIRO RPG\n";
        std::cout << "=========================\n";
        std::cout << "1 - Mostrar Vida Atual\n";
        std::cout << "2 - Usar Pocao de Cura\n";
        std::cout << "3 - Explorar a Masmorra (Entrar em Luta)\n";
        std::cout << "4 - Sair do jogo\n";
        std::cout << "=========================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> escolha;
        std::cout << "\n";

        if(vidaHeroi <= 0 && escolha != 4) {
            std::cout << "Voce esta morto! Nao pode fazer acoes. Saia do jogo.\n ";
            continue;
        }

        if (escolha == 4)
        {
            std::cout << "Saindo do jogo... Obrigado por jogar\n";
            break;
        }

        switch (escolha)
        {
        case 1:
            std::cout << "Status Inicial -> Vida: " << vidaHeroi << " | Pocoes: " << pocaoCura << "\n";
           
            break;

        case 2:
            usarPocao(pocaoCura, vidaHeroi);
            std::cout << "Status Inicial -> Vida: " << vidaHeroi << " | Pocoes: " << pocaoCura << "\n";
            break;

        case 3:
           iniciarCombate(vidaHeroi, vidaGoblin, pocaoCura);    
            break;

        default:
            std::cout << "Opcao invalida\n";
        }
    }
    return 0;
}
