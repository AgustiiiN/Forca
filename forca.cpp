#include<iostream>
#include<locale.h>

void forca(int chances);

int main() {
	setlocale(LC_ALL, "");
inicio:

	char palavra[30], letra[1], secreta[30], restart;
	int tam{ 0 }, i{ 0 }, acertos{ 0 }, chances{ 6 };
	bool acerto=false;

	std::cout << "Digite a palavra secreta: ";
	std::cin >> palavra;
	system("cls");
	
	while (palavra[i] != '\0') {
		i++;
		tam++;
	}

	for (i = 0; i < 30; ++i) {
		secreta[i] = '-';
	}

	while ((chances > 0) && (acertos < tam)) {
		std::cout << "Jogadas restantes: " << chances <<"\n";
		forca(chances);
		std::cout << "\nPalavra secreta: ";
		for (i = 0; i < tam; ++i) {
			std::cout << secreta[i];
		}
		std::cout << "\n\nDigite uma letra: ";
		std::cin >> letra[0];
		for (i = 0; i < tam; ++i) {
			if (palavra[i] == letra[0]){
				acerto = true;
				secreta[i] = palavra[i];
				++acertos;
				}
		}
		if (!acerto) {
			--chances;
		}
		acerto = false;
		system("cls");
	}
	if (acertos == tam) {
		std::cout << "Você venceu!\n\n";
	}else {
		std::cout << "Perdeu kkk\n\n";
	
	}
	
	do {
		std::cout << "Quer jogar denovo? [s/n]: ";
		std::cin >> restart;
	} while (restart != 's' && restart != 'n');

	if (restart == 's') {
		system("cls");
		goto inicio;
	}
	else {
		system("exit");
	}
		
	return 0;
}

void forca(int chances) {
	switch (chances)
	{
	case 5:
		std::cout << "_______\n |   |\n |   O\n | \n |\n |\n |\n==========\n"; //Cabeça
		break;
	case 4:
		std::cout << "_______\n |   |\n |   O\n |  / \n |\n |\n |\n==========\n"; //Cabeça e braço esquerdo
		break;
	case 3:
		std::cout << "_______\n |   |\n |   O\n |  / \\\n |\n |\n |\n==========\n"; //cabeça e ambos braços
		break;
	case 2:
		std::cout << "_______\n |   |\n |   O\n |  / \\\n |   |\n |\n |\n==========\n"; //Cab, breços e Tronco
		break;
	case 1:
		std::cout << "_______\n |   |\n |   O\n |  / \\\n |   |\n |  / \n |\n==========\n"; //Cab, breços, Tronco e perna esquerda
		break;
	case 0:
		std::cout << "_______\n |   |\n |   O\n |  / \\\n |   |\n |  / \\\n |\n==========\n"; //Corpo completo
		break;
	default:
		std::cout << "_______\n |   |\n |\n |\n |\n |\n |\n==========\n"; //Vazia
		break;
	}
}