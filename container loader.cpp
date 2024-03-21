#include <stdio.h>
#include <stdbool.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100  
struct Item {
    int width;
    int height;
    int depth;
}; 
struct Container {
    int width;
    int height;
    int depth;
    int remainingWidth;
    int remainingHeight;
    int remainingDepth;
}; 
bool doesFit(struct Item item, struct Container container) {
    return (item.width <= container.remainingWidth && 
            item.height <= container.remainingHeight && 
            item.depth <= container.remainingDepth);
} 
void loadItems(struct Item items[], int numItems, struct Container containers[], int numContainers) {
     
    for (int i = 0; i < numContainers; i++) {
        containers[i].remainingWidth = containers[i].width;
        containers[i].remainingHeight = containers[i].height;
        containers[i].remainingDepth = containers[i].depth;
    } 
    for (int i = 0; i < numItems; i++) {
        bool loaded = false;
        for (int j = 0; j < numContainers; j++) {
            if (doesFit(items[i], containers[j])) {
                printf("Item %d fits into Container %d\n", i+1, j+1);
                containers[j].remainingWidth -= items[i].width;
                containers[j].remainingHeight -= items[i].height;
                containers[j].remainingDepth -= items[i].depth;
                loaded = true;
                break;
            }
        }
        if (!loaded) {
            printf("Item %d could not be loaded into any container\n", i+1);
        }
    }
}

int main() {
 
    struct Item items[MAX_ITEMS] = {{2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    struct Container containers[MAX_CONTAINERS] = {{5, 5, 5}, {6, 6, 6}};

    int numItems = 3;
    int numContainers = 2;

    loadItems(items, numItems, containers, numContainers);

    return 0;
}
