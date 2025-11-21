#include <stdio.h>
#include <string.h>

#define MAX_CITY 50
#define MAX_DATE 20

struct Flight
{
    int flightNumber;
    char departureCity[MAX_CITY];
    char destinationCity[MAX_CITY];
    char date[MAX_DATE];
    int availableSeats;
};

void displayFlight(struct Flight f)
{
    printf("Flight Number: %d\n", f.flightNumber);
    printf("Departure City: %s\n", f.departureCity);
    printf("Destination City: %s\n", f.destinationCity);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.availableSeats);
}

int bookSeat(struct Flight *f)
{
    if (f->availableSeats > 0)
    {
        f->availableSeats--;
        printf("Seat booked successfully!\n");
        return 1;
    }
    else
    {
        printf("No seats available!\n");
        return 0;
    }
}

int main()
{
    struct Flight flight;
    flight.flightNumber = 1234;
    strcpy(flight.departureCity, "Karachi");
    strcpy(flight.destinationCity, "Lahore");
    strcpy(flight.date, "2025-11-21");
    flight.availableSeats = 5;

    printf("--- Flight Details ---\n");
    displayFlight(flight);

    printf("\nBooking a seat...\n");
    bookSeat(&flight);

    printf("\n--- Updated Flight Details ---\n");
    displayFlight(flight);

    return 0;
}
