#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char surname[20];
    char phone[12];
} Contact;

//metoda zwaracajaca index ostatniego "niepustego" elemntu w tablicy
int lastElementIndex(Contact * arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        if(*arr[i].name == 0) {
            return i;
        }
    }
    return 0;
}

//metoda dodajaca nowy kontakt do tablicy
void addNewContact(char * name, char * surname, char * phone,
                   Contact * arr, int size) {
    int lastIndex = lastElementIndex(arr, size);
    Contact c = {.name = *name, .surname = *surname, .phone = *phone};

    arr[lastIndex] = c;
}

//metoda wyszukujaca podane przez uzytkownika nazwisko w tablicy kontaktow
void searchFor(char * surname, Contact * arr, int size) {
    int i;
    int lastIndex = lastElementIndex(arr, size);

    for(i = 0; i < lastIndex; i++) {
        //w warunku zostaje uzyta funkcja strcmp, ktora porownuje ze soba dwa lancuchy znakow i zwraca zaleznosc miedzy nimi
        //jezeli zostaje znaleziony to metoda wypisuje pelne dane, w przeciwnym wypadku wypisuje odpowiedni komunikat
        if(strcmp(arr[i].surname, surname) == 0) {
            printf("%s %s %s\n", arr[i].name, arr[i].surname, arr[i].phone);
            break;
        }
        else {
            printf("Could not find the entered surname!\n");
            break;
        }
    }
}

//metoda usuwajaca kontakt z tablicy
void delete(char * surname, Contact * arr, int size) {
    int i;
    int lastIndex = lastElementIndex(arr, size);

    for(i = 0; i < lastIndex; i++) {
        if(strcmp(arr[i].surname, surname) == 0) { //ponowanie funkcja strcmp()
            Contact c = {};
            arr[i] = c;
            break;
        }
        else {
            printf("Could not find the entered surname!\n");
            break;
        }
    }
}

//metoda wypisujaca wszystkie kontakty z tablicy
void printContact(Contact * arr, int size) {
    int i;
    int lastIndex = lastElementIndex(arr, size);

    printf("%s\n%s\n",
    "      Contacts", "####################");

    for(i = 0; i < lastIndex; i++) {
        printf("%s %s %s\n", arr[i].name, arr[i].surname, arr[i].phone);
    }
}

int main() {
    //inicjalizacja tablicy kontatkow
    Contact contactArray[255] = {
            {"Alice", "XYZ", "123456789"},
            {"Bob", "ABC", "987654321"},
            {"Charlie", "ZYX", "123454321"},
            {"Tom", "CBA", "987656789"},
            {"Arthur", "QWE", "555444333"}
    };
    int i = -1;

    int size = sizeof(contactArray) / sizeof(contactArray[0]); //zmienna zainicjalizowana rozmiarem tablicy

    //petla while
    while(i != 0) {
        //"interface" uzytkownika
        printf(" ###### Contact ######\n");
        printf(" ### Rules: \n"
               " ### Press 1 to add new contact \n"
               " ### Press 2 to search for contact \n"
               " ### Press 3 to delete a contact \n"
               " ### Press 4 to view all contacts \n"
               " ### Press 0 to exit \n"
        );
        //wybor opcji przez uzytkownika
        scanf_s("%d", &i);
        //switch case reazliujacy opcje wymienione w interface
        switch(i) {
            case 1: {
                printf("Enter new name:");
                char name[20];
                scanf("%s", name);
                printf("Enter new surname:");
                char surname[20];
                scanf("%s", surname);
                printf("Enter new phone number:");
                char phone[20];
                scanf("%s", phone);
                addNewContact(name, surname, phone, contactArray, size);
            } break;

            case 2: {
                printf("Enter a surname:");
                char surname[20];
                scanf("%s", surname);
                searchFor(surname, contactArray, size);
            } break;
            case 3: {
                printf("Enter a surname:");
                char surname[20];
                scanf("%s", surname);
                delete(surname, contactArray, size);
            } break;
                case 4:
                printContact(contactArray, size);
                break;
            case 0:
                i = 0;
                break;
            default:
                printf("You've chosen the wrong option");
                break;
        }
        //dodatkowy komunikat dla zwiekszenia czytelnosci odpowiednich komunikatow
        printf("Press any key to continue\n");
        getchar();
        getchar();
    }
    
}
