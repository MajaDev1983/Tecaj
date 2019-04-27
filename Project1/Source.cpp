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

	int mVelocity;
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
	
	std::string getPrivateString()
	{
		return _privateString;
	}

	void setPrivateString(std::string stringParam)
	{
		_privateString = stringParam;
	}

private:
	std::string _privateString;
	std::string m_privateString;

protected:
	std::string _protectedString;
};



//void move(int& x, int& y, int& velocity)
//{
//	x += velocity;
//	y += velocity;
//}

int main()
{
	int counter = 1;
	std::string nameOne, nameTwo, nameThree;
	std::cout << "This is a simple game involving 3 players." << std::endl;
	
	std::cout << "Player number one what is your name?" << std::endl;
	std::cin >> nameOne;
	Player playerOne = Player(0, 0, 10, 30);
	playerOne.userName = nameOne;
	
	//move(playerOneX, playerOneY, velocity); // pass by value, ali se stavi gore u funkciju & i to je by reference

	std::cout << "Player number two what is your name?" << std::endl;
	std::cin >> nameTwo;
	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.userName = nameTwo;

	std::cout << "Player number three what is your name?" << std::endl;
	std::cin >> nameThree;
	Player playerThree = Player(15, 20, 10, 30);
	playerThree.userName = nameThree;

	playerOne.move();
	playerTwo.move();

	playerOne.setPrivateString("Ja sam privatan!");

	//std::string losingPlayerFirst;
	//std::string losingPlayerSecond;
	//std::string winningPlayerFirst;
	//std::string winningPlayerSecond;

	std::cout << playerOne.getPrivateString() << std::endl;

	while (playerOne.hp > 0 && playerTwo.hp > 0 && playerThree.hp > 0)
	{
		std::cout << "================================================" << std::endl;
		std::cout << "Round number " << counter << " begins!" << std::endl;
		std::string hitter;
		std::cout << "Who is doing the hitting?" << std::endl;
		std::cin >> hitter;

		int check;
		std::cout << "Choose which player you want to hit: ";
		std::cin >> check;
		std::cout << std::endl;

		std::cin.ignore(1000, '\n');
		std::cin.clear();
		switch (check)
		{
		case 1:
			playerOne.damage(5);
			std::cout << "Player " << playerOne.userName << " lost 5 hitpoints by " << hitter <<  std::endl;
			break;
		case 2:
			playerTwo.damage(5);
			std::cout << "Player " << playerTwo.userName << " lost 5 hitpoints by " << hitter << std::endl;
			break;
		case 3:
			playerThree.damage(5);
			std::cout << "Player " << playerThree.userName << " lost 5 hitpoints by " << hitter << std::endl;
			break;
		default:
			break;
		}

		std::cout << "\nPlayer " << playerOne.userName << " hitpoints: " << playerOne.hp << std::endl;
		std::cout << "Player " << playerTwo.userName << " hitpoints: " << playerTwo.hp << std::endl; 
		std::cout << "Player " << playerThree.userName << " hitpoints: " << playerThree.hp << std::endl;

		++counter;
	}

	std::cout << "\n";
	if(playerTwo.hp > playerOne.hp && playerThree.hp > playerOne.hp)
	{
		std::cout << playerOne.userName << " lost! Better luck next time!" << std::endl;
		if (playerTwo.hp > playerThree.hp)
		{
			std::cout << playerTwo.userName << " wins! Congartulations!";
		}
		else if (playerTwo.hp < playerThree.hp)
		{
			std::cout << playerThree.userName << " wins! Congartulations!";
		}
		else if (playerTwo.hp == playerThree.hp)
		{
			std::cout << playerThree.userName << " & " << playerTwo.userName << " win! Congartulations!";
		}
	}
	if(playerOne.hp > playerTwo.hp && playerThree.hp > playerTwo.hp)
	{
		std::cout << playerTwo.userName << " lost! Better luck next time!" << std::endl;
		if (playerOne.hp > playerThree.hp)
		{
			std::cout << playerOne.userName << " wins! Congartulations!";
		}
		else if (playerOne.hp < playerThree.hp)
		{
			std::cout << playerThree.userName << " wins! Congartulations!";
		}
		else if (playerOne.hp == playerThree.hp)
		{
			std::cout << playerOne.userName << " & " << playerThree.userName << " win! Congartulations!";
		}
	}
	if (playerOne.hp > playerThree.hp && playerTwo.hp > playerThree.hp)
	{
		std::cout << playerThree.userName << " lost! Better luck next time!" << std::endl;
		if (playerOne.hp > playerTwo.hp)
		{
			std::cout << playerOne.userName << " wins! Congartulations!";
		}
		else if (playerOne.hp < playerTwo.hp)
		{
			std::cout << playerTwo.userName << " wins! Congartulations!";
		}
		else if (playerOne.hp == playerTwo.hp)
		{
			std::cout << playerOne.userName << " & " << playerTwo.userName << " win! Congartulations!";
		}
	}


	//std::cout << winningPlayer << " wins! Congratulations!" << std::endl;
	//std::cout << losingPlayerFirst << " & " << losingPlayerSecond << " lost! Better luck next time!";

	std::cin.get();

	//napravi još jednog playera, te postaviti mogucnost za biranje usernamea.
	//prosiriti mogucnost dameganja playera tako da se bira koji ce kojeg udariti.

	return 0;
}