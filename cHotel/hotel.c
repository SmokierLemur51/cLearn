#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Room {
    char type[]; // single, double, family, luxury single, lux
    bool luxury;
    bool smoking;
    bool clean;
    int beds;
    float price;
};

struct Hotel {
    int floors;
    int totalRooms;
    struct Rooms rooms[5][25]; // 5 floors with 25 rooms per 
};

struct Room createRoom(const char *name, bool luxury, bool smoking, bool clean, int beds, float price) {
    struct Room r;
    strcpy(r.type, name); 
    r.luxury = luxury; r.smoking = smoking, r.clean = clean;
    r.beds = beds; r.price = price;
    return r;
};

struct Hotel createHotel(int floors, int roomsFloor) {
    struct Hotel h;
    h.floors = floors;
    h.totalRooms = (floors * roomsFloor); // this is too perfect, rooms per floor should vary
    for (f = 0; f <= floors; f++) {
        if (f == floors) {
            // presidential suite at top floor
            struct Room presidential;
            strcpy(presidential.type, "Presidential");
            presidential.luxury = true; presidential.smoking = true; // you do whatever you want up here
            h.rooms[f][0] = p;    
        } else {
            for (r = 0; r <= roomsFloor; r++) {
                switch r {
                    case 1:
                        h.rooms[f][r] = createRoom("Single (Smoking Permitted)", false, true, true, 1, 100.00);
                        break;
                    case 2:
                        h.rooms[f][r] = createRoom("Double (Smoking Permitted)", false, true, true, 2, 195.00);
                        break;
                    case 3:
                        h.rooms[f][r] = createRoom("Family (Smoking Permitted)", false, true, true, 4, 275.00); 
                        break;
                    case <10:
                        h.rooms[f][r] = createRoom("Single", false, false, true, 1, 89.00);
                        break;
                    case <18:
                        h.rooms[f][r] = createRoom("Double", false, false, true, 2, 164.00);
                        break;
                    case (roomsFloor - 1):
                        h.rooms[f][r] = createRoom("Family", false, false, true, 4, 250.00);
                        break;
                    case roomsFloor:
                        h.rooms[f][r] = createRoom("Luxury", false, false, true, 1, 148.00);
                        break;
                }
            }
        }
    }
    return h;
}

/**
    * @brief This function creates your hotel based off of your input
    *
    * @param floors easy, its the number of floors
    * @param rpf rooms per floor
    * @param  
*/
struct Hotel generateHotelWithArgs(int floors, int rpf) {
    struct Hotel h;
    for (int f = 0; f <= floors; f++) {
        int l = f; // l is for level
        for (int r = 0; r <= rpf; r++) {
            int i;
            printf("How many smoking rooms on floor # %d", l);
            
        }
    }

    return h;
}

int checkAvailableRooms(struct Hotel *h) {
    return 0;
}


int main() {
    struct Hotel h = createHotel(5, 25);
    // printf("%d rooms available.\n", checkAvailableRooms(&h));
    return 0;
}