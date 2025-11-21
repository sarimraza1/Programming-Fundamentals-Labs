#include <stdio.h>
#include <string.h>

struct Movie {
    char title[100];
    char genre[50];
    char director[100];
    int releaseYear;
    float rating;
};

void addMovie(struct Movie movies[], int *count) {
    printf("Enter details for the new movie:\n");
    
    printf("Title: ");
    scanf(" %[^\n]s", movies[*count].title); // Read string with spaces
    
    printf("Genre: ");
    scanf(" %[^\n]s", movies[*count].genre);
    
    printf("Director: ");
    scanf(" %[^\n]s", movies[*count].director);
    
    printf("Release Year: ");
    scanf("%d", &movies[*count].releaseYear);
    
    printf("Rating (0.0 - 10.0): ");
    scanf("%f", &movies[*count].rating);
    
    (*count)++;
    printf("Movie added successfully!\n");
}

void searchByGenre(struct Movie movies[], int count, char genre[]) {
    int found = 0;
    printf("\nMovies in genre '%s':\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, genre) == 0) { // Case-insensitive comparison
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("-------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in this genre.\n");
    }
}

void displayAllMovies(struct Movie movies[], int count) {
    if (count == 0) {
        printf("\nNo movies to display.\n");
        return;
    }
    printf("\nAll Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("-------------------------\n");
    }
}

int main() {
    struct Movie movies[100];
    int count = 0;
    int choice;
    char searchGenre[50];

    while (1) {
        printf("\nMovie Information Management System\n");
        printf("1. Add New Movie\n");
        printf("2. Search by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                printf("Enter genre to search: ");
                scanf(" %[^\n]s", searchGenre);
                searchByGenre(movies, count, searchGenre);
                break;
            case 3:
                displayAllMovies(movies, count);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
