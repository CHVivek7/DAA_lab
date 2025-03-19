#include <stdio.h>
#include <stdlib.h>


struct node {
    int number;
    int profit;
    int weight;
    double ratio;
    double optimal;
};
int remain;

void fknapsack(struct node *items, int n, int m);
void SortRatio(struct node *items, int n);

int main() {
    int n, m;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("\nEnter the max weight: ");
    scanf("%d", &m);

    struct node items[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter profit of item %d: ", i + 1);
        scanf("%d", &items[i].profit);

        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);

        items[i].number = i + 1;
        items[i].ratio = (double)items[i].profit / items[i].weight;
        items[i].optimal = 0; 
    }

    fknapsack(items, n, m); 

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { 
            if (items[j].number > items[j + 1].number) {
                struct node temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    printf("\nItems after Knapsack computation:\n");
    for (int i = 0; i < n; i++) {
	if(items[i].optimal>0 && items[i].optimal<1){
	    printf("Item %d: Profit = %d, Weight = %d, Ratio = %.2f, Optimal = %d / %d\n",items[i].number,items[i].profit,items[i].weight,items[i].ratio,remain,items[i].weight);
	}else{
        printf("Item %d: Profit = %d, Weight = %d, Ratio = %.2f, Optimal = %.2f\n",
               items[i].number, items[i].profit, items[i].weight, items[i].ratio, items[i].optimal);
    	}
    }
    return 0;
}


void fknapsack(struct node *items, int n, int m) {
    int curweight = 0;
    double total_profit = 0.0;

    
    SortRatio(items, n);

    for (int i = 0; i < n; i++) {
        if (curweight + items[i].weight <= m) {
            curweight += items[i].weight;
            total_profit += items[i].profit;
            items[i].optimal = 1.0;  
        } else {
            remain = m - curweight;
            total_profit += items[i].profit * ((double)remain / items[i].weight);
            items[i].optimal = (double)remain / items[i].weight; 
            break;
        }
    }

    printf("\nTotal profit: %.2f\n", total_profit);
}


void SortRatio(struct node *items, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {  
            if (items[j].ratio < items[j + 1].ratio) {
                struct node temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

