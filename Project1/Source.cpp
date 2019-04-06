#include <iostream>
#include <string>

class Player
{

public:
	Player(int positionX, int positionY, int currentVelocity, int currentHp)
	{
		x = positionX;
		y = positionY;
		velocity = currentVelocity;
		hp = currentHp;
	}

	std::string userName;
	int x, y, velocity, hp, strenght;

	void move()
	{
		x += velocity;
		y += velocity;
	}

	void damage(int ammount)
	{
		hp -= ammount;
	}
};



void move(int& x, int& y, int& velocity)
{
	x += velocity;
	y += velocity;
}

int main()
{
	Player playerOne = Player(0, 0, 10, 30);
	playerOne.userName = "Chaos";
	
	//move(playerOneX, playerOneY, velocity); // pass by value, ali se stavi gore u funkciju & i to je by reference

	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.userName = "robi";


	playerOne.move();
	playerTwo.move();

	std::string losingPlayer;
	std::string winnigPlayer;

	while (playerOne.hp > 0 && playerTwo.hp > 0)
	{
		int check;
		std::cout << "Choose whitch player you want to hit: ";
		std::cin >> check;
		std::cout << std::endl;

		std::cin.ignore(1000, '\n');
		std::cin.clear();
		switch (check)
		{
		case 1:
			playerOne.damage(5);
			std::cout << "Player one lost 5 hitpoints" << std::endl;
			break;
		case 2:
			playerTwo.damage(5);
			std::cout << "Player two lost 5 hitpoints" << std::endl;
			break;
		default:
			break;
		}

		std::cout << "Player one hitpoints: " << playerOne.hp << std::endl;
		std::cout << "Player two hitpoints: " << playerTwo.hp << std::endl;
	}

	if(playerOne.hp <= 0)
	{
		losingPlayer = playerOne.userName;
	}
	else if(playerTwo.hp <= 0)
	{
		losingPlayer = playerTwo.userName;
	}

	std::cout << winningPlayer << "wins! Congratulations!" << std::endl;
	std::cout << losingPlayer << " lost! Better luck next time!";

	std::cin.get();

	//napravi još jednog playera, te postaviti mogucnost za biranje usernamea.
	//prosiriti mogucnost dameganja playera tako da se bira koji ce kojeg udariti.

	return 0;
}