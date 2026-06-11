#include <iostream>
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
    std::cout << "O Goblin causou 15 de dano!\n";

    vidaHeroi -= 15;

    if(vidaHeroi <  0) {
        vidaHeroi = 0;
        std::cout << "Voce Morreu!\n";
    }
    
}

void atacarGoblin(int &vidaGoblin, int &pocaoCura) {

    std::cout << "Voce atacou o Goblin\n";


    vidaGoblin -= 10;

    if(vidaGoblin <= 0) {
        std::cout << "Goblin Derrotado!\n";
        pocaoCura++;
       std::cout << "Voce encontrou uma pocao!\n";
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
        std::cout << "=========================\n";
        std::cout << "    MEU PRIMEIRO RPG\n";
        std::cout << "=========================\n";
        std::cout << "1 - Mostrar Vida Atual\n";
        std::cout << "2 - Usar Pocao de Cura\n";
        std::cout << "3 - Lutar contra Goblin\n";
        std::cout << "4 - Atacar\n";
        std::cout << "5 - Sair do jogo\n";
        std::cout << "=========================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> escolha;
        std::cout << "\n";

        if (escolha == 5)
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
            lutarGoblin(vidaHeroi);
            std::cout << "Levou Dano -> Vida Atual: " << vidaHeroi << "\n";     
            break;

        case 4:
            atacarGoblin(vidaGoblin, pocaoCura);
            std::cout << "Vida Restante: " << vidaGoblin << " | Sua Pocoes: " << pocaoCura << "\n";
            break;

        default:
            std::cout << "Opcao invalida\n";
        }
    }
    return 0;
}
