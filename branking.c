#include <stdio.h>

void checkbalance(float balance);
float deposit();
float withdraw(float current_balance);  

int main() {
    int choice = 0;
    float balance = 0.0f;
    
    printf("Welcome to the Bank!\n");
    
    do {
        printf("\n=== BANK MENU ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                checkbalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance = withdraw(balance);  
                break;
            case 4:
                printf("\nThank you for using our bank. See you soon!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose 1-4.\n");
            
                while(getchar() != '\n');
                break;
        }
        
    } while(choice != 4);
    
    return 0;
}

void checkbalance(float balance) {
    printf("\nYour current balance is: $%.2f\n", balance);  
}

float deposit() {
    float amount = 0.0f;
    
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    
    if(amount <= 0) {  
        printf("Invalid amount! Must be positive.\n");
        return 0.0f;
    } else {
        printf("Successfully deposited $%.2f\n", amount);
        return amount;
    }
}

float withdraw(float current_balance) {  
    float amount = 0.0f;
    
    printf("Your current balance: $%.2f\n", current_balance);
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);  
    
    if(amount <= 0) {
        printf("Invalid amount! Must be positive.\n");
        return current_balance;  
    } else if(amount > current_balance) {
        printf("Insufficient funds!\n");
        return current_balance;  
    } else {
        printf("you haave Successfully withdrew $%.2f\n", amount);
        return current_balance - amount;  
    }
}