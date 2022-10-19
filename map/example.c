#include "map.h"
#include <stdio.h>
#include <string.h>

struct map_key_t {
    char name[128];
};

struct map_val_t {
    int age;
    int weight;
    int height;
};

void for_each(const void *key, const void *val)
{
    struct map_key_t *key_ptr = (struct map_key_t *)key;
    struct map_val_t *val_ptr = (struct map_val_t *)val;

    printf("[name: %s] -> [age: %d, height: %d, weight: %d]\n", key_ptr->name, val_ptr->age, val_ptr->height, val_ptr->weight);
}

int main()
{
    struct map m = map_init(sizeof(struct map_key_t), sizeof(struct map_val_t));
    struct map_key_t key;
    struct map_val_t val;

    strcpy(key.name, "Nelson Cheung");
    val.age = 22;
    val.weight = 180;
    val.height = 180;
    map_put(&m, &key, &val);

    strcpy(key.name, "Junyu Zhang");
    val.age = 18;
    val.weight = 220;
    val.height = 175;
    map_put(&m, &key, &val);

    strcpy(key.name, "Kwanyu Cheung");
    val.age = 20;
    val.weight = 200;
    val.height = 178;
    map_put(&m, &key, &val);

    strcpy(key.name, "Nelson Cheung");
    struct map_val_t *val_ptr = map_get(&m, &key);
    if (!val_ptr) {
        printf("retrieve error\n");
        return 0;
    }
    printf("[name: %s] -> [age: %d, height: %d, weight: %d]\n", key.name, val_ptr->age, val_ptr->height, val_ptr->weight);

    map_put(&m, &key, &val);
    val_ptr->age = 16;

    printf("traverse map\n");
    map_for_each(&m, for_each);

    map_clear(&m);
}