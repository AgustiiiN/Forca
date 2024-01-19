#include<iostream>
#include<locale.h>


int main() {
	setlocale(LC_ALL, "");
inicio:

	char palavra[30], letra[1], secreta[30], restart;
	int tam, i, chances, acertos;
	bool acerto = false;

	chances = 6;
	tam = 0;
	i = 0;
	acertos = 0;

	std::cout << "Digite a palavra secreta: ";
	std::cin >> palavra;
	system("cls");
	
	while (palavra[i] != '\0') {
		i++;
		tam++;
	}
	
	for (i = 0; i < 30; i++) {
		secreta[i] = '-';
	}

	while ((chances > 0) && (acertos < tam)) {
		std::cout << "Jogadas restantes: " << chances <<"\n\n";
		std::cout << "Palavra secreta: ";
		for (i = 0; i < tam; i++) {
			std::cout << secreta[i];
		}
		std::cout << "\n\nDigite uma letra: ";
		std::cin >> letra[0];
		for (i = 0; i < tam; i++) {
			if (palavra[i] == letra[0]){
				acerto = true;
				secreta[i] = palavra[i];
				acertos++;
				}
		}
		if (!acerto) {
			chances--;
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