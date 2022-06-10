#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {

	int minute;
	int hour;
	int day;
	int month;
	int year;

} Date;

typedef struct Buyer {

	char firstName[100];
	char lastName[100];
	char email[100];
	char phoneNumber[11];

} Buyer;

typedef struct Article {

	int number;
	char reference[6];
	char commercialName[100];
	char commonName[100];
	char category[100];
	char underCategory[100];
	char brand[100];
	char barcode[14];
	char serialNumber[7];
	char color[100];
	char material[100];
	int weight;
	int lenght;
	int width;
	int height;
	Date manufacturingDate;
	Date expiryDate;
	double valueAddedTax;
	double price;
	int numberAvailableUnits;

} Article;

typedef struct Element {

	Article article;
	void* next;

} Element;

typedef struct List {

	Element* first;

} List;

Article article0 = {
0, "00000", "NAME0", "COMMONNAME0", "CATEGORY0", "UNDERCATEGORY0", "BRAND0", "0000000000000", "000000", "COLOR0", "MATERIAL0", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article1 = {
1, "11111", "NAME1", "COMMONNAME1", "CATEGORY1", "UNDERCATEGORY1", "BRAND1", "1111111111111", "111111", "COLOR1", "MATERIAL1", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article2 = {
2, "22222", "NAME2", "COMMONNAME2", "CATEGORY2", "UNDERCATEGORY2", "BRAND2", "2222222222222", "222222", "COLOR2", "MATERIAL2", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article3 = {
3, "33333", "NAME3", "COMMONNAME3", "CATEGORY3", "UNDERCATEGORY3", "BRAND3", "3333333333333", "333333", "COLOR3", "MATERIAL3", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article4 = {
4, "44444", "NAME4", "COMMONNAME4", "CATEGORY4", "UNDERCATEGORY4", "BRAND4", "4444444444444", "444444", "COLOR4", "MATERIAL4", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article5 = {
5, "55555", "NAME5", "COMMONNAME5", "CATEGORY5", "UNDERCATEGORY5", "BRAND5", "5555555555555", "555555", "COLOR5", "MATERIAL5", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article6 = {
6, "66666", "NAME6", "COMMONNAME6", "CATEGORY6", "UNDERCATEGORY6", "BRAND6", "6666666666666", "666666", "COLOR6", "MATERIAL6", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article7 = {
7, "77777", "NAME7", "COMMONNAME7", "CATEGORY7", "UNDERCATEGORY7", "BRAND7", "7777777777777", "777777", "COLOR7", "MATERIAL7", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article8 = {
8, "88888", "NAME8", "COMMONNAME8", "CATEGORY8", "UNDERCATEGORY8", "BRAND8", "8888888888888", "888888", "COLOR8", "MATERIAL8", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };
Article article9 = {
9, "99999", "NAME9", "COMMONNAME9", "CATEGORY9", "UNDERCATEGORY9", "BRAND9", "9999999999999", "999999", "COLOR9", "MATERIAL9", 250, 1000, 1000, 1000, {0, 0, 1, 1, 2020}, {0, 0, 1, 1, 2021}, 10, 100, 10 };

void mainMenu(List* list, Article* table[]);
void seller(List* list, Article* table[]);
void displayArticleData(Element* pointer);
void displayCart(List* list, Article* table[]);
void addArticleMenu(List* list, Article* table[]);
void addArticleCart(List* list, Article* article);
void displayArticleDataMenu(List* list, Article* table[]);
void fullDisplayArticleData(List* list, Article* table[], int i);
void displayBill(List* list, Article* table[]);
void files();
void fTime();
void displayAllArticles(List* list, Article* table[]);
double totalPrice(List* list);
void deleteLastArticle(List* list, Article* table[]);
void goodBye(List* list);

void mainMenu(List* list, Article* table[]) {

	system("clear");
	printf("WELCOME DEAR CUSTOMER TO OUR MARKET!\n");
	printf("PLEASE TAKE A SEAT AND SELECT OUR PRODUCTS\n\n");
	printf("SHOW THE ARTICLES                              <A>\n");
	printf("SHOW THE ARTICLES DETAILS                      <B>\n");
	printf("ADD AN ARTICLE IN YOUR CART                    <C>\n");
	printf("CHECK YOUR CART                                <D>\n");
	printf("GO TO THE BILL                                 <E>\n");
	printf("SHOW SHOP INFORMATION                          <F>\n");
	printf("EXIT THE MARKET                                <G>\n\n");

	char enter = '-';
	scanf("%c", &enter);
	if (enter == 'A' || enter == 'B' || enter == 'C' || enter == 'D' || enter == 'E' || enter == 'F' || enter == 'G') {
		switch (enter) {
		case 'A': displayAllArticles(list, table); break;
		case 'B': displayArticleDataMenu(list, table); break;
		case 'C': addArticleMenu(list, table); break;
		case 'D': displayCart(list, table); break;
		case 'E': displayBill(list, table); break;
		case 'F': seller(list, table); break;
		case 'G': goodBye(list); break;
		}
	}
	else mainMenu(list, table);

}

void displayAllArticles(List* list, Article* table[]) {

	system("clear");

	int number = 0;
	for (int i = 0; i < 10; i++) {
		printf("%d)   ", number);
		printf("%s   %s   %s   %s   %s   %s   %s   ", table[i]->commercialName, table[i]->commonName, table[i]->category, table[i]->underCategory, table[i]->brand, table[i]->color, table[i]->material);
		printf("EXPIRY DATE: %d/%d/%d   ", table[i]->expiryDate.day, table[i]->expiryDate.month, table[i]->expiryDate.year);
		printf("PRICE: %f EUROS   ", table[i]->price);
		printf("QUANTITY: %d UNIT(S)\n\n", table[i]->numberAvailableUnits);
		number++;
	}

	printf("BACK TO THE MAIN MENU           <A>\n");
	printf("SHOW ARTICLES DETAILS           <B>\n");
	printf("ADD AN ARTICLE IN YOUR CART     <C>\n\n");

	char enter = '-';
	scanf("%c", &enter);
	if (enter == 'A' || enter == 'B' || enter == 'C') {
		switch (enter) {
			case 'A': mainMenu(list, table); break;
			case 'B': displayArticleDataMenu(list, table); break;
			case 'C': addArticleMenu(list, table); break;
		}
	}
	else displayAllArticles(list, table);

}

void displayArticleDataMenu(List* list, Article* table[]) {

	system("clear");
	printf("0) %s\n1) %s\n2) %s\n3) %s\n4) %s\n5) %s\n6) %s\n7) %s\n8) %s\n9) %s\n\n", table[0]->commercialName, table[1]->commercialName, table[2]->commercialName, table[3]->commercialName, table[4]->commercialName, table[5]->commercialName, table[6]->commercialName, table[7]->commercialName, table[8]->commercialName, table[9]->commercialName);
	printf("SELECT AN ARTICLE TO SEE ITS DETAILS     <?>\n");
	printf("BACK TO THE MAIN MENU                    <A>\n\n");
	char enter = '-';
	scanf("%c", &enter);

	if (enter == 'A' || enter == '0' || enter == '1' || enter == '2' || enter == '3' || enter == '4' || enter == '5' || enter == '6' || enter == '7' || enter == '8' || enter == '9') {
		switch (enter) {
		case 'A': mainMenu(list, table); break;
		case '0': fullDisplayArticleData(list, table, 0);
		case '1': fullDisplayArticleData(list, table, 1);
		case '2': fullDisplayArticleData(list, table, 2);
		case '3': fullDisplayArticleData(list, table, 3);
		case '4': fullDisplayArticleData(list, table, 4);
		case '5': fullDisplayArticleData(list, table, 5);
		case '6': fullDisplayArticleData(list, table, 6);
		case '7': fullDisplayArticleData(list, table, 7);
		case '8': fullDisplayArticleData(list, table, 8);
		case '9': fullDisplayArticleData(list, table, 9);
		}
	}
	else displayArticleDataMenu(list, table);

}

void fullDisplayArticleData(List* list, Article* table[], int i) {

	system("clear");
	printf("REFERENCE: %s\n", table[i]->reference);
	printf("COMMERCIAL NAME: %s\n", table[i]->commercialName);
	printf("COMMON NAME: %s\n", table[i]->commonName);
	printf("CATEGORY NAME: %s\n", table[i]->category);
	printf("UNDER CATEGORY: %s\n", table[i]->underCategory);
	printf("BRAND: %s\n", table[i]->brand);
	printf("BARCODE: %s\n", table[i]->barcode);
	printf("SERIAL NUMBER: %s\n", table[i]->serialNumber);
	printf("COLOR: %s\n", table[i]->color);
	printf("MATERIAL: %s\n", table[i]->material);
	printf("WEIGHT: %d\n", table[i]->weight);
	printf("LENGHT: %d\n", table[i]->lenght);
	printf("WIDTH: %d\n", table[i]->width);
	printf("HEIGHT: %d\n", table[i]->height);
	printf("EXPIRY DATE: %d/%d/%d\n", table[i]->expiryDate.day, table[i]->expiryDate.month, table[i]->expiryDate.year);
	printf("VALUE ADDED TAX: %f%%\n", table[i]->valueAddedTax);
	printf("PRICE: %f euros\n", table[i]->price);
	printf("NUMBER OF UNIT(S) REMAINING: %d\n\n", table[i]->numberAvailableUnits);

	printf("BACK     <A>\n\n");
	char enter = '-';
	scanf("%c", &enter);

	if (enter == 'A') displayArticleDataMenu(list, table);
	else fullDisplayArticleData(list, table, i);

}

void addArticleCart(List* list, Article* article) {

	Element* pointer0 = malloc(sizeof(Article));
	if (!pointer0) exit(-1);

	else {
		if (list->first) {
			Element* pointer1 = list->first;
			while (pointer1->next) {
				pointer1 = pointer1->next;
			}
			pointer1->next = pointer0;
		}
		else list->first = pointer0;
		pointer0->article.number = article->number;
		strcpy(pointer0->article.reference, article->reference);
		strcpy(pointer0->article.commercialName, article->commercialName);
		strcpy(pointer0->article.commonName, article->commonName);
		strcpy(pointer0->article.category, article->category);
		strcpy(pointer0->article.underCategory, article->underCategory);
		strcpy(pointer0->article.brand, article->brand);
		strcpy(pointer0->article.barcode, article->barcode);
		strcpy(pointer0->article.serialNumber, article->serialNumber);
		strcpy(pointer0->article.color, article->color);
		strcpy(pointer0->article.material, article->material);
		pointer0->article.weight = article->weight;
		pointer0->article.lenght = article->lenght;
		pointer0->article.width = article->width;
		pointer0->article.height = article->height;
		pointer0->article.manufacturingDate = article->manufacturingDate;
		pointer0->article.expiryDate = article->expiryDate;
		pointer0->article.valueAddedTax = article->valueAddedTax;
		pointer0->article.price = article->price;
		pointer0->article.numberAvailableUnits = article->numberAvailableUnits--;
		pointer0->next = NULL;
	}

}

void displayCart(List* list, Article* table[]) {

	system("clear");

	if (!list->first) {
		printf("YOUR CART IS EMPTY\n\n");
		sleep(2);
		mainMenu(list, table);
	}
	
	else {
		Element* pointer = list->first;
		printf("TOTAL PRICE: %f€\n\n", totalPrice(list));
		while (pointer->next) {
			displayArticleData(pointer);
			pointer = pointer->next;
			if (!pointer->next) displayArticleData(pointer);
		}
		printf("BACK TO THE MAIN MENU     <A>\n");
		printf("DELETE LAST ARTICLE       <B>\n\n");
		char enter = '-';
		scanf("%c", &enter);

		if (enter == 'A' || enter == 'B') {
			switch (enter) {
				case 'A': mainMenu(list, table); break;
				case 'B': deleteLastArticle(list, table); break;
			}
		}
		else displayCart(list, table);
	}

}

void deleteLastArticle(List* list, Article* table[]) {

	system("clear");

	if (!list->first) {
		printf("YOUR CART IS EMPTY\n\n");
		sleep(2);
		mainMenu(list, table);
	}

	else if (list->first) {
		Element* pointer = list->first;
		if (pointer->next) {
			while (pointer->next) {
				pointer = pointer->next;
			}
			switch (pointer->article.number) {
				case 0: table[0]->numberAvailableUnits++; break;
				case 1: table[1]->numberAvailableUnits++; break;
				case 2: table[2]->numberAvailableUnits++; break;
				case 3: table[3]->numberAvailableUnits++; break;
				case 4: table[4]->numberAvailableUnits++; break;
				case 5: table[5]->numberAvailableUnits++; break;
				case 6: table[6]->numberAvailableUnits++; break;
				case 7: table[7]->numberAvailableUnits++; break;
				case 8: table[8]->numberAvailableUnits++; break;
				case 9: table[9]->numberAvailableUnits++; break;
			}
			free(pointer);
			pointer = NULL;
			printf("ARTICLE DELETED\n\n");
			sleep(2);
			displayCart(list, table);
		}
		else {
			free(pointer);
			pointer = NULL;
			printf("ARTICLE DELETED\n\n");
			sleep(2);
			displayCart(list, table);
		}
	}

}

void displayArticleData(Element* pointer) {

	printf("%s   ", pointer->article.commercialName);
	printf("%s   ", pointer->article.commonName);
	printf("%s   ", pointer->article.category);
	printf("%s   ", pointer->article.brand);
	printf("%s   ", pointer->article.color);
	printf("%s\n", pointer->article.material);
	printf("EXPIRY DATE: %d/%d/%d   ", pointer->article.expiryDate.day, pointer->article.expiryDate.month, pointer->article.expiryDate.year);
	printf("VALUE ADDED TAX: %f%%   ", pointer->article.valueAddedTax);
	printf("PRICE: %f€   \n\n", pointer->article.price);

}

void addArticleMenu(List* list, Article* table[]) {

	system("clear");

	char enter = '-';
	printf("0) %s\n1) %s\n2) %s\n3) %s\n4) %s\n5) %s\n6) %s\n7) %s\n8) %s\n9) %s\n\n", table[0]->commercialName, table[1]->commercialName, table[2]->commercialName, table[3]->commercialName, table[4]->commercialName, table[5]->commercialName, table[6]->commercialName, table[7]->commercialName, table[8]->commercialName, table[9]->commercialName);
	printf("SELECT AN ARTICLE         <?>\n");
	printf("BACK TO THE MAIN MENU     <A>\n\n");
	scanf("%c", &enter);
	printf("\n");

	if (enter == 'A' || enter == '0' || enter == '1' || enter == '2' || enter == '3' || enter == '4' || enter == '5' || enter == '6' || enter == '7' || enter == '8' || enter == '9') {
		switch (enter) {
		case 'A': mainMenu(list, table); break;
		case '0': if (table[0]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 0)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[0]->numberAvailableUnits); sleep(2); addArticleMenu(list, table); } break;
		case '1': if (table[1]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 1)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[1]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '2': if (table[2]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 2)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[2]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '3': if (table[3]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 3)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[3]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '4': if (table[4]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 4)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[4]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '5': if (table[5]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 5)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[5]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '6': if (table[6]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 6)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[6]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '7': if (table[7]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 7)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[7]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '8': if (table[8]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 8)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[8]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		case '9': if (table[9]->numberAvailableUnits <= 0) { printf("ARTICLE UNAVAILABLE\n\n"); sleep(2); addArticleMenu(list, table); } else { addArticleCart(list, *(table + 9)); printf("ARTICLE ADDED IN YOUR CART\n"); printf("UNIT(S) REMAINING: %d\n\n", table[9]->numberAvailableUnits); sleep(2); addArticleMenu(list, table);	} break;
		}
	}
	else addArticleMenu(list, table);

}

double totalPrice(List* list) {

	if (list == NULL) exit(-1);
	double price = 0;
	Element* pointer = list->first;

	while (pointer != NULL) {
		price += ((pointer->article.valueAddedTax / 100) * pointer->article.price) + pointer->article.price;
		pointer = pointer->next;
	}

	return price;

}

void displayBill(List* list, Article* table[])
{
	system("clear");
	if (totalPrice(list) == 0) {
		printf("YOUR CART IS EMPTY\n\n");
		sleep(2);
		mainMenu(list, table);
	}
	else {
		printf("THE TOTAL PRICE IS %f€", totalPrice(list));
		if (500 < totalPrice(list)) {
			printf(" AND IS OVER 500€\nYOU CAN NOT PROCEED TO PAYMENT\n\n");
			sleep(10);
			mainMenu(list, table);
		}
		else {
			printf("\n\n");
			printf("CONTINUE AND PAY             <A>\n");
			printf("RETURN TO YOUR PURCHASES     <B>\n\n");
			char enter = '-';
			scanf("%c", &enter);

			if (enter == 'A' || enter == 'B') {
				switch (enter) {
				case 'A':
					files();
					system("clear");
					srand(time(NULL));
					printf("BILL NUMBER: %d\n\n", rand());
					sleep(5);
					goodBye(list);
					break;
				case 'B':
					mainMenu(list, table);
					break;
				}
			}
			else displayBill(list, table);
		}
	}

}

void fTime() {

	srand(time(NULL));
	int hour, minute, second, day, month, year;
	time_t now;
	time(&now);
	printf("TODAY: %s", ctime(&now));

	struct tm* local = localtime(&now);
	hour = local->tm_hour;
	minute = local->tm_min;
	second = local->tm_sec;
	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;

	printf("THE HOUR: %02d:%02d:%02d\n", hour, minute, second);
	printf("THE DATE: %02d/%02d/%d\n", day, month, year);

}

void files() {

	FILE* file = NULL;
	file = fopen("bill.txt", "w");

	if (file == NULL) exit(-1);

	fprintf(file, "BILL\nNUMBER: %d\n", rand());

	int hour, minute, second, day, month, year;
	time_t now;
	time(&now);

	struct tm* local = localtime(&now);
	hour = local->tm_hour;
	minute = local->tm_min;
	second = local->tm_sec;
	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;

	fprintf(file, "MADE THE: %02d/%02d/%d\nAT: %02d:%02d:%02d\n\n", day, month, year, hour, minute, second);
	fclose(file);

}

void seller(List* list, Article* table[]) {

	system("clear");
	char name[100] = "ONLINE SHOP";
	char email[100] = "ONLINESHOP@GMAIL.COM";
	char phoneNumber[15] = "01 23 45 67 89";
	char rcs[100] = "RCS-PARIS-A-012345678-01234";
	printf("BRAND: %s\nEMAIL: %s\nPHONE NUMBER: %s\nRCS: %s\n\n", name, email, phoneNumber, rcs);
	printf("BACK     <A>\n\n");
	char enter = '-';
	scanf("%c", &enter);
	if (enter == 'A') mainMenu(list, table);
	else seller(list, table);

}

void goodBye(List* list) {

	system("clear");
	printf("THANK YOU HAVE A NICE DAY!\n\n");
	sleep(2);
	system("clear");
	free(list);
	exit(1);

}

int main() {

	Article* ptr0 = &article0;
	Article* ptr1 = &article1;
	Article* ptr2 = &article2;
	Article* ptr3 = &article3;
	Article* ptr4 = &article4;
	Article* ptr5 = &article5;
	Article* ptr6 = &article6;
	Article* ptr7 = &article7;
	Article* ptr8 = &article8;
	Article* ptr9 = &article9;
	Article* table[10] = { ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7, ptr8, ptr9 };

	List* list = malloc(sizeof(List));
	if (list == NULL) exit(-1);
	list->first = NULL;

	mainMenu(list, table);

	return 1;

}