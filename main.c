#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct languages_t{
    char name[30];
    char number[30];
};

int show_menu(){
    int read;
    int selection;
    printf("1 - Dateien einlessen\n2 - Tabelle anzeigen\n3 - Sortieren absteigen"
           "\n4 - Sortieren aufsteigend\n5 - Sortieren nach Name\n6 - Programm verlassen\n");
    read = scanf("%d",&selection);
    while (getchar() != '\n');
    return selection;
}

int read_file(struct languages_t languages[]){
    int counter = 0;
    FILE * sourceFile = NULL;
    sourceFile = fopen("artikel.txt", "r");
    if(sourceFile == NULL){
        printf("No file");
    } else{
        printf("File is ready\n");
    }
    do{
        fscanf(sourceFile,"%[^\t]\t%[^\n]\n",languages[counter].name,languages[counter].number);
        counter += 1;
    } while (!feof(sourceFile));
    fclose(sourceFile);
    return counter;
}

void show_table(struct languages_t languages[], int counter){

    for(int i = 0; i < counter;i++){
        printf("%s\t%s\n",languages[i].name,languages[i].number);
    }
    printf("\n");
}

void bubbleSort(struct languages_t languages[], int counter,int sort_type)
{
    struct languages_t tmp;
    double number;
    double number1;

    if(sort_type == 0){

        for(int i = 0; i < counter;i++){
            for(int j = 0;j<counter -1;j++){

                number = atof(languages[j].number);
                number1 = atof(languages[j + 1].number);

                if(number > number1){
                    tmp = languages[j];
                    languages[j] = languages[j + 1];
                    languages[j + 1] = tmp;
                }
            }
        }
    }
    else{
        for(int i = 0; i < counter;i++){
            for(int j = 0;j<counter -1;j++){

                number = atof(languages[j].number);
                number1 = atof(languages[j + 1].number);

                if(number < number1){
                    tmp = languages[j];
                    languages[j] = languages[j + 1];
                    languages[j + 1] = tmp;
                }
            }
        }
    }
}

void sort_by_name(struct languages_t languages[], int counter){

    struct languages_t tmp;
    for(int i = 0; i < counter;i++){
        for(int j = 0;j<counter -1;j++){

            if(strcmp(languages[j].name,languages[j + 1].name) > 0){
                tmp = languages[j];
                languages[j] = languages[j + 1];
                languages[j + 1] = tmp;
            }
        }
    }
}

int main() {

    int selection = 5;
    int counter = 0;
    struct languages_t languages[100];

    do{
        selection = show_menu();

        if(selection == 1){

            counter = read_file(languages);
        }
        else if(selection == 2){

            show_table(languages, counter);
        }
        else if(selection == 3){
            bubbleSort(languages,counter, 0);
        }
        else if(selection == 4){
            bubbleSort(languages,counter, 1);
        }
        else if(selection == 5){
            sort_by_name(languages, counter);
        }

    } while (selection != 6);

}
