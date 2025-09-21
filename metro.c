#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 27
#define MAX_1 18
#define FARE_1 10
#define FARE_2 20
#define FARE_3 30
#define FARE_4 40
#define FARE_5 50

struct node {
    int num;
    char data[50];
    struct node *next;
};
struct node *head=NULL;
struct node *blue_head = NULL;
struct node *green_head = NULL;

struct node *creation(struct node *, char [], int);
void traverse(struct node *);
int searching(struct node *,int ,int);
int price_calculation(int);
int printing(struct node *,int,int,int);
int printing_from_pt(struct node *,int);
int printing_arrival_pt(struct node *,int);

char blue_line[MAX][100] = {
    "BLUE LINE",
    "Airport", "Meenambakkam", "NanganallurRoad",
    "Alandur", "Guindy", "Little_Mount", "Saidapet",
    "Nandanam", "Teynampet", "AG_DMS", "Thousand_Lights", "LIC",
    "Government_Estate", "M.G.Ramachandran_Central",
    "High_Court", "Mannadi", "Washermanpet", "Sir_Theagaraya_College",
    "Tondiarpet", "New_Washermanpet", "Tollgate", "Kaladipet",
    "Tiruvottriyur_Theradi", "Tiruvottriyur", "Wimco_Nagar",
    "Wimco_Nagar_Depot"
};
char green_line[MAX_1][100] = {
    "GREEN LINE",
    "St.Thomas_Mount","Alandur",
    "Ekkattuthangal","Ashok_Nagar","Vadapalani","Arumbakkam",
    "CMBT","Koyambedu",
    "Thirumangalam","Anna_Nagar_Tower","Anna_Nagar_East",
    "Shenoy_Nagar","Pachaiyappa_College","Kilpauk_Medical_College",
    "Nehru_Park","Egmore","M.G.Ramachandran_Central"
};

int main() {
    int i, option,from_pt,arrival_pt,count,prices,blue_count,green_count,total_station,blue_line_stop,green_line_stop,fare;
    printf("\n1. Passing in Blue Line\n2. Passing in Green Line\n3. Passing from Blue Line to Green line\n4.Passing From Green Line to Blue Line\n ");
    scanf("%d", &option);
    switch(option) {
        case 1:
            for (i = 0; i < MAX; i++) {
                blue_head = creation(blue_head, blue_line[i], i); // Pass blue_head to creation
            }
            traverse(blue_head);
            printf("\nEnter the starting point station number (1-26): ");
        	scanf("%d",&from_pt);
        	printf("\nEnter the desination station number(1-26):");
        	scanf("%d",&arrival_pt);
        	count=searching(blue_head,from_pt,arrival_pt);
        	prices=price_calculation(count);
        	printing(blue_head,from_pt,arrival_pt,prices);
            break;
        case 2:
            for (i = 0; i < MAX_1; i++) {
                green_head = creation(green_head, green_line[i], i); // Pass green_head to creation
            }
            traverse(green_head);
            printf("\nEnter the starting point station number (1-17): ");
        	scanf("%d",&from_pt);
        	printf("\nEnter the desination station number(1-17):");
        	scanf("%d",&arrival_pt);
        	count=searching(green_head,from_pt,arrival_pt);
        	prices=price_calculation(count);
        	printing(green_head,from_pt,arrival_pt,prices);
            break;
        case 3:
        	blue_line_stop=4;
			green_line_stop=2;
            for (i = 0; i < MAX; i++) {
                blue_head = creation(blue_head, blue_line[i], i); // Pass blue_head to creation
            }
            traverse(blue_head);
            printf("\nEnter the starting point station number (1-26): ");
        	scanf("%d",&from_pt);

            for (i = 0; i < MAX_1; i++) {
                green_head = creation(green_head, green_line[i], i); // Pass green_head to creation
            }
            traverse(green_head);
            printf("\nEnter the desination station number(1-17):");
        	scanf("%d",&arrival_pt);
        	blue_count=searching(blue_head,from_pt,blue_line_stop);
            //function to count from Alandur to desination point
            green_count=searching(green_head,arrival_pt,green_line_stop);
            total_station=blue_count+green_count;
            prices=price_calculation(total_station);
			printf("\n---------------------------------------------------------------\n");
    		printf("TICKET :\n");
            printing_from_pt(blue_head,from_pt);
            printing_arrival_pt(green_head,arrival_pt);
            printf("\nFARE :%d",prices);
            printf("\n\n");
    		printf("\t\t::.::....:::.:.::...::....\n");
			printf("\t\t  ..::.::.::.::.::.."""". ::\n");
			printf("\t\t::..:::::..:::...::.""""::..\n");
			printf("\t\t::.::....:::. :::.........\n");
			printf("\t\t ..:: """"::.::.::...:: ::\n");
			printf("\t\t::.::."""":::.: ::...:::..\n");
			printf("\t\t::.:: .: :.::..::.........\n");
			printf("\t\t::.::..  ..:::.::....:....\n");
			printf("\t\t ..::.::.::.::.::.  .::.::\n");
			printf("\t\t ..::.::.::.::.::...:.. ::\n");
			printf("\t\t::.::....:::. :::.""""....\n");
			printf("\t\t::.::.::.:::..::.."""".::. .\n");
			printf("\n\n");
			printf("PLEASE RETAIN THE BILL TILL YOUR JOURNEY\n");
            printf("\n---------------------------------------------------------------\n");
			break;


        case 4:
        	blue_line_stop=4;
			green_line_stop=2;
        	for (i = 0; i < MAX_1; i++) {
                green_head = creation(green_head, green_line[i], i); // Pass green_head to creation
            }
            traverse(green_head);
            printf("\nEnter the starting point station number (1-17): ");
        	scanf("%d",&from_pt);
        	for (i = 0; i < MAX; i++) {
                blue_head = creation(blue_head, blue_line[i], i); // Pass blue_head to creation
            }
            traverse(blue_head);
            printf("\nEnter the desination station number(1-26):");
        	scanf("%d",&arrival_pt);
        	green_count=searching(green_head,from_pt,green_line_stop);
        	blue_count=searching(blue_head,arrival_pt,blue_line_stop);
        	total_station=blue_count+green_count;
            prices=price_calculation(total_station);
            printf("\n---------------------------------------------------------------\n");
            printf("\t\tCHENNAI METRO COPORATION\n");
    		printf("TICKET :\n");
            printing_from_pt(green_head,from_pt);
            printing_arrival_pt(blue_head,arrival_pt);
            printf("\nFARE :%d",prices);
            printf("\n\n");
    		printf("\t\t::.""""....:::.:.::...::....\n");
			printf("\t\t  ."""":.::.::.::.::..... ::\n");
			printf("\t\t::..:::::..:::...::...::..\n");
			printf("\t\t::.::....:::. :::.......""""\n");
			printf("\t\t ..::.::.::.::.::....:: """"\n");
			printf("\t\t::.::.::.:::.: ::...:::...\n");
			printf("\t\t::.::...::"""":..::.........\n");
			printf("\t\t::.::..  .""""::.::....:....\n");
			printf("\t\t ..::.::.::.::.::.  .::.::\n");
			printf("\t\t ..::.::.::.::.::...:.. ::\n");
			printf("\t\t"""".::....:::. :::.........\n");
			printf("\t\t"""".::.::.:::..::..::.::. .\n");
			printf("\n\n");
			printf("PLEASE RETAIN THE BILL TILL YOUR JOURNEY\n");
            printf("\n---------------------------------------------------------------\n");
            break;




        default:
            printf("Invalid option\n");
    }
    return 0;
}

struct node *creation(struct node *head, char line[], int st_num) {		//creation of node
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->num = st_num;
    strcpy(ptr->data, line);
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    return head;
}

void traverse(struct node *head) {				//Traversal of Node
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d  %s \n", temp->num, temp->data);
        temp = temp->next;
    }
}

int searching(struct node *head,int start, int stop) {
    struct node *temp = head;
    int count = 1;

    // Find the start and stop nodes
    struct node *start_node = NULL;
    struct node *stop_node = NULL;
    while (temp != NULL)
    {
        if (temp->num == start)
            start_node = temp;
        if (temp->num == stop)
            stop_node = temp;
        temp = temp->next;
    }

    // Count the stations between start and stop
    if (start_node != NULL && stop_node != NULL)
    {
        if (start_node->num < stop_node->num)
        {
            temp = start_node->next;
            while (temp != stop_node)
            {
                count++;
                temp = temp->next;
            }
        }
    else
        {
            temp = stop_node->next;
            while (temp != start_node)
            {
                count++;
                temp = temp->next;
            }
        }
    }

    // Print the number of stations
    return count;
}

 int price_calculation(int count) {
    int fare,passengers;
    printf("\nHow many number of passengers are going to travel : ");
    scanf("%d",&passengers);
    if (count == 1) {
        fare = FARE_1*passengers;
    } else if (count <= 3) {
        fare = FARE_2*passengers;
    } else if (count <= 10) {
        fare = FARE_3*passengers;
    } else if (count <= 18) {
        fare = FARE_4*passengers;
    } else {
        fare = FARE_5*passengers;
    }
	printf("%d",fare);
return fare;
}

int printing(struct node *head, int from_pt, int arrival_pt, int fare) {
    char from_1[100], to_point[100]; // Assuming station names can be up to 100 characters long
    struct node *temp = head;

    printf("\n---------------------------------------------------------------\n");
    printf("TICKET :\n");
    // Find the station names corresponding to from_pt and arrival_pt
    while (temp != NULL) {
        if (temp->num == from_pt) {
            strcpy(from_1, temp->data);
        }
        if (temp->num == arrival_pt) {
            strcpy(to_point, temp->data);
        }
        temp = temp->next;
    }

    printf("From point : %s\nTo point : %s\nTotal amount : %d\n", from_1, to_point, fare);
    printf("\n\n");
    printf("\t\t::.::....:::.:.::...::....\n");
	printf("\t\t  ..::.::  :.::.::..... ::\n");
	printf("\t\t::..:: ::  :...::.."""".\n");
	printf("\t\t::.::....:::. :::... """".\n");
	printf("\t\t ..::.::.::.::.::....:: ::\n");
	printf("\t\t::.::.::.:::.: ::...:::...\n");
	printf("\t\t::.::...::.::..::.........\n");
	printf("\t\t""""::.  ..:::.::....:....\n");
	printf("\t\t"""":.::.::.::.::.  .::.::\n");
	printf("\t\t ..::.::.  .::.::...:.. ::\n");
	printf("\t\t:"""":...:::. :::.........::\n");
	printf("\t\t:"""":::.:::..::..::.::. .::\n");
	printf("\n\n");
	printf("PLEASE RETAIN THE BILL TILL YOUR JOURNEY\n");
	printf("\n---------------------------------------------------------------\n");

}

int printing_from_pt(struct node *head ,int from_pt)
{
	struct node *temp=head;
	char from_name[100];
	while (temp != NULL) {
        if (temp->num == from_pt) {
            strcpy(from_name, temp->data);
        }
        temp = temp->next;
    }
    printf("\nFrom point :%s",from_name);

}

int printing_arrival_pt(struct node *head,int arrival_pt)
{
	char to_name[100];
	struct node *temp=head;
	while (temp != NULL) {
        if (temp->num == arrival_pt) {
            strcpy(to_name, temp->data);
        }
        temp = temp->next;
    }

    printf("\nTo point : %s",to_name);
}

