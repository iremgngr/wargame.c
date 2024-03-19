#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buyArmor(int *gold, int *armor){
	int a, gold1, armor1;
	gold1 = *gold, armor1 = *armor;
	printf("1-leather=>10 golds, armor:+5\n2-mixed=>20 golds, armor:+10\n3-steel=>30 golds, armor:+15\n");
	scanf("%d", &a);
	switch(a){
		case 1:
			*armor=*armor+5;
			*gold=*gold-10;
			break;
		case 2:
			*armor=*armor+10;
			*gold=*gold-20;
			break;
		case 3:
			*armor=*armor+15;
			*gold=*gold-30;
			break;
		default:
			printf("error!\n");
			break;
	}
	if(*gold<0){
		printf("You don't have enough gold to buy this item.\n");
		*gold = gold1;
		*armor = armor1;
	}
	return a;
}

int buyWeapon(int *gold, int *damage){
	int weapon, gold2, damage1;
	gold2 = *gold, damage1 = *damage;
	printf("1-spear=>30 golds, damage:20\n2-ax=>45 golds, damage:30\n3-Sword=>90 golds, damage:50\n4-arrow=>25 golds, damage:15\n");
	scanf("%d", &weapon);
	switch(weapon){
		case 1: 
			*gold=*gold-30;
			*damage=*damage+20;
			break;
		case 2:
			*gold=*gold-45;
			*damage=*damage+30;
			break;
		case 3:
			*gold=*gold-90;
			*damage=*damage+50;
			break;
		case 4:
			*gold=*gold-25;
			*damage=*damage+15;
			break;
		default:
			printf("error!\n");
			break;
	}
		if(*gold<0){
		printf("You don't have enough gold to buy this item.\n");
		*gold = gold2;
		*damage = damage1;
	}
	return weapon;
}

int buyHealthCare(int *gold, int *health){
	int h, gold3, health1;
	gold3 = *gold, health1 = *health;
	printf("1- +300 health care=>50 golds\n2- +150 health care=>25 golds\n");
	scanf("%d", &h);
	switch(h){
		
		case 1:
			*health=*health+300;
			*gold=*gold-50;
			break;
		case 2:
			*health=*health+150;
			*gold=*gold-25;
			break;
		default:
			printf("error!\n");
			break;
	}
	if(*gold<0){
		printf("You don't have enough gold to buy this item.\n");
		*gold = gold3;
		*health = health1;
	}
	return h;
}

int shoppingCentre(int *gold, int *damage, int *health, int *armor){
	
	int sc=0;
	
	while(sc!=5){
		
		printf("\nShopping Centre Menu:\n");
		printf("1-Health Care, 2-Weapon, 3-Armor, 4-Check Inventory, 5-Exit: ");
		scanf("%d", &sc);
		if(sc==5){
			break;
		}

		switch(sc){
			
			case 1: 
				printf("Current amount of golds: %d\n", *gold);
				printf("Choose health type:\n");
				buyHealthCare(&*gold, &*health);
				break;
			case 2: 
				printf("Current amount of golds: %d\n", *gold);
				printf("Choose weapon type:\n");
				buyWeapon(&*gold, &*damage);
				break;
			case 3: 
				printf("Current amount of golds: %d\n", *gold);
				printf("Choose armor type:\n");	
				buyArmor(&*gold, &*armor);
				break;
			case 4:
				printf("Your Health Status: %d, damage power: %d, armor:+%d, gold:%d\n", *health, *damage, *armor, *gold);
				break;
		}
		continue;
	}
	
	return sc;
}

void displayCharacters(int *gold, int *damage, int *health, int *armor, int *character){
	
	srand(time(NULL));
	
	int taken, ehealth, prize, i=0;
	
	*character=rand()%5+1;
	
	switch(*character){
		
		case 1:
			printf("\nYour enemy is Tiger from Agarta, his damage: 30, health: 70, given prize = 20 golds\n");
			taken=30, ehealth=70, prize=20;
			break;
		case 2:
			printf("\nYour enemy is Raiden, his damage power: 20, health: 100, given prize = 50 golds\n");
			taken=20, ehealth=100, prize=50;
			break;
		case 3:
			printf("\nYour enemy is Sub-zero, his damage power: 25, health: 200, given prize = 90 golds\n");
			taken=25, ehealth=200, prize=90;
			break;
		case 4:
			printf("\nYour enemy is Quan-Chi, his damage power: 45, health: 100, given prize = 120 golds\n");
			taken=45, ehealth=100, prize=120;
			break;
		case 5:
			printf("\nYour enemy is Shao-Kahn, his damage power: 70, health: 500, given prize = 150 golds\n");
			taken=70, ehealth=500, prize=150;
			break;
	}
	
	printf("\n-------------Fight Begins---------------\n");
	
	while(*health>0 || ehealth>0){
		i++;
		printf("Round %d\n", i);
		printf("Health: %d, Enemy Health: %d, Taken damage: %d, Given damage: %d, armor: %d\n", *health, ehealth, taken, *damage, *armor);
		
		*health=*health-taken+(*armor);
		ehealth=ehealth-(*damage);
		
		if(ehealth<=0){
			i++;
			printf("Round %d\n", i);
			printf("Health: %d, Enemy Health: %d, Taken damage: %d, Given damage: %d, armor: %d\n", *health, ehealth, taken, *damage, *armor);
			printf("\nEnemy is dead\n");
			*gold=(*gold)+prize;
			printf("You gained prize as %d golds and your current golds amount is: %d", prize, *gold);
			if(*character==5){
				printf("\nYou killed Shao-Khan. You won the game.\n");
			}
			break;
		}
		
		else if(*health<=0){
			i++;
			printf("Round %d\n", i);
			printf("Health: %d, Enemy Health: %d, Taken damage: %d, Given damage: %d, armor: %d\n", *health, ehealth, taken, *damage, *armor);
			printf("\ngame over\n");
			*character=5;
			break;
		}
	}
}



int main(){
	
	srand(time(NULL));
	
	int choice=1, gold=50, damage=0, health=300, armor=0, character;
	
	printf("-------Welcome to game arena-------");

	while(choice!=0){
		
		while(choice!=2){
			printf("\n\n1- Shopping Centre 2-War Zone: ");
			scanf("%d", &choice);
	
			if(choice==1){
				shoppingCentre(&gold, &damage, &health, &armor);
			}
		}
		
		displayCharacters(&gold, &damage, &health, &armor, &character);
		if(character==5){
			break;
		}
		choice=1;
	}
	return 0;
}
