#include <stdio.h>

struct Hotel {
    int totalRooms;
    int bookedRooms;
};

int checkAvailableRooms(struct Hotel h) {
    return (h.totalRooms - h.bookedRooms); 
}

int main() {
    struct Hotel h;
    h.totalRooms = 20; 
    h.bookedRooms = 15;
    printf("%d rooms available.\n", checkAvailableRooms(h));
    return 0;
}