#include <stdio.h>

int main() {
	double bal;
	int dmc;
	int dmon;
	int wmon;
	bal = 1000.0;
	int c;
	int qc;
	
	printf("=== ATM MENU ===\n");
	printf("Current Balance: %.2f\n", bal);
	printf("1. Check Balance\n");
	printf("2. Withdraw Money\n");
	printf("3. Deposit Money\n");
	printf("4. Quick Cash\n");
	printf("5. Exit\n");
	
	printf("Enter Your Choice: ");
	scanf("%d", &c);
	
	switch (c) {
		case 1: {
			printf("Balance is: %.2f\n", bal);
			break;
		} case 2: {
			printf("Enter Withdrawal amount: ");
			scanf("%d", &wmon);
			dmc = wmon % 10;
			if (bal >= wmon && dmc == 0) {
				if (wmon > 100) {
					printf("Transaction Successful\n");
					bal = bal - wmon - 2.00;
					printf("Transaction fee: $2.00\n");
					printf("Withdrawal Amount: %d\n", wmon);
					printf("New Balance: %.2f\n", bal);
				} else {
					printf("Transaction Successful\n");
					bal = bal - wmon;
					printf("Withdrawal Amount: %d\n", wmon);
					printf("New Balance: %.2f\n", bal);
				}
			} else {
				printf("Transaction failed\n");
			}
			break;
		} case 3: {
			printf("Enter Deposit Amount: ");
			scanf("%d", &dmon);
			if (dmon < 5000) {
				bal = bal + dmon;
				printf("New Balance: %.2f\n", bal);
			} else {
				printf("Transaction failed\n");
			}
			break;
		} case 4: {
			printf("Enter QUICK Cash amount ($20, $50, $100, $200): ");
			scanf("%d", &qc);
			switch (qc) {
				case 20: {
					printf("Transaction Successful\n");
					bal = bal - 20;
					printf("New Balance: %.2f\n", bal);
					break;
				} case 50: {
					printf("Transaction Successful\n");
					bal = bal - 50;
					printf("New Balance: %.2f\n", bal);
					break;
				} case 100: {
					printf("Transaction Successful\n");
					bal = bal - 100;
					printf("New Balance: %.2f\n", bal);
					break;
				} case 200: {
					printf("Transaction Successful\n");
					bal = bal - 200;
					printf("New Balance: %.2f\n", bal);
					break;
				} default: {
					printf("Invalid Quick Cash amount\n");
					break;
				}
			}
			break;
		} case 5: {
			printf("EXITING\n");
			break;
		} default: {
			printf("Invalid Input\n");
			break;
		}
	}
}

