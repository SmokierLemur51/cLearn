#include <stdio.h>
#include <string.h>

struct Plant {
  int id;
  char name[50];
  char scientificName[50];
  int age;
  float health;
  float waterContent;
  float nutrients;
  float sicknessProbability;
};

struct SoilQuality {
  float ph;
  float moisture;
  float microbes;
  float organicMatter;
  float nitrogen;
  float phosphorus;
  float potassium;
};

struct Garden {
  // 3 rows, potatoes, carrots, tomatoes and 10 plants each
  struct Plant patch[3][10];
  struct SoilQuality sq;
  float soilHealth;
  float blightProbability;
};

// const
const int POTATO_ID = 1; // create loadDatabaseID()
const int CARROT_ID = 2;
const int TOMATO_ID = 3;

void waterPlant(struct Plant *p, float amountPoured) {
  p->waterContent += amountPoured;
  return;
}

void feedPlant(struct Plant *p, float feedAmount) {
  p->nutrients += feedAmount;
  return;
}

void calculatePlantHealth(struct Plant *p, struct Garden g) {
  // right now health is just the average of the three stats
  // more research is needed
  p->health = (p->waterContent + p->nutrients + g.soilQuality) / 3;
  return;
}

// this function should probably take the array instead
void calculateSicknessProbability(struct Plant *p) { return; }

void measureWaterLevel(struct Plant p) {
  printf("Water levels at %.02f %%.\n", p.waterContent);
  return;
}

void measureSoilQuality(struct Garden g) {
  printf("Soil quality is at %.02f %%.\n", g.soilQuality);
  return;
}

void measureHealth(struct Plant p) {
  printf("%s is at %.02f %% health.\n", p.name, p.health);
  return;
}

struct Plant createPlant(int id, int age, float water, float nutrients,
                         const char *name, const char *scientificName) {
  struct Plant p;
  p.id = id;
  strcpy(p.name, name);
  strcpy(p.scientificName, scientificName);
  p.age = age;
  p.waterContent = water;
  p.nutrients = nutrients;
  return p;
}

struct Garden createGarden(int rows, int cols, float soilQuality) {
  struct Garden g;
  g.soilQuality = soilQuality;
  for (int r = 0; r < rows; r++) {
    if (r == 0) {
      for (int c = 0; c < cols; c++) {
        // create potato struct for each spot in this row
        g.patch[r][c] = createPlant(POTATO_ID, 0, 0.00, 0.00, "Russet Potato",
                                    "Solanum tuberosum");
      }
    } else if (r == 1) {
      for (int c = 0; c < cols; c++) {
        // create carrot struct for each spot in this row
        g.patch[r][c] =
            createPlant(CARROT_ID, 0, 0.00, 0.00, "Carrot", "Daucus carota");
      }
    } else {
      for (int c = 0; c < cols; c++) {
        // create tomato struct for each spot in this row
        g.patch[r][c] = createPlant(TOMATO_ID, 0, 0.00, 0.00, "Roma Tomato",
                                    "Solanum lycopersicum");
      }
    }
  }
  return g;
}

void printGarden(struct Garden g, int rows, int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (g.patch[r][c].id == 1) {
        // potato
        printf("\t0\t");
      } else if (g.patch[r][c].id == 2) {
        // carrot
        printf("\t1\t");
      } else if (g.patch[r][c].id == 3) {
        // tomato
        printf("\to\t");
      } else {
        printf("\t \t");
      }
    }
    printf("\n\n");
  }
}

int main(void) {
  struct Garden g = createGarden(3, 10, 72.00);
  printGarden(g, 3, 10);
  return 0;
}